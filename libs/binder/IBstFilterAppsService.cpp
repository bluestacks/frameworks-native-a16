#ifndef __ANDROID_VENDOR__
#define LOG_TAG "BstFilterAppsService"

#include <binder/IBstFilterAppsService.h>

#include <utils/Debug.h>
#include <utils/Log.h>
#include <binder/Parcel.h>
#include <utils/String8.h>
#include <utils/String16.h>

#include <Static.h>

namespace android {

// ----------------------------------------------------------------------

class BpBstFilterAppsService : public BpInterface<IBstFilterAppsService>
{
public:
    explicit BpBstFilterAppsService(const sp<IBinder>& impl)
        : BpInterface<IBstFilterAppsService>(impl)
    {
    }

    virtual bool isSmallScreenApp(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_isSmallScreenApp, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return false;
        int32_t res = reply.readInt32();
        if (res == 1)
            return true;
        else
            return false;
    }

    virtual bool forceArmInstall(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_forceArmInstall, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return false;
        int32_t res = reply.readInt32();
        if (res == 1)
            return true;
        else
            return false;

    }

    virtual bool forceX86Install(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_forceX86Install, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return false;
        int32_t res = reply.readInt32();
        if (res == 1)
            return true;
        else
            return false;
    }

    virtual bool isWhiteListed(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_isWhiteListed, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return false;
        int32_t res = reply.readInt32();
        if (res == 1)
            return true;
        else
            return false;
    }

    virtual bool isBlackListed(const String16& packageName, const String16& version) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        data.writeString16(version);
        remote()->transact(T_isBlackListed, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return false;
        int32_t res = reply.readInt32();
        if (res == 1)
            return true;
        else
            return false;
    }

    virtual bool isSoftKeyboardRequired(const String16& packageName, const String16& activity) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        data.writeString16(activity);
        remote()->transact(T_isSoftKeyboardRequired, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return false;
        int32_t res = reply.readInt32();
        if (res == 1)
            return true;
        else
            return false;
    }

    virtual const String16 getSoftKeyboardModifier(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_getSoftKeyboardModifier, data, &reply);
        // fail on exception
        String16 default_return("soft");
        if (reply.readExceptionCode() != 0) return default_return;
        return reply.readString16();
    }

    virtual bool isMarketRequired(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_isMarketRequired, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return false;
        int32_t res = reply.readInt32();
        if (res == 1)
            return true;
        else
            return false;
    }

    virtual bool isHeadsetRequired(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_isHeadsetRequired, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return false;
        int32_t res = reply.readInt32();
        if (res == 1)
            return true;
        else
            return false;

    }

    virtual bool isPortraitDisabled(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_isPortraitDisabled, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0)
        {
            return false;
        }
        int32_t res = reply.readInt32();
        if (res == 1)
            return true;
        else
            return false;

    }

    virtual const String16 getCustomDpi(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_getCustomDpi, data, &reply);
        String16 default_return("");
        // fail on exception
        if (reply.readExceptionCode() != 0) return default_return;
        return reply.readString16();
    }

    virtual bool isGlv1notimpApp(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_isGlv1notimpApp, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return false;
        int32_t res = reply.readInt32();
        if (res == 1)
            return true;
        else
            return false;
    }

    virtual bool isPvrtcApp(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_isPvrtcApp, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return false;
        int32_t res = reply.readInt32();
        if (res == 1)
            return true;
        else
            return false;
    }

    virtual bool isS3tcApp(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_isS3tcApp, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return false;
        int32_t res = reply.readInt32();
        if (res == 1)
            return true;
        else
            return false;
    }

    virtual bool isXarchApp(const int32_t uid) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeInt32(uid);
        remote()->transact(T_isXarchApp, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return false;
        int32_t res = reply.readInt32();
        if (res == 1)
            return true;
        else
            return false;
    }

    virtual bool isClearInstallApp(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_isClearInstallApp, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return false;
        int32_t res = reply.readInt32();
        if (res == 1)
            return true;
        else
            return false;
    }

    virtual bool isScreenOrientationFixed(const String16& callingPkgName,const String16& currentPkgName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(callingPkgName);
        data.writeString16(currentPkgName);
        remote()->transact(T_isScreenOrientationFixed, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return false;
        int32_t res = reply.readInt32();
        if (res == 1)
            return true;
        else
            return false;
    }

    virtual int isCameraRotationRequired(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_isCameraRotationRequired, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return 0;
        int32_t res = reply.readInt32();
        return res;
    }

    virtual bool forceLandscapeOrientationIfUnspecified(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_forceLandscapeOrientationIfUnspecified, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return false;
        int32_t res = reply.readInt32();
        if (res == 1)
            return true;
        else
            return false;
    }

    virtual const String16 getGlRenderer(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_getGlRenderer, data, &reply);
        String16 default_return("");
        // fail on exception
        if (reply.readExceptionCode() != 0) return default_return;
        return reply.readString16();
    }

    virtual const String16 getGlVendor(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_getGlVendor, data, &reply);
        String16 default_return("");
        // fail on exception
        if (reply.readExceptionCode() != 0) return default_return;
        return reply.readString16();
    }

    virtual bool isXArmApp(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_isXArmApp, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return false;
        int32_t res = reply.readInt32();
        if (res == 1)
            return true;
        else
            return false;
    }

    virtual bool isGL3App(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_isGL3App, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return false;
        int32_t res = reply.readInt32();
        if (res == 1)
            return true;
        else
            return false;
    }

    virtual const String16 isLoadLibHackReqd(const int32_t uid) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeInt32(uid);
        remote()->transact(T_isLoadLibHackReqd, data, &reply);
        String16 default_return("");
        // fail on exception
        if (reply.readExceptionCode() != 0) return default_return;
        return reply.readString16();
    }

    virtual bool isGL3Disabled(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_isGL3Disabled, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return false;
        int32_t res = reply.readInt32();
        if (res == 1)
            return true;
        else
            return false;
    }

    virtual bool isZeroMappedPageReqd(const int32_t uid) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeInt32(uid);
        remote()->transact(T_isZeroMappedPageReqd, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return false;
        int32_t res = reply.readInt32();
        if (res == 1)
            return true;
        else
            return false;
    }

    virtual bool isModifysdPathReqd(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_isModifysdPathReqd, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return false;
        int32_t res = reply.readInt32();
        if (res == 1)
            return true;
        else
            return false;
    }

    virtual bool isAGAGL3Disabled(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_isAGAGL3Disabled, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return false;
        int32_t res = reply.readInt32();
        if (res == 1)
            return true;
        else
            return false;
    }

    virtual bool isPGAGL3Disabled(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_isPGAGL3Disabled, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return false;
        int32_t res = reply.readInt32();
        if (res == 1)
            return true;
        else
            return false;
    }

    virtual bool isShowOrigCpuinfoArmApp(const int32_t uid) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeInt32(uid);
        remote()->transact(T_isShowOrigCpuinfoArmApp, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return false;
        int32_t res = reply.readInt32();
        if (res == 1)
            return true;
        else
            return false;
    }

    virtual bool isAstcApp(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_isAstcApp, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return false;
        int32_t res = reply.readInt32();
        if (res == 1)
            return true;
        else
            return false;
    }

    virtual bool isPatchRelocApp(const int32_t uid) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeInt32(uid);
        remote()->transact(T_isPatchRelocApp, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return false;
        int32_t res = reply.readInt32();
        if (res == 1)
            return true;
        else
            return false;
    }

    virtual const String16 getPgaGlVersion(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_getPgaGlVersion, data, &reply);
        String16 default_return("");
        // fail on exception
        if (reply.readExceptionCode() != 0) return default_return;
        return reply.readString16();
    }

    virtual const String16 getAgaGlVersion(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_getAgaGlVersion, data, &reply);
        String16 default_return("");
        // fail on exception
        if (reply.readExceptionCode() != 0) return default_return;
        return reply.readString16();
    }

    virtual bool isHardwareAstcDisabledApp(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_isHardwareAstcDisabledApp, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return false;
        int32_t res = reply.readInt32();
        if (res == 1)
            return true;
        else
            return false;
    }

    virtual const String16 getMemorySize(const int32_t uid) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeInt32(uid);
        remote()->transact(T_getMemorySize, data, &reply);
        String16 default_return("");
        // fail on exception
        if (reply.readExceptionCode() != 0) return default_return;
        return reply.readString16();
    }

    virtual bool isAppUsingOldHoudini(const int32_t uid) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeInt32(uid);
        remote()->transact(T_isAppUsingOldHoudini, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return false;
        int32_t res = reply.readInt32();
        if (res == 1)
            return true;
        else
            return false;
    }

    virtual const String16 getAdditionalGlExtensions(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_getAdditionalGlExtensions, data, &reply);
        String16 default_return("");
        //fail on exception
        if (reply.readExceptionCode() != 0) return default_return;
        return reply.readString16();
    }

    virtual bool areInputDevicesExposed(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_areInputDevicesExposed, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return false;
        int32_t res = reply.readInt32();
        if (res == 1)
            return true;
        else
            return false;
    }

    virtual bool isShowArmAbiListApp(const int32_t uid) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeInt32(uid);
        remote()->transact(T_isShowArmAbiListApp, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return false;
        int32_t res = reply.readInt32();
        if (res == 1)
            return true;
        else
            return false;
    }

    virtual bool isIgnoreLargeHeapApp(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_isIgnoreLargeHeapApp, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return false;
        int32_t res = reply.readInt32();
        if (res == 1)
            return true;
        else
            return false;
    }

    virtual bool isClearCodeCacheApp(const int32_t uid) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeInt32(uid);
        remote()->transact(T_isClearCodeCacheApp, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return false;
        int32_t res = reply.readInt32();
        if (res == 1)
            return true;
        else
            return false;
    }

    virtual bool isImageDetectionEnabled(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_isImageDetectionEnabled, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return false;
        int32_t res = reply.readInt32();
        if (res == 1)
            return true;
        else
            return false;
    }

    virtual int getHeapGrowthLimitSize(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_getHeapGrowthLimitSize, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return -1;
        int32_t res = reply.readInt32();
        return res;
    }

    virtual bool isHideProcMapsApp(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_isHideProcMapsApp, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return false;
        int32_t res = reply.readInt32();
        if (res == 1)
            return true;
        else
            return false;
    }

    virtual bool isEnableNativeGamePad(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_isEnableNativeGamePad, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return false;
        int32_t res = reply.readInt32();
        if (res == 1)
            return true;
        else
            return false;
    }

    virtual bool isPreloadBstHookLibraryApp(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_isPreloadBstHookLibraryApp, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return false;
        int32_t res = reply.readInt32();
        if (res == 1)
            return true;
        else
            return false;
    }

    virtual bool isIl2cppApp(const int32_t uid) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeInt32(uid);
        remote()->transact(T_isIl2cppApp, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return false;
        int32_t res = reply.readInt32();
        if (res == 1)
            return true;
        else
            return false;
    }

    void updateIl2cppPkgs(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_updateIl2cppPkgs, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return;

        return;
    }

    virtual bool isSuppressedNotificationApp(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_isSuppressedNotificationApp, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return false;
        int32_t res = reply.readInt32();
        if (res == 1)
            return true;
        else
            return false;
    }

    virtual bool isMacrosDisabledApp(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_isMacrosDisabledApp, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return false;
        int32_t res = reply.readInt32();
        if (res == 1)
            return true;
        else
            return false;
    }

    virtual bool showFeedbackPopup(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_showFeedbackPopup, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return false;
        int32_t res = reply.readInt32();
        if (res == 1)
            return true;
        else
            return false;
    }

    virtual float ffmpegConfidenceForApp(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_ffmpegConfidenceForApp, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return 0.0f;
        float res = reply.readFloat();
        return res;
    }

    virtual bool isAppUsingSwappy(const int32_t uid) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeInt32(uid);
        remote()->transact(T_isAppUsingSwappy, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return false;
        int32_t res = reply.readInt32();
        if (res == 1)
            return true;
        else
            return false;
    }

    virtual const String16 getMouseCursorStyle(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_getMouseCursorStyle, data, &reply);
        String16 default_return("");
        // fail on exception
        if (reply.readExceptionCode() != 0) return default_return;
        return reply.readString16();
    }

    virtual int getCameraSensorRotation(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_getCameraSensorRotation, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return 0;
        int32_t res = reply.readInt32();
        return res;
    }

    virtual int getCameraInitRotation(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_getCameraInitRotation, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return 0;
        int32_t res = reply.readInt32();
        return res;
    }

    virtual bool isUE4GLFlushApp(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_isUE4GLFlushApp, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return false;
        int32_t res = reply.readInt32();
        if (res == 1)
            return true;
        else
            return false;
    }

    virtual bool isGetNowggAccountsListApp(const int32_t uid) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeInt32(uid);
        remote()->transact(T_isGetNowggAccountsListApp, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return false;
        int32_t res = reply.readInt32();
        if (res == 1)
            return true;
        else
            return false;
    }

    virtual bool isGoogleSignInRequired(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_isGoogleSignInRequired, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return false;
        int32_t res = reply.readInt32();
        if (res == 1)
            return true;
        else
            return false;
    }

    virtual const String16 isVulkanRequired(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_isVulkanRequired, data, &reply);
        String16 default_return("");
        // fail on exception
        if (reply.readExceptionCode() != 0) return default_return;
        return reply.readString16();
    }


    virtual bool isForceKillApp(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_isForceKillApp, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return false;
        int32_t res = reply.readInt32();
        if (res == 1)
            return true;
        else
            return false;
    }

    virtual bool isFixedDisplayRotationApp(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_isFixedDisplayRotationApp, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return false;
        int32_t res = reply.readInt32();
        if (res == 1)
            return true;
        else
            return false;
    }


    virtual const String16 getGameDefaultSetting(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_getGameDefaultSetting, data, &reply);
        String16 default_return("");
        // fail on exception
        if (reply.readExceptionCode() != 0) return default_return;
        return reply.readString16();
    }

    virtual bool isHppEnabled(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_isHppEnabled, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return true;
        int32_t res = reply.readInt32();
        if (res == 1)
            return true;
        else
            return false;
    }

    virtual bool isHotFixApp(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_isHotFixApp, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return false;
        int32_t res = reply.readInt32();
        if (res == 1)
            return true;
        else
            return false;
    }

    virtual bool isGLInvalidateFramebufferFilterApp(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_isGLInvalidateFramebufferFilterApp, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return false;
        int32_t res = reply.readInt32();
        if (res == 1)
            return true;
        else
            return false;
    }

    virtual int getUnityFlickerPatchRequired(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_getUnityFlickerPatchRequired, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return 0;
        int32_t res = reply.readInt32();
        return res;
    }
    virtual const String16 getDefaultProfile(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_getDefaultProfile, data, &reply);
        String16 default_return("");
        // fail on exception
        if (reply.readExceptionCode() != 0) return default_return;
        return reply.readString16();
    }

    virtual int getXperfMode(const int32_t uid) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeInt32(uid);
        remote()->transact(T_getXperfMode, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return 0;
        int32_t res = reply.readInt32();
        return res;
    }

    virtual bool isIntelGLDispatchComputeFlushApp(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_isIntelGLDispatchComputeFlushApp, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return false;
        int32_t res = reply.readInt32();
        if (res == 1)
            return true;
        else
            return false;
    }

    virtual bool isDhdg(const int32_t uid) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeInt32(uid);
        remote()->transact(T_isDhdg, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return false;
        int32_t res = reply.readInt32();
        if (res == 1)
            return true;
        else
            return false;
    }

    virtual bool isGlNativeSyncDisabled(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_isGlNativeSyncDisabled, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return false;
        int32_t res = reply.readInt32();
        if (res == 1)
            return true;
        else
            return false;
    }

    virtual bool isAngleDisabled(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_isAngleDisabled, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return false;
        int32_t res = reply.readInt32();
        if (res == 1)
            return true;
        else
            return false;
    }

    virtual bool isFbScreenLockApp(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_isFbScreenLockApp, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return false;
        int32_t res = reply.readInt32();
        if (res == 1)
            return true;
        else
            return false;
    }

    virtual bool isOneStorePay(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_isOneStorePay, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return false;
        int32_t res = reply.readInt32();
        if (res == 1)
            return true;
        else
            return false;
    }

    virtual bool isGLProgramBinaryApp(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_isGLProgramBinaryApp, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return true;
        int32_t res = reply.readInt32();
        if (res == 1)
            return true;
        else
            return false;
    }

    virtual bool isGLUnmapBufferPerfApp(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_isGLUnmapBufferPerfApp, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return true;
        int32_t res = reply.readInt32();
        if (res == 1)
            return true;
        else
            return false;
    }

    virtual const String16 getGLShaderWorkaround(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_getGLShaderWorkaround, data, &reply);
        String16 default_return("");
        // fail on exception
        if (reply.readExceptionCode() != 0) return default_return;
        return reply.readString16();
    }

    virtual bool isDrmEnabled(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_isDrmEnabled, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return false;
        int32_t res = reply.readInt32();
        if (res == 1)
            return true;
        else
            return false;
    }

    virtual bool isEtherNetType(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_isEtherNetType, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return false;
        int32_t res = reply.readInt32();
        if (res == 1)
            return true;
        else
            return false;
    }

    virtual bool isTexTargetCheckDisabled(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_isTexTargetCheckDisabled, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return true;
        int32_t res = reply.readInt32();
        if (res == 1)
            return true;
        else
            return false;
    }

    virtual bool isIgnoreSyncTimeout(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_isIgnoreSyncTimeout, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return false;
        int32_t res = reply.readInt32();
        if (res == 1)
            return true;
        else
            return false;
    }

    virtual int getFixedSurfaceRotationRequired(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_getFixedSurfaceRotationRequired, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return -1;
        int32_t res = reply.readInt32();
        return res;
    }

    virtual const String16 getIapSetting(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_getIapSetting, data, &reply);
        String16 default_return("");
        // fail on exception
        if (reply.readExceptionCode() != 0) return default_return;
        return reply.readString16();
    }

    virtual bool isGlMapBufferRangeHost(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_isGlMapBufferRangeHost, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return true;
        int32_t res = reply.readInt32();
        if (res == 1)
            return true;
        else
            return false;
    }

    virtual bool isGLVBOCacheDisableApp(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_isGLVBOCacheDisableApp, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return false;
        int32_t res = reply.readInt32();
        if (res == 1)
            return true;
        else
            return false;
    }

    virtual bool isBlockEditWhenComposing(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_isBlockEditWhenComposing, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return false;
        int32_t res = reply.readInt32();
        if (res == 1)
            return true;
        else
            return false;
    }

    virtual const String16 getGLHostInfo(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_getGLHostInfo, data, &reply);
        String16 default_return("");
        // fail on exception
        if (reply.readExceptionCode() != 0) return default_return;
        return reply.readString16();
    }

    virtual const String16 getGLExtensionsIgnore(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_getGLExtensionsIgnore, data, &reply);
        String16 default_return("");
        // fail on exception
        if (reply.readExceptionCode() != 0) return default_return;
        return reply.readString16();
    }

    virtual const String16 getVkHostInfo(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_getVkHostInfo, data, &reply);
        String16 default_return("");
        // fail on exception
        if (reply.readExceptionCode() != 0) return default_return;
        return reply.readString16();
    }

    virtual const String16 getVKDeviceExtIgnore(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_getVKDeviceExtIgnore, data, &reply);
        String16 default_return("");
        // fail on exception
        if (reply.readExceptionCode() != 0) return default_return;
        return reply.readString16();
    }

    virtual bool isEGLSurfaceIgnore(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_isEGLSurfaceIgnore, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return false;
        int32_t res = reply.readInt32();
        if (res == 1)
            return true;
        else
            return false;
    }

    virtual bool isHardKeyBoard(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_isHardKeyBoard, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return false;
        int32_t res = reply.readInt32();
        if (res == 1)
            return true;
        else
            return false;
    }

    virtual bool isIntelAutoGLFlushApp(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_isIntelAutoGLFlushApp, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return true;
        int32_t res = reply.readInt32();
        if (res == 1)
            return true;
        else
            return false;
    }

    virtual bool isRotateDisabled(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_isRotateDisabled, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return false;
        int32_t res = reply.readInt32();
        if (res == 1)
            return true;
        else
            return false;
    }

    virtual bool isUnreal5App(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_isUnreal5App, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return false;
        int32_t res = reply.readInt32();
        if (res == 1)
            return true;
        else
            return false;
    }

    virtual bool isUE5PBDisabled(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_isUE5PBDisabled, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return false;
        int32_t res = reply.readInt32();
        if (res == 1)
            return true;
        else
            return false;
    }

    virtual bool isBptcApp(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_isBptcApp, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return false;
        int32_t res = reply.readInt32();
        if (res == 1)
            return true;
        else
            return false;
    }

    virtual bool isExtractNativeLibs(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_isExtractNativeLibs, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return false;
        int32_t res = reply.readInt32();
        if (res == 1)
            return true;
        else
            return false;
    }

    virtual bool isDefaultXYDpi(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_isDefaultXYDpi, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return false;
        int32_t res = reply.readInt32();
        if (res == 1)
            return true;
        else
            return false;
        return res;
    }

    virtual int getPScoreAbove(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_getPScoreAbove, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return false;
        int32_t res = reply.readInt32();
        return res;
    }

    virtual bool isMapBufRangeReadOnceEnabled(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_isMapBufRangeReadOnceEnabled, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return false;
        int32_t res = reply.readInt32();
        if (res == 1)
            return true;
        else
            return false;
    }

    virtual bool isFbCompleteCheckDisabled(const String16& packageName) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstFilterAppsService::getInterfaceDescriptor());
        data.writeString16(packageName);
        remote()->transact(T_isFbCompleteCheckDisabled, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return false;
        int32_t res = reply.readInt32();
        if (res == 1)
            return true;
        else
            return false;
    }
};

// ----------------------------------------------------------------------

IMPLEMENT_META_INTERFACE(BstFilterAppsService, "com.bluestacks.os.IBstFilterAppsService")

// ----------------------------------------------------------------------

// NOLINTNEXTLINE(google-default-arguments)
status_t BnBstFilterAppsService::onTransact(
    uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags)
{
    //printf("BstFilterAppsService received: "); data.print();
    switch(code) {
        case T_isSmallScreenApp: {
            CHECK_INTERFACE(IBstFilterAppsService, data, reply);
            String16 packageName = data.readString16();
            bool res = isSmallScreenApp(packageName);
            reply->writeNoException();
            if (res == true)
                reply->writeInt32(1);
            else
                reply->writeInt32(0);
            return NO_ERROR;
        } break;
        case T_forceArmInstall: {
            CHECK_INTERFACE(IBstFilterAppsService, data, reply);
            String16 packageName = data.readString16();
            bool res = forceArmInstall(packageName);
            reply->writeNoException();
            if (res == true)
                reply->writeInt32(1);
            else
                reply->writeInt32(0);
            return NO_ERROR;
        } break;
        case T_forceX86Install: {
            CHECK_INTERFACE(IBstFilterAppsService, data, reply);
            String16 packageName = data.readString16();
            bool res = forceX86Install(packageName);
            reply->writeNoException();
            if (res == true)
                reply->writeInt32(1);
            else
                reply->writeInt32(0);
            return NO_ERROR;
        } break;
        case T_isWhiteListed: {
            CHECK_INTERFACE(IBstFilterAppsService, data, reply);
            String16 packageName = data.readString16();
            bool res = isWhiteListed(packageName);
            reply->writeNoException();
            if (res == true)
                reply->writeInt32(1);
            else
                reply->writeInt32(0);
            return NO_ERROR;
        } break;
        case T_isBlackListed: {
            CHECK_INTERFACE(IBstFilterAppsService, data, reply);
            String16 packageName = data.readString16();
            String16 version = data.readString16();
            bool res = isBlackListed(packageName, version);
            reply->writeNoException();
            if (res == true)
                reply->writeInt32(1);
            else
                reply->writeInt32(0);
            return NO_ERROR;
        } break;
        case T_isSoftKeyboardRequired: {
            CHECK_INTERFACE(IBstFilterAppsService, data, reply);
            String16 packageName = data.readString16();
            String16 activity = data.readString16();
            bool res = isSoftKeyboardRequired(packageName, activity);
            reply->writeNoException();
            if (res == true)
                reply->writeInt32(1);
            else
                reply->writeInt32(0);
            return NO_ERROR;
        } break;
        case T_getSoftKeyboardModifier: {
            CHECK_INTERFACE(IBstFilterAppsService, data, reply);
            String16 packageName = data.readString16();
            String16 res = getSoftKeyboardModifier(packageName);
            reply->writeNoException();
            reply->writeString16(res);
            return NO_ERROR;
        } break;
        case T_isMarketRequired: {
            CHECK_INTERFACE(IBstFilterAppsService, data, reply);
            String16 packageName = data.readString16();
            bool res = isMarketRequired(packageName);
            reply->writeNoException();
            if (res == true)
                reply->writeInt32(1);
            else
                reply->writeInt32(0);
            return NO_ERROR;
        } break;
        case T_isHeadsetRequired: {
            CHECK_INTERFACE(IBstFilterAppsService, data, reply);
            String16 packageName = data.readString16();
            bool res = isHeadsetRequired(packageName);
            reply->writeNoException();
            if (res == true)
                reply->writeInt32(1);
            else
                reply->writeInt32(0);
            return NO_ERROR;
        } break;
        case T_isPortraitDisabled: {
            CHECK_INTERFACE(IBstFilterAppsService, data, reply);
            String16 packageName = data.readString16();
            bool res = isPortraitDisabled(packageName);
            reply->writeNoException();
            if (res == true)
                reply->writeInt32(1);
            else
                reply->writeInt32(0);
            return NO_ERROR;
        } break;
        case T_getCustomDpi: {
            CHECK_INTERFACE(IBstFilterAppsService, data, reply);
            String16 packageName = data.readString16();
            String16 res = getCustomDpi(packageName);
            reply->writeNoException();
            reply->writeString16(res);
            return NO_ERROR;
        } break;
        case T_isGlv1notimpApp: {
            CHECK_INTERFACE(IBstFilterAppsService, data, reply);
            String16 packageName = data.readString16();
            bool res = isGlv1notimpApp(packageName);
            reply->writeNoException();
            if (res == true)
                reply->writeInt32(1);
            else
                reply->writeInt32(0);
            return NO_ERROR;
        } break;
        case T_isPvrtcApp: {
            CHECK_INTERFACE(IBstFilterAppsService, data, reply);
            String16 packageName = data.readString16();
            bool res = isPvrtcApp(packageName);
            reply->writeNoException();
            if (res == true)
                reply->writeInt32(1);
            else
                reply->writeInt32(0);
            return NO_ERROR;
        } break;
        case T_isS3tcApp: {
            CHECK_INTERFACE(IBstFilterAppsService, data, reply);
            String16 packageName = data.readString16();
            bool res = isS3tcApp(packageName);
            reply->writeNoException();
            if (res == true)
                reply->writeInt32(1);
            else
                reply->writeInt32(0);
            return NO_ERROR;
        } break;
        case T_isXarchApp: {
            CHECK_INTERFACE(IBstFilterAppsService, data, reply);
            int32_t uid = data.readInt32();
            bool res = isXarchApp(uid);
            reply->writeNoException();
            if (res == true)
                reply->writeInt32(1);
            else
                reply->writeInt32(0);
            return NO_ERROR;
        } break;
        case T_isClearInstallApp : {
            CHECK_INTERFACE(IBstFilterAppsService, data, reply);
            String16 packageName = data.readString16();
            bool res = isClearInstallApp(packageName);
            reply->writeNoException();
            if (res == true)
                reply->writeInt32(1);
            else
                reply->writeInt32(0);
            return NO_ERROR;
        } break;
        case T_isScreenOrientationFixed: {
            CHECK_INTERFACE(IBstFilterAppsService, data, reply);
            String16 callingPkgName = data.readString16();
            String16 currentPkgName = data.readString16();
            bool res = isScreenOrientationFixed(callingPkgName,currentPkgName);
            reply->writeNoException();
            if (res == true)
                reply->writeInt32(1);
            else
                reply->writeInt32(0);
            return NO_ERROR;
        } break;
        case T_isCameraRotationRequired: {
            CHECK_INTERFACE(IBstFilterAppsService, data, reply);
            String16 packageName = data.readString16();
            int res = isCameraRotationRequired(packageName);
            reply->writeNoException();
            reply->writeInt32(res);
            return NO_ERROR;
        } break;
        case T_forceLandscapeOrientationIfUnspecified: {
            CHECK_INTERFACE(IBstFilterAppsService, data, reply);
            String16 packageName = data.readString16();
            bool res = forceLandscapeOrientationIfUnspecified(packageName);
            reply->writeNoException();
            if (res == true)
                reply->writeInt32(1);
            else
                reply->writeInt32(0);
            return NO_ERROR;
        } break;
        case T_getGlRenderer: {
            CHECK_INTERFACE(IBstFilterAppsService, data, reply);
            String16 packageName = data.readString16();
            String16 res = getGlRenderer(packageName);
            reply->writeNoException();
            reply->writeString16(res);
            return NO_ERROR;
        } break;
        case T_getGlVendor: {
            CHECK_INTERFACE(IBstFilterAppsService, data, reply);
            String16 packageName = data.readString16();
            String16 res = getGlVendor(packageName);
            reply->writeNoException();
            reply->writeString16(res);
            return NO_ERROR;
        } break;
        case T_isGL3App: {
            CHECK_INTERFACE(IBstFilterAppsService, data, reply);
            String16 packageName = data.readString16();
            bool res = isGL3App(packageName);
            reply->writeNoException();
            if (res == true)
                reply->writeInt32(1);
            else
                reply->writeInt32(0);
            return NO_ERROR;
        } break;
        case T_isLoadLibHackReqd: {
            CHECK_INTERFACE(IBstFilterAppsService, data, reply);
            int32_t uid = data.readInt32();
            String16 res = isLoadLibHackReqd(uid);
            reply->writeNoException();
            reply->writeString16(res);
            return NO_ERROR;
        } break;
        case T_isGL3Disabled: {
            CHECK_INTERFACE(IBstFilterAppsService, data, reply);
            String16 packageName = data.readString16();
            bool res = isGL3Disabled(packageName);
            reply->writeNoException();
            if (res == true)
                reply->writeInt32(1);
            else
                reply->writeInt32(0);
            return NO_ERROR;
        } break;
        case T_isZeroMappedPageReqd: {
            CHECK_INTERFACE(IBstFilterAppsService, data, reply);
            int32_t uid = data.readInt32();
            bool res = isZeroMappedPageReqd(uid);
            reply->writeNoException();
            if (res == true)
                reply->writeInt32(1);
            else
                reply->writeInt32(0);
            return NO_ERROR;
        } break;
        case T_isModifysdPathReqd: {
            CHECK_INTERFACE(IBstFilterAppsService, data, reply);
            String16 packageName = data.readString16();
            bool res = isModifysdPathReqd(packageName);
            reply->writeNoException();
            if (res == true)
                reply->writeInt32(1);
            else
                reply->writeInt32(0);
            return NO_ERROR;
        } break;
        case T_isAGAGL3Disabled: {
            CHECK_INTERFACE(IBstFilterAppsService, data, reply);
            String16 packageName = data.readString16();
            bool res = isAGAGL3Disabled(packageName);
            reply->writeNoException();
            if (res == true)
                reply->writeInt32(1);
            else
                reply->writeInt32(0);
            return NO_ERROR;
        } break;
        case T_isPGAGL3Disabled: {
            CHECK_INTERFACE(IBstFilterAppsService, data, reply);
            String16 packageName = data.readString16();
            bool res = isPGAGL3Disabled(packageName);
            reply->writeNoException();
            if (res == true)
                reply->writeInt32(1);
            else
                reply->writeInt32(0);
            return NO_ERROR;
        } break;
        case T_isShowOrigCpuinfoArmApp: {
            CHECK_INTERFACE(IBstFilterAppsService, data, reply);
            int32_t uid = data.readInt32();
            bool res = isShowOrigCpuinfoArmApp(uid);
            reply->writeNoException();
            if (res == true)
                reply->writeInt32(1);
            else
                reply->writeInt32(0);
            return NO_ERROR;
        } break;
        case T_isAstcApp: {
            CHECK_INTERFACE(IBstFilterAppsService, data, reply);
            String16 packageName = data.readString16();
            bool res = isAstcApp(packageName);
            reply->writeNoException();
            if (res == true)
                reply->writeInt32(1);
            else
                reply->writeInt32(0);
            return NO_ERROR;
        } break;
        case T_isPatchRelocApp: {
            CHECK_INTERFACE(IBstFilterAppsService, data, reply);
            int32_t uid = data.readInt32();
            bool res = isPatchRelocApp(uid);
            reply->writeNoException();
            if (res == true)
                reply->writeInt32(1);
            else
                reply->writeInt32(0);
            return NO_ERROR;
        } break;
        case T_getPgaGlVersion: {
            CHECK_INTERFACE(IBstFilterAppsService, data, reply);
            String16 packageName = data.readString16();
            String16 res = getPgaGlVersion(packageName);
            reply->writeNoException();
            reply->writeString16(res);
            return NO_ERROR;
        } break;
        case T_getAgaGlVersion : {
            CHECK_INTERFACE(IBstFilterAppsService, data, reply);
            String16 packageName = data.readString16();
            String16 res = getAgaGlVersion(packageName);
            reply->writeNoException();
            reply->writeString16(res);
            return NO_ERROR;
        } break;
        case T_isHardwareAstcDisabledApp : {
            CHECK_INTERFACE(IBstFilterAppsService, data, reply);
            String16 packageName = data.readString16();
            bool res = isHardwareAstcDisabledApp(packageName);
            reply->writeNoException();
            if (res == true)
                reply->writeInt32(1);
            else
                reply->writeInt32(0);
            return NO_ERROR;
        } break;
        case T_isXArmApp: {
            CHECK_INTERFACE(IBstFilterAppsService, data, reply);
            String16 packageName = data.readString16();
            bool res = isXArmApp(packageName);
            reply->writeNoException();
            if (res == true)
                reply->writeInt32(1);
            else
                reply->writeInt32(0);
            return NO_ERROR;
        } break;
        case T_getMemorySize:  {
            CHECK_INTERFACE(IBstFilterAppsService, data, reply);
            int32_t uid = data.readInt32();
            String16 res = getMemorySize(uid);
            reply->writeNoException();
            reply->writeString16(res);
            return NO_ERROR;
        } break;
        case T_isAppUsingOldHoudini: {
            CHECK_INTERFACE(IBstFilterAppsService, data, reply);
            int32_t uid = data.readInt32();
            bool res = isAppUsingOldHoudini(uid);
            reply->writeNoException();
            if (res == true)
                reply->writeInt32(1);
            else
                reply->writeInt32(0);
            return NO_ERROR;
        } break;
        case T_getAdditionalGlExtensions: {
            CHECK_INTERFACE(IBstFilterAppsService, data, reply);
            String16 packageName = data.readString16();
            String16 res = getAdditionalGlExtensions(packageName);
            reply->writeNoException();
            reply->writeString16(res);
            return NO_ERROR;
        } break;
        case T_areInputDevicesExposed: {
            CHECK_INTERFACE(IBstFilterAppsService, data, reply);
            String16 packageName = data.readString16();
            bool res = areInputDevicesExposed(packageName);
            reply->writeNoException();
            if (res == true)
                reply->writeInt32(1);
            else
                reply->writeInt32(0);
            return NO_ERROR;
        } break;
        case T_isShowArmAbiListApp: {
            CHECK_INTERFACE(IBstFilterAppsService, data, reply);
            int32_t uid = data.readInt32();
            bool res = isShowArmAbiListApp(uid);
            reply->writeNoException();
            if (res == true)
                reply->writeInt32(1);
            else
                reply->writeInt32(0);
            return NO_ERROR;
        } break;
        case T_isIgnoreLargeHeapApp: {
            CHECK_INTERFACE(IBstFilterAppsService, data, reply);
            String16 packageName = data.readString16();
            bool res = isIgnoreLargeHeapApp(packageName);
            reply->writeNoException();
            if (res == true)
                reply->writeInt32(1);
            else
                reply->writeInt32(0);
            return NO_ERROR;
        } break;
        case T_isClearCodeCacheApp: {
            CHECK_INTERFACE(IBstFilterAppsService, data, reply);
            int32_t uid = data.readInt32();
            bool res = isClearCodeCacheApp(uid);
            reply->writeNoException();
            if (res == true)
                reply->writeInt32(1);
            else
                reply->writeInt32(0);
            return NO_ERROR;
        } break;
        case T_isImageDetectionEnabled: {
            CHECK_INTERFACE(IBstFilterAppsService, data, reply);
            String16 packageName = data.readString16();
            bool res = isImageDetectionEnabled(packageName);
            reply->writeNoException();
            if (res == true)
                reply->writeInt32(1);
            else
                reply->writeInt32(0);
            return NO_ERROR;
        } break;
        case T_getHeapGrowthLimitSize: {
            CHECK_INTERFACE(IBstFilterAppsService, data, reply);
            String16 packageName = data.readString16();
            int res = getHeapGrowthLimitSize(packageName);
            reply->writeNoException();
            reply->writeInt32(res);
            return NO_ERROR;
        } break;
        case T_isHideProcMapsApp: {
            CHECK_INTERFACE(IBstFilterAppsService, data, reply);
            String16 packageName = data.readString16();
            bool res = isHideProcMapsApp(packageName);
            reply->writeNoException();
            if (res == true)
                reply->writeInt32(1);
            else
                reply->writeInt32(0);
            return NO_ERROR;
        } break;
        case T_isEnableNativeGamePad: {
            CHECK_INTERFACE(IBstFilterAppsService, data, reply);
            String16 packageName = data.readString16();
            bool res = isEnableNativeGamePad(packageName);
            reply->writeNoException();
            if (res == true)
                reply->writeInt32(1);
            else
                reply->writeInt32(0);
            return NO_ERROR;
        } break;
        case T_isPreloadBstHookLibraryApp: {
            CHECK_INTERFACE(IBstFilterAppsService, data, reply);
            String16 packageName = data.readString16();
            bool res = isPreloadBstHookLibraryApp(packageName);
            reply->writeNoException();
            if (res == true)
                reply->writeInt32(1);
            else
                reply->writeInt32(0);
            return NO_ERROR;
        } break;

        case T_isIl2cppApp: {
            CHECK_INTERFACE(IBstFilterAppsService, data, reply);
            int32_t uid = data.readInt32();
            bool res = isIl2cppApp(uid);
            reply->writeNoException();
            if (res == true)
                reply->writeInt32(1);
            else
                reply->writeInt32(0);
            return NO_ERROR;
        } break;

        case T_updateIl2cppPkgs: {
            CHECK_INTERFACE(IBstFilterAppsService, data, reply);
            String16 packageName = data.readString16();
            updateIl2cppPkgs(packageName);
            reply->writeNoException();
            return NO_ERROR;
        } break;

        case T_isSuppressedNotificationApp: {
            CHECK_INTERFACE(IBstFilterAppsService, data, reply);
            String16 packageName = data.readString16();
            bool res = isSuppressedNotificationApp(packageName);
            reply->writeNoException();
            if (res == true)
                reply->writeInt32(1);
            else
                reply->writeInt32(0);
            return NO_ERROR;
        } break;

        case T_isMacrosDisabledApp: {
            CHECK_INTERFACE(IBstFilterAppsService, data, reply);
            String16 packageName = data.readString16();
            bool res = isMacrosDisabledApp(packageName);
            reply->writeNoException();
            if (res == true)
                reply->writeInt32(1);
            else
                reply->writeInt32(0);
            return NO_ERROR;
        } break;

        case T_showFeedbackPopup: {
            CHECK_INTERFACE(IBstFilterAppsService, data, reply);
            String16 packageName = data.readString16();
            bool res = showFeedbackPopup(packageName);
            reply->writeNoException();
            if (res == true)
                reply->writeInt32(1);
            else
                reply->writeInt32(0);
            return NO_ERROR;
        } break;

        case T_ffmpegConfidenceForApp: {
            CHECK_INTERFACE(IBstFilterAppsService, data, reply);
            String16 packageName = data.readString16();
            float res = ffmpegConfidenceForApp(packageName);
            reply->writeNoException();
            reply->writeFloat(res);
            return NO_ERROR;
        } break;

        case T_isAppUsingSwappy: {
            CHECK_INTERFACE(IBstFilterAppsService, data, reply);
            int32_t uid = data.readInt32();
            bool res = isAppUsingSwappy(uid);
            reply->writeNoException();
            if (res == true)
                reply->writeInt32(1);
            else
                reply->writeInt32(0);
            return NO_ERROR;
        } break;

        case T_getMouseCursorStyle: {
            CHECK_INTERFACE(IBstFilterAppsService, data, reply);
            String16 packageName = data.readString16();
            String16 res = getMouseCursorStyle(packageName);
            reply->writeNoException();
            reply->writeString16(res);
            return NO_ERROR;
        } break;

        case T_getCameraSensorRotation: {
            CHECK_INTERFACE(IBstFilterAppsService, data, reply);
            String16 packageName = data.readString16();
            int res = getCameraSensorRotation(packageName);
            reply->writeNoException();
            reply->writeInt32(res);
            return NO_ERROR;
        } break;

        case T_getCameraInitRotation: {
            CHECK_INTERFACE(IBstFilterAppsService, data, reply);
            String16 packageName = data.readString16();
            int res = getCameraInitRotation(packageName);
            reply->writeNoException();
            reply->writeInt32(res);
            return NO_ERROR;
        } break;

        case T_isUE4GLFlushApp: {
            CHECK_INTERFACE(IBstFilterAppsService, data, reply);
            String16 packageName = data.readString16();
            bool res = isUE4GLFlushApp(packageName);
            reply->writeNoException();
            if (res == true)
                reply->writeInt32(1);
            else
                reply->writeInt32(0);
            return NO_ERROR;
        } break;
        case T_isGetNowggAccountsListApp: {
            CHECK_INTERFACE(IBstFilterAppsService, data, reply);
            int32_t uid = data.readInt32();
            bool res = isGetNowggAccountsListApp(uid);
            reply->writeNoException();
            if (res == true)
                reply->writeInt32(1);
            else
                reply->writeInt32(0);
            return NO_ERROR;
        } break;

        case T_isGoogleSignInRequired: {
            CHECK_INTERFACE(IBstFilterAppsService, data, reply);
            String16 packageName = data.readString16();
            bool res = isGoogleSignInRequired(packageName);
            reply->writeNoException();
            if (res == true)
                reply->writeInt32(1);
            else
                reply->writeInt32(0);
            return NO_ERROR;
        } break;

        case T_isVulkanRequired: {
            CHECK_INTERFACE(IBstFilterAppsService, data, reply);
                String16 packageName = data.readString16();
                String16 res = isVulkanRequired(packageName);
                reply->writeNoException();
                reply->writeString16(res);
                return NO_ERROR;
            } break;

        case T_isForceKillApp: {
            CHECK_INTERFACE(IBstFilterAppsService, data, reply);
            String16 packageName = data.readString16();
            bool res = isForceKillApp(packageName);
            reply->writeNoException();
            reply->writeInt32(res ? 1 : 0);
            return NO_ERROR;
        } break;

        case T_isFixedDisplayRotationApp: {
            CHECK_INTERFACE(IBstFilterAppsService, data, reply);
            String16 packageName = data.readString16();
            bool res = isFixedDisplayRotationApp(packageName);
            reply->writeNoException();
            reply->writeInt32(res ? 1 : 0);
            return NO_ERROR;
        } break;

        case T_getGameDefaultSetting: {
            CHECK_INTERFACE(IBstFilterAppsService, data, reply);
            String16 packageName = data.readString16();
            String16 res = getGameDefaultSetting(packageName);
            reply->writeNoException();
            reply->writeString16(res);
            return NO_ERROR;
        } break;

        case T_isHppEnabled: {
            CHECK_INTERFACE(IBstFilterAppsService, data, reply);
            String16 packageName = data.readString16();
            bool res = isHppEnabled(packageName);
            reply->writeNoException();
            if (res == true)
                reply->writeInt32(1);
            else
                reply->writeInt32(0);
            return NO_ERROR;
        } break;

        case T_isHotFixApp: {
             CHECK_INTERFACE(IBstFilterAppsService, data, reply);
            String16 packageName = data.readString16();
            bool res = isHotFixApp(packageName);
            reply->writeNoException();
            if (res == true)
                reply->writeInt32(1);
            else
                reply->writeInt32(0);
            return NO_ERROR;
        } break;

        case T_isGLInvalidateFramebufferFilterApp: {
            CHECK_INTERFACE(IBstFilterAppsService, data, reply);
            String16 packageName = data.readString16();
            bool res = isGLInvalidateFramebufferFilterApp(packageName);
            reply->writeNoException();
            if (res == true)
                reply->writeInt32(1);
            else
                reply->writeInt32(0);
            return NO_ERROR;
        } break;

        case T_getUnityFlickerPatchRequired: {
            CHECK_INTERFACE(IBstFilterAppsService, data, reply);
            String16 packageName = data.readString16();
            int res = getUnityFlickerPatchRequired(packageName);
            reply->writeNoException();
            reply->writeInt32(res);
            return NO_ERROR;
        } break;
        case T_getDefaultProfile: {
            CHECK_INTERFACE(IBstFilterAppsService, data, reply);
            String16 packageName = data.readString16();
            String16 res = getDefaultProfile(packageName);
            reply->writeNoException();
            reply->writeString16(res);
            return NO_ERROR;
        } break;
        case T_getXperfMode: {
            CHECK_INTERFACE(IBstFilterAppsService, data, reply);
            int32_t uid = data.readInt32();
            int res = getXperfMode(uid);
            reply->writeNoException();
            reply->writeInt32(res);
            return NO_ERROR;
        } break;
        case T_isIntelGLDispatchComputeFlushApp: {
            CHECK_INTERFACE(IBstFilterAppsService, data, reply);
            String16 packageName = data.readString16();
            bool res = isIntelGLDispatchComputeFlushApp(packageName);
            reply->writeNoException();
            if (res == true)
                reply->writeInt32(1);
            else
                reply->writeInt32(0);
            return NO_ERROR;
        } break;
            case T_isDhdg: {
                CHECK_INTERFACE(IBstFilterAppsService, data, reply);
                int32_t uid = data.readInt32();
                bool res = isDhdg(uid);
                reply->writeNoException();
                if (res == true)
                    reply->writeInt32(1);
                else
                    reply->writeInt32(0);
                return NO_ERROR;
            } break;
            case T_isGlNativeSyncDisabled: {
                CHECK_INTERFACE(IBstFilterAppsService, data, reply);
                String16 packageName = data.readString16();
                bool res = isGlNativeSyncDisabled(packageName);
                reply->writeNoException();
                if (res == true)
                    reply->writeInt32(1);
                else
                    reply->writeInt32(0);
                return NO_ERROR;
            } break;
            case T_isAngleDisabled: {
                CHECK_INTERFACE(IBstFilterAppsService, data, reply);
                String16 packageName = data.readString16();
                bool res = isAngleDisabled(packageName);
                reply->writeNoException();
                if (res == true)
                    reply->writeInt32(1);
                else
                    reply->writeInt32(0);
                return NO_ERROR;
            } break;
            case T_isFbScreenLockApp: {
                CHECK_INTERFACE(IBstFilterAppsService, data, reply);
                String16 packageName = data.readString16();
                bool res = isFbScreenLockApp(packageName);
                reply->writeNoException();
                if (res == true)
                    reply->writeInt32(1);
                else
                    reply->writeInt32(0);
                return NO_ERROR;
            } break;
            case T_isOneStorePay: {
                CHECK_INTERFACE(IBstFilterAppsService, data, reply);
                String16 packageName = data.readString16();
                bool res = isOneStorePay(packageName);
                reply->writeNoException();
                if (res == true)
                    reply->writeInt32(1);
                else
                    reply->writeInt32(0);
                return NO_ERROR;
            } break;
            case T_isGLProgramBinaryApp: {
                CHECK_INTERFACE(IBstFilterAppsService, data, reply);
                String16 packageName = data.readString16();
                bool res = isGLProgramBinaryApp(packageName);
                reply->writeNoException();
                if (res == true)
                    reply->writeInt32(1);
                else
                    reply->writeInt32(0);
                return NO_ERROR;
            } break;
            case T_isGLUnmapBufferPerfApp: {
                CHECK_INTERFACE(IBstFilterAppsService, data, reply);
                String16 packageName = data.readString16();
                bool res = isGLUnmapBufferPerfApp(packageName);
                reply->writeNoException();
                if (res == true)
                    reply->writeInt32(1);
                else
                    reply->writeInt32(0);
                return NO_ERROR;
            } break;
            case T_getGLShaderWorkaround: {
                CHECK_INTERFACE(IBstFilterAppsService, data, reply);
                String16 packageName = data.readString16();
                String16 res = getGLShaderWorkaround(packageName);
                reply->writeNoException();
                reply->writeString16(res);
                return NO_ERROR;
            } break;
            case T_isDrmEnabled: {
                CHECK_INTERFACE(IBstFilterAppsService, data, reply);
                String16 packageName = data.readString16();
                bool res = isDrmEnabled(packageName);
                reply->writeNoException();
                if (res == true)
                    reply->writeInt32(1);
                else
                    reply->writeInt32(0);
                return NO_ERROR;
            } break;
            case T_isTexTargetCheckDisabled: {
                CHECK_INTERFACE(IBstFilterAppsService, data, reply);
                String16 packageName = data.readString16();
                bool res = isTexTargetCheckDisabled(packageName);
                reply->writeNoException();
                if (res == true)
                    reply->writeInt32(1);
                else
                    reply->writeInt32(0);
                return NO_ERROR;
            } break;
            case T_getFixedSurfaceRotationRequired: {
                CHECK_INTERFACE(IBstFilterAppsService, data, reply);
                String16 packageName = data.readString16();
                int res = getFixedSurfaceRotationRequired(packageName);
                reply->writeNoException();
                reply->writeInt32(res);
                return NO_ERROR;
            } break;
            case T_getIapSetting: {
                CHECK_INTERFACE(IBstFilterAppsService, data, reply);
                String16 packageName = data.readString16();
                String16 res = getIapSetting(packageName);
                reply->writeNoException();
                reply->writeString16(res);
                return NO_ERROR;
            } break;
            case T_isGlMapBufferRangeHost: {
                CHECK_INTERFACE(IBstFilterAppsService, data, reply);
                String16 packageName = data.readString16();
                bool res = isGlMapBufferRangeHost(packageName);
                reply->writeNoException();
                if (res == true)
                    reply->writeInt32(1);
                else
                    reply->writeInt32(0);
                return NO_ERROR;
            } break;
            case T_isIgnoreSyncTimeout: {
                CHECK_INTERFACE(IBstFilterAppsService, data, reply);
                String16 packageName = data.readString16();
                bool res = isIgnoreSyncTimeout(packageName);
                reply->writeNoException();
                if (res == true)
                    reply->writeInt32(1);
                else
                    reply->writeInt32(0);
                return NO_ERROR;
            } break;
            case T_isGLVBOCacheDisableApp: {
                CHECK_INTERFACE(IBstFilterAppsService, data, reply);
                String16 packageName = data.readString16();
                bool res = isGLVBOCacheDisableApp(packageName);
                reply->writeNoException();
                if (res == true)
                    reply->writeInt32(1);
                else
                    reply->writeInt32(0);
                return NO_ERROR;
            } break;
            case T_isBlockEditWhenComposing: {
                CHECK_INTERFACE(IBstFilterAppsService, data, reply);
                String16 packageName = data.readString16();
                bool res = isBlockEditWhenComposing(packageName);
                reply->writeNoException();
                if (res == true)
                    reply->writeInt32(1);
                else
                    reply->writeInt32(0);
                return NO_ERROR;
            } break;
            case T_getGLHostInfo: {
                CHECK_INTERFACE(IBstFilterAppsService, data, reply);
                String16 packageName = data.readString16();
                String16 res = getGLHostInfo(packageName);
                reply->writeNoException();
                reply->writeString16(res);
                return NO_ERROR;
            } break;
            case T_getGLExtensionsIgnore: {
                CHECK_INTERFACE(IBstFilterAppsService, data, reply);
                String16 packageName = data.readString16();
                String16 res = getGLExtensionsIgnore(packageName);
                reply->writeNoException();
                reply->writeString16(res);
                return NO_ERROR;
            } break;
            case T_getVkHostInfo: {
                CHECK_INTERFACE(IBstFilterAppsService, data, reply);
                String16 packageName = data.readString16();
                String16 res = getVkHostInfo(packageName);
                reply->writeNoException();
                reply->writeString16(res);
                return NO_ERROR;
            } break;
            case T_getVKDeviceExtIgnore: {
                CHECK_INTERFACE(IBstFilterAppsService, data, reply);
                String16 packageName = data.readString16();
                String16 res = getVKDeviceExtIgnore(packageName);
                reply->writeNoException();
                reply->writeString16(res);
                return NO_ERROR;
            } break;
            case T_isEGLSurfaceIgnore: {
                CHECK_INTERFACE(IBstFilterAppsService, data, reply);
                String16 packageName = data.readString16();
                bool res = isEGLSurfaceIgnore(packageName);
                reply->writeNoException();
                if (res == true)
                    reply->writeInt32(1);
                else
                    reply->writeInt32(0);
                return NO_ERROR;
            } break;
            case T_isHardKeyBoard: {
                CHECK_INTERFACE(IBstFilterAppsService, data, reply);
                String16 packageName = data.readString16();
                bool res = isHardKeyBoard(packageName);
                reply->writeNoException();
                if (res == true)
                    reply->writeInt32(1);
                else
                    reply->writeInt32(0);
                return NO_ERROR;
            } break;
            case T_isIntelAutoGLFlushApp: {
                CHECK_INTERFACE(IBstFilterAppsService, data, reply);
                String16 packageName = data.readString16();
                bool res = isIntelAutoGLFlushApp(packageName);
                reply->writeNoException();
                if (res == true)
                    reply->writeInt32(1);
                else
                    reply->writeInt32(0);
                return NO_ERROR;
            } break;
            case T_isRotateDisabled: {
                CHECK_INTERFACE(IBstFilterAppsService, data, reply);
                String16 packageName = data.readString16();
                bool res = isRotateDisabled(packageName);
                reply->writeNoException();
                if (res == true)
                    reply->writeInt32(1);
                else
                    reply->writeInt32(0);
                return NO_ERROR;
            } break;
            case T_isUnreal5App: {
                CHECK_INTERFACE(IBstFilterAppsService, data, reply);
                String16 packageName = data.readString16();
                bool res = isUnreal5App(packageName);
                reply->writeNoException();
                if (res == true)
                    reply->writeInt32(1);
                else
                    reply->writeInt32(0);
                return NO_ERROR;
            } break;
            case T_isUE5PBDisabled: {
                CHECK_INTERFACE(IBstFilterAppsService, data, reply);
                String16 packageName = data.readString16();
                bool res = isUE5PBDisabled(packageName);
                reply->writeNoException();
                if (res == true)
                    reply->writeInt32(1);
                else
                    reply->writeInt32(0);
                return NO_ERROR;
            } break;
            case T_isBptcApp: {
                CHECK_INTERFACE(IBstFilterAppsService, data, reply);
                String16 packageName = data.readString16();
                bool res = isBptcApp(packageName);
                reply->writeNoException();
                if (res == true)
                    reply->writeInt32(1);
                else
                    reply->writeInt32(0);
                return NO_ERROR;
            } break;
            case T_isExtractNativeLibs: {
                CHECK_INTERFACE(IBstFilterAppsService, data, reply);
                String16 packageName = data.readString16();
                bool res = isExtractNativeLibs(packageName);
                reply->writeNoException();
                if (res == true)
                    reply->writeInt32(1);
                else
                    reply->writeInt32(0);
                return NO_ERROR;
            } break;
            case T_isEtherNetType: {
                CHECK_INTERFACE(IBstFilterAppsService, data, reply);
                String16 packageName = data.readString16();
                bool res = isEtherNetType(packageName);
                reply->writeNoException();
                if (res == true)
                    reply->writeInt32(1);
                else
                    reply->writeInt32(0);
                return NO_ERROR;
            } break;
            case T_isDefaultXYDpi: {
                CHECK_INTERFACE(IBstFilterAppsService, data, reply);
                String16 packageName = data.readString16();
                bool res = isDefaultXYDpi(packageName);
                reply->writeNoException();
                if (res == true)
                    reply->writeInt32(1);
                else
                    reply->writeInt32(0);
                return NO_ERROR;
            } break;
            case T_getPScoreAbove: {
                CHECK_INTERFACE(IBstFilterAppsService, data, reply);
                String16 packageName = data.readString16();
                int res = getPScoreAbove(packageName);
                reply->writeNoException();
                reply->writeInt32(res);
                return NO_ERROR;
            } break;
            case T_isMapBufRangeReadOnceEnabled: {
                CHECK_INTERFACE(IBstFilterAppsService, data, reply);
                String16 packageName = data.readString16();
                bool res = isMapBufRangeReadOnceEnabled(packageName);
                reply->writeNoException();
                if (res == true)
                    reply->writeInt32(1);
                else
                    reply->writeInt32(0);
                return NO_ERROR;
            } break;
            case T_isFbCompleteCheckDisabled: {
                CHECK_INTERFACE(IBstFilterAppsService, data, reply);
                String16 packageName = data.readString16();
                bool res = isFbCompleteCheckDisabled(packageName);
                reply->writeNoException();
                if (res == true)
                    reply->writeInt32(1);
                else
                    reply->writeInt32(0);
                return NO_ERROR;
            } break;
      default:
            return BBinder::onTransact(code, data, reply, flags);
    }
}

// ----------------------------------------------------------------------

} // namespace android

#endif // __ANDROID_VENDOR__
