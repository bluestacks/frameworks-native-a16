#define LOG_TAG "BstFilterAppsManager"

#include <binder/BstFilterAppsManager.h>
#include <binder/Binder.h>
#include <binder/IServiceManager.h>

#include <cutils/multiuser.h>
#include <private/android_filesystem_config.h>

#include <utils/Log.h>
#include <utils/String8.h>
#include <utils/SystemClock.h>

#include <dlfcn.h>
#include <mutex>
#include <string>
#include <unistd.h>

#ifndef __ANDROID_VNDK__  // A16DBG:P2:D9 PermissionController not visible to vendor variant
#include <binder/PermissionController.h>
#endif

struct AIBinder;
struct AIBinder_Class;
struct AParcel;

namespace android {

namespace {

constexpr char kBstFilterAppsServiceName[] = "bstfilterapps";
constexpr char kBstFilterAppsDescriptor[] = "com.bluestacks.os.IBstFilterAppsService";
constexpr int32_t kStatusOk = 0;
constexpr int32_t kStatusUnknownTransaction = -32;

using BinderStatus = int32_t;
using TransactionCode = uint32_t;
using StringAllocator = bool (*)(void*, int32_t, char**);
using ClassOnCreate = void* (*)(void*);
using ClassOnDestroy = void (*)(void*);
using ClassOnTransact = BinderStatus (*)(AIBinder*, TransactionCode, const AParcel*, AParcel*);

void* unusedClassCreate(void*) {
    return nullptr;
}

void unusedClassDestroy(void*) {}

BinderStatus unusedClassTransact(AIBinder*, TransactionCode, const AParcel*, AParcel*) {
    return kStatusUnknownTransaction;
}

struct NdkBinderApi {
    void* handle = nullptr;
    AIBinder* (*checkService)(const char*) = nullptr;
    AIBinder_Class* (*defineClass)(const char*, ClassOnCreate, ClassOnDestroy, ClassOnTransact) =
            nullptr;
    bool (*associateClass)(AIBinder*, const AIBinder_Class*) = nullptr;
    BinderStatus (*prepareTransaction)(AIBinder*, AParcel**) = nullptr;
    BinderStatus (*transact)(AIBinder*, TransactionCode, AParcel**, AParcel**, uint32_t) = nullptr;
    BinderStatus (*writeString)(AParcel*, const char*, int32_t) = nullptr;
    BinderStatus (*readInt32)(const AParcel*, int32_t*) = nullptr;
    BinderStatus (*readString)(const AParcel*, void*, StringAllocator) = nullptr;
    void (*deleteParcel)(AParcel*) = nullptr;
    void (*incStrong)(AIBinder*) = nullptr;
    void (*decStrong)(AIBinder*) = nullptr;
    bool (*isAlive)(AIBinder*) = nullptr;
    AIBinder_Class* clazz = nullptr;

    bool complete() const {
        return handle != nullptr && checkService != nullptr && defineClass != nullptr &&
                associateClass != nullptr && prepareTransaction != nullptr && transact != nullptr &&
                writeString != nullptr && readInt32 != nullptr && readString != nullptr &&
                deleteParcel != nullptr && incStrong != nullptr && decStrong != nullptr &&
                isAlive != nullptr && clazz != nullptr;
    }
};

const NdkBinderApi& getNdkBinderApi() {
    [[clang::no_destroy]] static const NdkBinderApi api = []() {
        NdkBinderApi loaded;
        loaded.handle = dlopen("libbinder_ndk.so", RTLD_NOW | RTLD_LOCAL);
        if (loaded.handle == nullptr) {
            return loaded;
        }
        loaded.checkService = reinterpret_cast<decltype(loaded.checkService)>(
                dlsym(loaded.handle, "AServiceManager_checkService"));
        loaded.defineClass = reinterpret_cast<decltype(loaded.defineClass)>(
                dlsym(loaded.handle, "AIBinder_Class_define"));
        loaded.associateClass = reinterpret_cast<decltype(loaded.associateClass)>(
                dlsym(loaded.handle, "AIBinder_associateClass"));
        loaded.prepareTransaction = reinterpret_cast<decltype(loaded.prepareTransaction)>(
                dlsym(loaded.handle, "AIBinder_prepareTransaction"));
        loaded.transact = reinterpret_cast<decltype(loaded.transact)>(
                dlsym(loaded.handle, "AIBinder_transact"));
        loaded.writeString = reinterpret_cast<decltype(loaded.writeString)>(
                dlsym(loaded.handle, "AParcel_writeString"));
        loaded.readInt32 = reinterpret_cast<decltype(loaded.readInt32)>(
                dlsym(loaded.handle, "AParcel_readInt32"));
        loaded.readString = reinterpret_cast<decltype(loaded.readString)>(
                dlsym(loaded.handle, "AParcel_readString"));
        loaded.deleteParcel = reinterpret_cast<decltype(loaded.deleteParcel)>(
                dlsym(loaded.handle, "AParcel_delete"));
        loaded.incStrong = reinterpret_cast<decltype(loaded.incStrong)>(
                dlsym(loaded.handle, "AIBinder_incStrong"));
        loaded.decStrong = reinterpret_cast<decltype(loaded.decStrong)>(
                dlsym(loaded.handle, "AIBinder_decStrong"));
        loaded.isAlive = reinterpret_cast<decltype(loaded.isAlive)>(
                dlsym(loaded.handle, "AIBinder_isAlive"));
        if (loaded.defineClass != nullptr) {
            loaded.clazz = loaded.defineClass(kBstFilterAppsDescriptor, unusedClassCreate,
                                              unusedClassDestroy, unusedClassTransact);
        }
        return loaded;
    }();
    return api;
}

bool isAppPolicyClient() {
    const uid_t uid = getuid();
    const uid_t appId = multiuser_get_app_id(uid);
    return appId >= AID_APP_START && appId <= AID_APP_END;
}

struct BinderCache {
    std::mutex lock;
    AIBinder* binder = nullptr;
};

AIBinder* acquireSystemBstFilterService() {
    const NdkBinderApi& api = getNdkBinderApi();
    if (!api.complete()) {
        static std::once_flag logOnce;
        std::call_once(logOnce, []() {
            ALOGE("A16DBG:BSTFILTER: public NDK Binder API unavailable");
        });
        return nullptr;
    }

    [[clang::no_destroy]] static BinderCache cache;
    std::lock_guard<std::mutex> guard(cache.lock);
    if (cache.binder != nullptr && !api.isAlive(cache.binder)) {
        api.decStrong(cache.binder);
        cache.binder = nullptr;
    }
    if (cache.binder == nullptr) {
        cache.binder = api.checkService(kBstFilterAppsServiceName);
        if (cache.binder == nullptr) {
            return nullptr;
        }
        if (!api.associateClass(cache.binder, api.clazz)) {
            api.decStrong(cache.binder);
            cache.binder = nullptr;
            return nullptr;
        }
    }
    api.incStrong(cache.binder);
    return cache.binder;
}

AParcel* transactGraphicsPolicy(uint32_t transactionOffset, const String16& packageName) {
    if (!isAppPolicyClient()) {
        return nullptr;
    }

    const NdkBinderApi& api = getNdkBinderApi();
    AIBinder* binder = acquireSystemBstFilterService();
    if (binder == nullptr) {
        return nullptr;
    }

    AParcel* input = nullptr;
    AParcel* output = nullptr;
    BinderStatus status = api.prepareTransaction(binder, &input);
    if (status == kStatusOk) {
        const String8 packageUtf8(packageName);
        status = api.writeString(input, packageUtf8.c_str(),
                                 static_cast<int32_t>(packageUtf8.size()));
    }
    if (status == kStatusOk) {
        status = api.transact(binder, transactionOffset + 1, &input, &output, 0);
    }
    api.decStrong(binder);
    if (input != nullptr) {
        api.deleteParcel(input);
    }
    if (status != kStatusOk || output == nullptr) {
        if (output != nullptr) {
            api.deleteParcel(output);
        }
        return nullptr;
    }

    int32_t exceptionCode = -1;
    status = api.readInt32(output, &exceptionCode);
    if (status != kStatusOk || exceptionCode != 0) {
        api.deleteParcel(output);
        return nullptr;
    }

    static std::once_flag successLogOnce;
    std::call_once(successLogOnce, []() {
        ALOGI("A16DBG:BSTFILTER: direct system Binder graphics policy enabled");
    });
    return output;
}

bool allocateString(void* stringData, int32_t length, char** buffer) {
    auto* value = static_cast<std::string*>(stringData);
    if (length < 0) {
        value->clear();
        *buffer = nullptr;
        return true;
    }
    value->resize(static_cast<size_t>(length));
    *buffer = value->data();
    return true;
}

} // namespace

namespace bst_graphics_policy {

LIBBINDER_EXPORTED bool queryBool(uint32_t transactionOffset, const String16& packageName,
                                  bool fallback) {
    AParcel* output = transactGraphicsPolicy(transactionOffset, packageName);
    if (output == nullptr) {
        return fallback;
    }
    const NdkBinderApi& api = getNdkBinderApi();
    int32_t value = fallback ? 1 : 0;
    const BinderStatus status = api.readInt32(output, &value);
    api.deleteParcel(output);
    return status == kStatusOk ? value != 0 : fallback;
}

LIBBINDER_EXPORTED int32_t queryInt(uint32_t transactionOffset, const String16& packageName,
                                    int32_t fallback) {
    AParcel* output = transactGraphicsPolicy(transactionOffset, packageName);
    if (output == nullptr) {
        return fallback;
    }
    const NdkBinderApi& api = getNdkBinderApi();
    int32_t value = fallback;
    const BinderStatus status = api.readInt32(output, &value);
    api.deleteParcel(output);
    return status == kStatusOk ? value : fallback;
}

LIBBINDER_EXPORTED String8 queryString(uint32_t transactionOffset, const String16& packageName,
                                       const String8& fallback) {
    AParcel* output = transactGraphicsPolicy(transactionOffset, packageName);
    if (output == nullptr) {
        return fallback;
    }
    const NdkBinderApi& api = getNdkBinderApi();
    std::string value;
    const BinderStatus status = api.readString(output, &value, allocateString);
    api.deleteParcel(output);
    if (status != kStatusOk) {
        return fallback;
    }
    if (!value.empty() && value.back() == '\0') {
        value.pop_back();
    }
    return String8(value.c_str());
}

} // namespace bst_graphics_policy

    BstFilterAppsManager::BstFilterAppsManager()
    {
    }

    sp<IBstFilterAppsService> BstFilterAppsManager::getService()
    {
        //int64_t startTime = uptimeMillis();
        mLock.lock();
        sp<IBstFilterAppsService> service = mService;
        if (service == NULL || !(IInterface::asBinder(service)->isBinderAlive())) {
            sp<IBinder> binder = defaultServiceManager()->checkService(String16("bstfilterapps"));
            if (binder == NULL) {
                /*
                // Wait for the bstfilterapps service to come back...
                ALOGI("Waiting for bstfilterapps service");
                if ((uptimeMillis()-startTime) > 10000) {
                ALOGW("Waiting too long for bstfilterapps service, giving up");
                return NULL;
                }
                sleep(1);
                */
                ALOGW("Waited too long for bstfilterapps service, giving up");
            } else {
                service = interface_cast<IBstFilterAppsService>(binder);
                mService = service;
            }
        }
        mLock.unlock();
        return service;
    }

    bool BstFilterAppsManager::isSmallScreenApp(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->isSmallScreenApp(callingPackage) : false;
    }

    bool BstFilterAppsManager::forceArmInstall(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->forceArmInstall(callingPackage) : false;
    }

    bool BstFilterAppsManager::forceX86Install(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->forceX86Install(callingPackage) : false;
    }

    bool BstFilterAppsManager::isWhiteListed(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->isWhiteListed(callingPackage): false;
    }

    bool BstFilterAppsManager::isBlackListed(const String16& callingPackage, const String16& version)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->isBlackListed(callingPackage, version): false;
    }

    bool BstFilterAppsManager::isSoftKeyboardRequired(const String16& callingPackage, const String16& activity)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->isSoftKeyboardRequired(callingPackage, activity): false;
    }

    const String16 BstFilterAppsManager::getSoftKeyboardModifier(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        String16 default_return("soft");
        return service != NULL ? service->getSoftKeyboardModifier(callingPackage): default_return;
    }

    bool BstFilterAppsManager::isMarketRequired(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->isMarketRequired(callingPackage): false;
    }

    bool BstFilterAppsManager::isGlv1notimpApp(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->isGlv1notimpApp(callingPackage): false;
    }

    bool BstFilterAppsManager::isPvrtcApp(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->isPvrtcApp(callingPackage): false;
    }

    bool BstFilterAppsManager::isS3tcApp(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->isS3tcApp(callingPackage): false;
    }

    bool BstFilterAppsManager::isXarchApp(const int32_t uid)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->isXarchApp(uid): false;
    }

    bool BstFilterAppsManager::isHeadsetRequired(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->isHeadsetRequired(callingPackage) : false;
    }

    bool BstFilterAppsManager::isPortraitDisabled(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->isPortraitDisabled(callingPackage): false;
    }

    const String16 BstFilterAppsManager::getCustomDpi(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        String16 default_return("");
        return service != NULL ? service->getCustomDpi(callingPackage): default_return;
    }

    bool BstFilterAppsManager::isClearInstallApp(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->isClearInstallApp(callingPackage): false;
    }

    bool BstFilterAppsManager::isScreenOrientationFixed(const String16& callingPackage,const String16& currentPkgName)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->isScreenOrientationFixed(callingPackage,currentPkgName): false;
    }

    int BstFilterAppsManager::isCameraRotationRequired(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->isCameraRotationRequired(callingPackage) : 0;
    }

    bool BstFilterAppsManager::forceLandscapeOrientationIfUnspecified(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->forceLandscapeOrientationIfUnspecified(callingPackage): false;
    }

    const String16 BstFilterAppsManager::getGlRenderer(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        String16 default_return("");
        return service != NULL ? service->getGlRenderer(callingPackage) : default_return ;
    }

    const String16 BstFilterAppsManager::getGlVendor(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        String16 default_return("");
        return service != NULL ? service->getGlVendor(callingPackage) : default_return;
    }

    bool BstFilterAppsManager::isGL3App(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->isGL3App(callingPackage): false;
    }

    bool BstFilterAppsManager::isXArmApp(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->isXArmApp(callingPackage): false;
    }

    const String16 BstFilterAppsManager::isLoadLibHackReqd(const int32_t uid)
    {
        sp<IBstFilterAppsService> service = getService();
        String16 default_return("");
        return service != NULL ? service->isLoadLibHackReqd(uid) : default_return;
    }

    bool BstFilterAppsManager::isGL3Disabled(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->isGL3Disabled(callingPackage): false;
    }

    bool BstFilterAppsManager::isZeroMappedPageReqd(const int32_t uid)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->isZeroMappedPageReqd(uid): false;
    }

    bool BstFilterAppsManager::isModifysdPathReqd(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->isModifysdPathReqd(callingPackage): false;
    }

    bool BstFilterAppsManager::isAGAGL3Disabled(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->isAGAGL3Disabled(callingPackage): false;
    }

    bool BstFilterAppsManager::isPGAGL3Disabled(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->isPGAGL3Disabled(callingPackage): false;
    }

    bool BstFilterAppsManager::isShowOrigCpuinfoArmApp(const int32_t uid)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->isShowOrigCpuinfoArmApp(uid): false;
    }

    bool BstFilterAppsManager::isAstcApp(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->isAstcApp(callingPackage): false;
    }

    bool BstFilterAppsManager::isPatchRelocApp(const int32_t uid)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->isPatchRelocApp(uid): false;
    }

    const String16 BstFilterAppsManager::getPgaGlVersion(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        String16 default_return("");
        return service != NULL ? service->getPgaGlVersion(callingPackage) : default_return;
    }

    const String16 BstFilterAppsManager::getAgaGlVersion(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        String16 default_return("");
        return service != NULL ? service->getAgaGlVersion(callingPackage) : default_return;
    }

    bool BstFilterAppsManager::isHardwareAstcDisabledApp(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->isHardwareAstcDisabledApp(callingPackage): false;
    }

    const String16 BstFilterAppsManager::getMemorySize(const int32_t uid)
    {
        sp<IBstFilterAppsService> service = getService();
        String16 default_return("");
        return service != NULL ? service->getMemorySize(uid) : default_return;
    }

    bool BstFilterAppsManager::isAppUsingOldHoudini(const int32_t uid)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->isAppUsingOldHoudini(uid): false;
    }

    const String16 BstFilterAppsManager::getAdditionalGlExtensions(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        String16 default_return("");
        return service != NULL ? service->getAdditionalGlExtensions(callingPackage): default_return;
    }

    bool BstFilterAppsManager::areInputDevicesExposed(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->areInputDevicesExposed(callingPackage): false;
    }

    bool BstFilterAppsManager::isShowArmAbiListApp(const int32_t uid)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->isShowArmAbiListApp(uid): false;
    }

    bool BstFilterAppsManager::isIgnoreLargeHeapApp(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->isIgnoreLargeHeapApp(callingPackage): false;
    }

    bool BstFilterAppsManager::isClearCodeCacheApp(const int32_t uid)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->isClearCodeCacheApp(uid): false;
    }

    bool BstFilterAppsManager::isImageDetectionEnabled(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->isImageDetectionEnabled(callingPackage): false;
    }

    int BstFilterAppsManager::getHeapGrowthLimitSize(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->getHeapGrowthLimitSize(callingPackage): -1;
    }

    bool BstFilterAppsManager::isHideProcMapsApp(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->isHideProcMapsApp(callingPackage): false;
    }

    bool BstFilterAppsManager::isEnableNativeGamePad(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->isEnableNativeGamePad(callingPackage): false;
    }

    bool BstFilterAppsManager::isPreloadBstHookLibraryApp(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->isPreloadBstHookLibraryApp(callingPackage): false;
    }

    bool BstFilterAppsManager::isIl2cppApp(const int32_t uid)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->isIl2cppApp(uid): false;
    }

    void BstFilterAppsManager::updateIl2cppPkgs(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        service->updateIl2cppPkgs(callingPackage);
        return;
    }

    bool BstFilterAppsManager::isSuppressedNotificationApp(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->isSuppressedNotificationApp(callingPackage): false;
    }

    bool BstFilterAppsManager::isMacrosDisabledApp(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->isMacrosDisabledApp(callingPackage): false;
    }

    bool BstFilterAppsManager::showFeedbackPopup(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->showFeedbackPopup(callingPackage): false;
    }

    float BstFilterAppsManager::ffmpegConfidenceForApp(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->ffmpegConfidenceForApp(callingPackage): 0.0f;
    }

    bool BstFilterAppsManager::isAppUsingSwappy(const int32_t uid)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->isAppUsingSwappy(uid): false;
    }

    int BstFilterAppsManager::getCameraSensorRotation(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->getCameraSensorRotation(callingPackage) : 0;
    }

    int BstFilterAppsManager::getCameraInitRotation(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->getCameraInitRotation(callingPackage) : 0;
    }

    bool BstFilterAppsManager::isUE4GLFlushApp(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->isUE4GLFlushApp(callingPackage): false;
    }

    const String16 BstFilterAppsManager::isVulkanRequired(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        String16 default_return("");
        return service != NULL ? service->isVulkanRequired(callingPackage) : default_return;
    }

    bool BstFilterAppsManager::isForceKillApp(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->isForceKillApp(callingPackage): false;
    }

    bool BstFilterAppsManager::isFixedDisplayRotationApp(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->isFixedDisplayRotationApp(callingPackage): false;
    }

    bool BstFilterAppsManager::isHppEnabled(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->isHppEnabled(callingPackage): true;
    }

    bool BstFilterAppsManager::isHotFixApp(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->isHotFixApp(callingPackage): false;
    }

    bool BstFilterAppsManager::isGLInvalidateFramebufferFilterApp(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->isGLInvalidateFramebufferFilterApp(callingPackage): false;
    }

    int BstFilterAppsManager::getUnityFlickerPatchRequired(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->getUnityFlickerPatchRequired(callingPackage) : 0;
    }

    int BstFilterAppsManager::getXperfMode(const int32_t uid)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->getXperfMode(uid): 0;
    }

    bool BstFilterAppsManager::isIntelGLDispatchComputeFlushApp(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->isIntelGLDispatchComputeFlushApp(callingPackage): false;
    }

    bool BstFilterAppsManager::isDhdg(const int32_t uid)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->isDhdg(uid): false;
    }

    bool BstFilterAppsManager::isGlNativeSyncDisabled(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->isGlNativeSyncDisabled(callingPackage): false;
    }

    bool BstFilterAppsManager::isAngleDisabled(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->isAngleDisabled(callingPackage): false;
    }

    bool BstFilterAppsManager::isHotFixAppByUid(const int32_t uid)
    {
        (void)uid;  // A16DBG:P2:D9 silence -Wunused-parameter in vendor variant (uid only used in system path)
#ifndef __ANDROID_VNDK__  // A16DBG:P2:D9 PermissionController system-only; vendor fail-open
        Vector<String16> packages;
        PermissionController pc;
        pc.getPackagesForUid(uid, packages);
        if (packages.size() > 0) {
            return isHotFixApp(packages[0]);
        }
#endif
        return false;
    }

    bool BstFilterAppsManager::isFbScreenLockApp(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->isFbScreenLockApp(callingPackage): false;
    }

    bool BstFilterAppsManager::isOneStorePay(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->isOneStorePay(callingPackage): false;
    }

    bool BstFilterAppsManager::isGLProgramBinaryApp(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->isGLProgramBinaryApp(callingPackage): true;
    }

    bool BstFilterAppsManager::isGLUnmapBufferPerfApp(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->isGLUnmapBufferPerfApp(callingPackage): true;
    }

    const String16 BstFilterAppsManager::getGLShaderWorkaround(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        String16 default_return("");
        return service != NULL ? service->getGLShaderWorkaround(callingPackage) : default_return;
    }

    bool BstFilterAppsManager::isDrmEnabled(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->isDrmEnabled(callingPackage): false;
    }

    bool BstFilterAppsManager::isEtherNetType(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->isEtherNetType(callingPackage): false;
    }

    bool BstFilterAppsManager::isTexTargetCheckDisabled(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->isTexTargetCheckDisabled(callingPackage): true;
    }

    int BstFilterAppsManager::getFixedSurfaceRotationRequired(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->getFixedSurfaceRotationRequired(callingPackage) : -1;
    }

    const String16 BstFilterAppsManager::getIapSetting(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        String16 default_return("");
        return service != NULL ? service->getIapSetting(callingPackage) : default_return;
    }

    bool BstFilterAppsManager::isGlMapBufferRangeHost(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->isGlMapBufferRangeHost(callingPackage): true;
    }

    bool BstFilterAppsManager::isIgnoreSyncTimeout(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->isIgnoreSyncTimeout(callingPackage): false;
    }

    bool BstFilterAppsManager::isGLVBOCacheDisableApp(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->isGLVBOCacheDisableApp(callingPackage): false;
    }

    bool BstFilterAppsManager::isBlockEditWhenComposing(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->isBlockEditWhenComposing(callingPackage): false;
    }

    const String16 BstFilterAppsManager::getGLHostInfo(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        String16 default_return("");
        return service != NULL ? service->getGLHostInfo(callingPackage) : default_return;
    }

    const String16 BstFilterAppsManager::getGLExtensionsIgnore(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        String16 default_return("");
        return service != NULL ? service->getGLExtensionsIgnore(callingPackage) : default_return;
    }

    const String16 BstFilterAppsManager::getVkHostInfo(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        String16 default_return("");
        return service != NULL ? service->getVkHostInfo(callingPackage) : default_return;
    }

    const String16 BstFilterAppsManager::getVKDeviceExtIgnore(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        String16 default_return("");
        return service != NULL ? service->getVKDeviceExtIgnore(callingPackage) : default_return;
    }

    bool BstFilterAppsManager::isEGLSurfaceIgnore(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->isEGLSurfaceIgnore(callingPackage): false;
    }

    bool BstFilterAppsManager::isHardKeyBoard(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->isHardKeyBoard(callingPackage): false;
    }

     bool BstFilterAppsManager::isIntelAutoGLFlushApp(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->isIntelAutoGLFlushApp(callingPackage): true;
    }

    bool BstFilterAppsManager::isRotateDisabled(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->isRotateDisabled(callingPackage): false;
    }

    bool BstFilterAppsManager::isUnreal5App(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->isUnreal5App(callingPackage): false;
    }

    bool BstFilterAppsManager::isUE5PBDisabled(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->isUE5PBDisabled(callingPackage): false;
    }

    bool BstFilterAppsManager::isBptcApp(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->isBptcApp(callingPackage): false;
    }

    bool BstFilterAppsManager::isExtractNativeLibs(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->isExtractNativeLibs(callingPackage): false;
    }

    bool BstFilterAppsManager::isDefaultXYDpi(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->isDefaultXYDpi(callingPackage): false;
    }

    int BstFilterAppsManager::getPScoreAbove(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->getPScoreAbove(callingPackage) : 0;
    }

    bool BstFilterAppsManager::isMapBufRangeReadOnceEnabled(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->isMapBufRangeReadOnceEnabled(callingPackage): false;
    }

    bool BstFilterAppsManager::isFbCompleteCheckDisabled(const String16& callingPackage)
    {
        sp<IBstFilterAppsService> service = getService();
        return service != NULL ? service->isFbCompleteCheckDisabled(callingPackage): false;
    }
} // namespace android

extern "C" bool bstIsHotFixApp(const char* callingPackage)
{
    return android::BstFilterAppsManager().isHotFixApp(android::String16(callingPackage));
}

extern "C" int bst_getXPerfMode(const int32_t uid)
{
    return android::BstFilterAppsManager().getXperfMode(uid);
}

extern "C" bool bstIsHotFixAppByUid(const int32_t uid)
{
    return android::BstFilterAppsManager().isHotFixAppByUid(uid);
}
