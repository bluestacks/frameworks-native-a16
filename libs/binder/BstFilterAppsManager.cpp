#ifndef __ANDROID_VENDOR__
#define LOG_TAG "BstFilterAppsManager"

#include <binder/BstFilterAppsManager.h>
#include <binder/Binder.h>
#include <binder/IServiceManager.h>

#include <utils/Log.h>
#include <utils/SystemClock.h>

#include <binder/PermissionController.h>
// BS-A16: Force linker to keep all BstFilterAppsManager methods.
// __attribute__((retain)) prevents -ffunction-sections dead-strip.
// Each method call below creates a reference, keeping it alive.
extern "C" __attribute__((visibility("default"), used, retain))
void _bstfilterapps_keepalive() {
    android::BstFilterAppsManager b;
    volatile int v = 0; android::String16 s("");
    b.isSmallScreenApp(s); b.forceArmInstall(s); b.forceX86Install(s);
    b.isWhiteListed(s); b.isBlackListed(s,s); b.isSoftKeyboardRequired(s,s);
    s = b.getSoftKeyboardModifier(s); b.isMarketRequired(s); b.isHeadsetRequired(s);
    b.isPortraitDisabled(s); s = b.getCustomDpi(s); b.isPvrtcApp(s);
    b.isS3tcApp(s); b.isGlv1notimpApp(s); b.isXarchApp(v);
    b.isClearInstallApp(s); b.isScreenOrientationFixed(s,s); v = b.isCameraRotationRequired(s);
    b.forceLandscapeOrientationIfUnspecified(s); s = b.getGlRenderer(s);
    s = b.getGlVendor(s); b.isGL3App(s); s = b.isLoadLibHackReqd(v);
    b.isGL3Disabled(s); b.isZeroMappedPageReqd(v); b.isModifysdPathReqd(s);
    b.isAGAGL3Disabled(s); b.isPGAGL3Disabled(s); b.isShowOrigCpuinfoArmApp(v);
    b.isAstcApp(s); b.isPatchRelocApp(v); s = b.getPgaGlVersion(s);
    s = b.getAgaGlVersion(s); b.isHardwareAstcDisabledApp(s); b.isXArmApp(s);
    s = b.getMemorySize(v); b.isAppUsingOldHoudini(v); s = b.getAdditionalGlExtensions(s);
    b.areInputDevicesExposed(s); b.isShowArmAbiListApp(v); b.isIgnoreLargeHeapApp(s);
    b.isClearCodeCacheApp(v); b.isImageDetectionEnabled(s); v = b.getHeapGrowthLimitSize(s);
    b.isHideProcMapsApp(s); b.isEnableNativeGamePad(s); b.isPreloadBstHookLibraryApp(s);
    b.isIl2cppApp(v); b.updateIl2cppPkgs(s); b.isSuppressedNotificationApp(s);
    b.isMacrosDisabledApp(s); b.showFeedbackPopup(s); float f = b.ffmpegConfidenceForApp(s);
    b.isAppUsingSwappy(v); s = b.getMouseCursorStyle(s); v = b.getCameraSensorRotation(s);
    v = b.getCameraInitRotation(s); b.isUE4GLFlushApp(s); b.isGetNowggAccountsListApp(v);
    b.isGoogleSignInRequired(s); s = b.isVulkanRequired(s); b.isForceKillApp(s);
    b.isFixedDisplayRotationApp(s); s = b.getGameDefaultSetting(s); b.isHppEnabled(s);
    b.isHotFixApp(s); b.isGLInvalidateFramebufferFilterApp(s); v = b.getUnityFlickerPatchRequired(s);
    s = b.getDefaultProfile(s); v = b.getXperfMode(v); b.isIntelGLDispatchComputeFlushApp(s);
    b.isDhdg(v); b.isGlNativeSyncDisabled(s); b.isAngleDisabled(s);
    b.isHotFixAppByUid(v); b.isFbScreenLockApp(s); b.isOneStorePay(s);
    b.isGLProgramBinaryApp(s); b.isGLUnmapBufferPerfApp(s); s = b.getGLShaderWorkaround(s);
    b.isDrmEnabled(s); b.isEtherNetType(s); b.isTexTargetCheckDisabled(s);
    v = b.getFixedSurfaceRotationRequired(s); s = b.getIapSetting(s); b.isGlMapBufferRangeHost(s);
    b.isIgnoreSyncTimeout(s); b.isGLVBOCacheDisableApp(s); b.isBlockEditWhenComposing(s);
    s = b.getGLHostInfo(s); s = b.getGLExtensionsIgnore(s); s = b.getVkHostInfo(s);
    s = b.getVKDeviceExtIgnore(s); b.isEGLSurfaceIgnore(s); b.isHardKeyBoard(s);
    b.isIntelAutoGLFlushApp(s); b.isRotateDisabled(s); b.isUnreal5App(s);
    b.isUE5PBDisabled(s); b.isBptcApp(s); b.isExtractNativeLibs(s);
    b.isDefaultXYDpi(s); v = b.getPScoreAbove(s); b.isMapBufRangeReadOnceEnabled(s);
    b.isFbCompleteCheckDisabled(s); b.isImmersiveEnabledApp(s);
    (void)v; (void)f; (void)s;
}


namespace android {

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wexit-time-destructors"
    static String16 _bstfilterapps("bstfilterapps");
#pragma clang diagnostic pop

    BstFilterAppsManager::BstFilterAppsManager()
    {
    }

    sp<IBstFilterAppsService> BstFilterAppsManager::getService()
    {
        //int64_t startTime = uptimeMillis();
        mLock.lock();
        sp<IBstFilterAppsService> service = mService;
        if (service == NULL || !(IInterface::asBinder(service)->isBinderAlive())) {
            sp<IBinder> binder = defaultServiceManager()->checkService(_bstfilterapps);
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
        Vector<String16> packages;
        PermissionController pc;
        pc.getPackagesForUid(uid, packages);
        if (packages.size() > 0) {
            return isHotFixApp(packages[0]);
        }
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

    // BS-A16: empty stubs for methods referenced by _bstfilterapps_keepalive
    // but not yet wired to IBstFilterAppsService.
    const String16 BstFilterAppsManager::getMouseCursorStyle(const String16& /*callingPackage*/)
    {
        return String16();
    }

    bool BstFilterAppsManager::isGetNowggAccountsListApp(const int32_t /*uid*/)
    {
        return false;
    }

    bool BstFilterAppsManager::isGoogleSignInRequired(const String16& /*callingPackage*/)
    {
        return false;
    }

    const String16 BstFilterAppsManager::getGameDefaultSetting(const String16& /*pkgName*/)
    {
        return String16();
    }

    const String16 BstFilterAppsManager::getDefaultProfile(const String16& /*pkgName*/)
    {
        return String16();
    }

    bool BstFilterAppsManager::isImmersiveEnabledApp(const String16& /*callingPackage*/)
    {
        return false;
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

#endif // __ANDROID_VENDOR__
