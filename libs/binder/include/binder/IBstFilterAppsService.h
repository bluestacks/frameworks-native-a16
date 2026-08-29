#pragma once

#include <binder/Common.h>
#include <binder/IInterface.h>
#include <utils/String16.h>

namespace android {

    // ----------------------------------------------------------------------

    class LIBBINDER_EXPORTED IBstFilterAppsService : public IInterface
    {
        public:
            DECLARE_META_INTERFACE(BstFilterAppsService)

            virtual bool isSmallScreenApp(const String16& packageName) = 0;
            virtual bool forceArmInstall(const String16& packageName) = 0;
            virtual bool forceX86Install(const String16& packageName) = 0;
            virtual bool isWhiteListed(const String16& packageName) = 0;
            virtual bool isBlackListed(const String16& packageName, const String16& version) = 0;
            virtual bool isSoftKeyboardRequired(const String16& packageName, const String16& activity) = 0;
            virtual const String16 getSoftKeyboardModifier(const String16& packageName) = 0;
            virtual bool isMarketRequired(const String16& packageName) = 0;
            virtual bool isHeadsetRequired(const String16& packageName) = 0;
            virtual bool isPortraitDisabled(const String16& packageName) = 0;
            virtual const String16 getCustomDpi(const String16& packageName) = 0;
            virtual bool isGlv1notimpApp(const String16& packageName) = 0;
            virtual bool isPvrtcApp(const String16& packageName) = 0;
            virtual bool isXarchApp(const int32_t uid) = 0;
            virtual bool isS3tcApp(const String16& packageName) = 0;
            virtual bool isClearInstallApp(const String16& packageName) = 0;
            virtual bool isScreenOrientationFixed(const String16& callingPkgName,const String16& currentPkgName) = 0;
            virtual int  isCameraRotationRequired(const String16& packageName) = 0;
            virtual bool forceLandscapeOrientationIfUnspecified(const String16& callingPkgName) = 0;
            virtual const String16 getGlRenderer(const String16& packageName) = 0;
            virtual const String16 getGlVendor(const String16& packageName) = 0;
            virtual bool isGL3App(const String16& packageName) = 0;
            virtual const String16 isLoadLibHackReqd(const int32_t uid) = 0;
            virtual bool isGL3Disabled(const String16& packageName) = 0;
            virtual bool isZeroMappedPageReqd(const int32_t uid) = 0;
            virtual bool isModifysdPathReqd(const String16& packageName) = 0;
            virtual bool isAGAGL3Disabled(const String16& packageName) = 0;
            virtual bool isPGAGL3Disabled(const String16& packageName) = 0;
            virtual bool isShowOrigCpuinfoArmApp(const int32_t uid) = 0;
            virtual bool isAstcApp(const String16& packageName) = 0;
            virtual bool isPatchRelocApp(const int32_t uid) = 0;
            virtual const String16 getPgaGlVersion(const String16& packageName) = 0;
            virtual const String16 getAgaGlVersion(const String16& packageName) = 0;
            virtual bool isHardwareAstcDisabledApp(const String16& packageName) = 0;
            virtual bool isXArmApp(const String16& packageName) = 0;
            virtual const String16 getMemorySize(const int32_t uid) = 0;
            virtual bool isAppUsingOldHoudini(const int32_t uid) = 0;
            virtual const String16 getAdditionalGlExtensions(const String16& packageName) = 0;
            virtual bool areInputDevicesExposed(const String16& packageName) = 0;
            virtual bool isShowArmAbiListApp(const int32_t uid) = 0;
            virtual bool isIgnoreLargeHeapApp(const String16& packageName) = 0;
            virtual bool isClearCodeCacheApp(const int32_t uid) = 0;
            virtual bool isImageDetectionEnabled(const String16& packageName) = 0;
            virtual int  getHeapGrowthLimitSize(const String16& packageName) = 0;
            virtual bool isHideProcMapsApp(const String16& packageName) = 0;
            virtual bool isEnableNativeGamePad(const String16& packageName) = 0;
            virtual bool isPreloadBstHookLibraryApp(const String16& packageName) = 0;
            virtual bool isIl2cppApp(const int32_t uid) = 0;
            virtual void updateIl2cppPkgs(const String16& packageName) = 0;
            virtual bool isSuppressedNotificationApp(const String16& packageName) = 0;
            virtual bool isMacrosDisabledApp(const String16& packageName) = 0;
            virtual bool showFeedbackPopup(const String16& packageName) = 0;
            virtual float ffmpegConfidenceForApp(const String16& packageName) = 0;
            virtual bool isAppUsingSwappy(const int32_t uid) = 0;
            virtual const String16 getMouseCursorStyle(const String16& packageName) = 0;
            virtual int  getCameraSensorRotation(const String16& packageName) = 0;
            virtual int  getCameraInitRotation(const String16& packageName) = 0;
            virtual bool isUE4GLFlushApp(const String16& packageName) = 0;
            virtual bool isGetNowggAccountsListApp(const int32_t uid) = 0;
            virtual bool isGoogleSignInRequired(const String16& packageName) = 0;
            virtual const String16 isVulkanRequired(const String16& packageName) = 0;
            virtual bool isForceKillApp(const String16& packageName) = 0;
            virtual bool isFixedDisplayRotationApp(const String16& packageName) = 0;
            virtual const String16 getGameDefaultSetting(const String16& packageName) = 0;
            virtual bool isHppEnabled(const String16& packageName) = 0;
            virtual bool isHotFixApp(const String16& packageName) = 0;
            virtual bool isGLInvalidateFramebufferFilterApp(const String16& packageName) = 0;
            virtual int  getUnityFlickerPatchRequired(const String16& packageName) = 0;
            virtual const String16 getDefaultProfile(const String16& packageName) = 0;
            virtual int getXperfMode(const int32_t uid) = 0;
            virtual bool isIntelGLDispatchComputeFlushApp(const String16& packageName) = 0;
            virtual bool isDhdg(const int32_t uid) = 0;
            virtual bool isGlNativeSyncDisabled(const String16& packageName) = 0;
            virtual bool isAngleDisabled(const String16& packageName) = 0;
            virtual bool isFbScreenLockApp(const String16& packageName) = 0;
            virtual bool isOneStorePay(const String16& packageName) = 0;
            virtual bool isGLProgramBinaryApp(const String16& packageName) = 0;
            virtual bool isGLUnmapBufferPerfApp(const String16& packageName) = 0;
            virtual const String16 getGLShaderWorkaround(const String16& packageName) = 0;
            virtual bool isDrmEnabled(const String16& packageName) = 0;
            virtual bool isEtherNetType(const String16& packageName) = 0;
            virtual bool isTexTargetCheckDisabled(const String16& packageName) = 0;
            virtual int  getFixedSurfaceRotationRequired(const String16& packageName) = 0;
            virtual const String16 getIapSetting(const String16& packageName) = 0;
            virtual bool isGlMapBufferRangeHost(const String16& packageName) = 0;
            virtual bool isIgnoreSyncTimeout(const String16& packageName) = 0;
            virtual bool isGLVBOCacheDisableApp(const String16& packageName) = 0;
            virtual bool isBlockEditWhenComposing(const String16& packageName) = 0;
            virtual const String16 getGLHostInfo(const String16& packageName) = 0;
            virtual const String16 getGLExtensionsIgnore(const String16& packageName) = 0;
            virtual const String16 getVkHostInfo(const String16& packageName) = 0;
            virtual const String16 getVKDeviceExtIgnore(const String16& packageName) = 0;
            virtual bool isEGLSurfaceIgnore(const String16& packageName) = 0;
            virtual bool isHardKeyBoard(const String16& packageName) = 0;
            virtual bool isIntelAutoGLFlushApp(const String16& packageName) = 0;
            virtual bool isRotateDisabled(const String16& packageName) = 0;
            virtual bool isUnreal5App(const String16& packageName) = 0;
            virtual bool isUE5PBDisabled(const String16& packageName) = 0;
            virtual bool isBptcApp(const String16& packageName) = 0;
            virtual bool isExtractNativeLibs(const String16& packageName) = 0;
            virtual bool isDefaultXYDpi(const String16& packageName) = 0;
            virtual int getPScoreAbove(const String16& packageName) = 0;
            virtual bool isMapBufRangeReadOnceEnabled(const String16& pkgName) = 0;
            virtual bool isFbCompleteCheckDisabled(const String16& packageName) = 0;
            virtual bool isUEEGLCrashFixApp(const String16& packageName) = 0;

            /**
             * These should be in sync with the ordering in services's Aidl.
             * Here, it directly relates with IBstFilterAppsServices.aidl.
             * If not in sync, these remote calls may call different functions than intended.
             */
            enum {

                T_isSmallScreenApp = IBinder::FIRST_CALL_TRANSACTION + 0,
                T_forceArmInstall = IBinder::FIRST_CALL_TRANSACTION + 1,
                T_forceX86Install = IBinder::FIRST_CALL_TRANSACTION + 2,
                T_isWhiteListed = IBinder::FIRST_CALL_TRANSACTION + 3,
                T_isBlackListed = IBinder::FIRST_CALL_TRANSACTION + 4,
                T_isSoftKeyboardRequired = IBinder::FIRST_CALL_TRANSACTION + 5,
                T_getSoftKeyboardModifier = IBinder::FIRST_CALL_TRANSACTION + 6,
                T_isMarketRequired = IBinder::FIRST_CALL_TRANSACTION + 7,
                T_isHeadsetRequired = IBinder::FIRST_CALL_TRANSACTION + 8,
                T_isPortraitDisabled = IBinder::FIRST_CALL_TRANSACTION + 9,
                T_getCustomDpi = IBinder::FIRST_CALL_TRANSACTION + 10,
                T_isGlv1notimpApp = IBinder::FIRST_CALL_TRANSACTION + 11,
                T_isPvrtcApp = IBinder::FIRST_CALL_TRANSACTION + 12,
                T_isXarchApp = IBinder::FIRST_CALL_TRANSACTION + 13,
                T_isS3tcApp = IBinder::FIRST_CALL_TRANSACTION + 14,
                T_isClearInstallApp = IBinder::FIRST_CALL_TRANSACTION + 15,
                T_isScreenOrientationFixed = IBinder::FIRST_CALL_TRANSACTION + 16,
                T_isCameraRotationRequired = IBinder::FIRST_CALL_TRANSACTION + 17,
                T_forceLandscapeOrientationIfUnspecified = IBinder::FIRST_CALL_TRANSACTION + 18,
                T_getGlRenderer = IBinder::FIRST_CALL_TRANSACTION + 19,
                T_getGlVendor = IBinder::FIRST_CALL_TRANSACTION + 20,
                T_isGL3App = IBinder::FIRST_CALL_TRANSACTION + 21,
                T_isLoadLibHackReqd = IBinder::FIRST_CALL_TRANSACTION + 22,
                T_isGL3Disabled = IBinder::FIRST_CALL_TRANSACTION + 23,
                T_isZeroMappedPageReqd = IBinder::FIRST_CALL_TRANSACTION + 24,
                T_isModifysdPathReqd = IBinder::FIRST_CALL_TRANSACTION + 25,
                T_isAGAGL3Disabled = IBinder::FIRST_CALL_TRANSACTION + 26,
                T_isPGAGL3Disabled = IBinder::FIRST_CALL_TRANSACTION + 27,
                T_isShowOrigCpuinfoArmApp = IBinder::FIRST_CALL_TRANSACTION + 28,
                T_isAstcApp = IBinder::FIRST_CALL_TRANSACTION + 29,
                T_isPatchRelocApp = IBinder::FIRST_CALL_TRANSACTION + 30,
                T_getPgaGlVersion = IBinder::FIRST_CALL_TRANSACTION + 31,
                T_getAgaGlVersion = IBinder::FIRST_CALL_TRANSACTION + 32,
                T_isHardwareAstcDisabledApp = IBinder::FIRST_CALL_TRANSACTION + 33,
                T_isXArmApp = IBinder::FIRST_CALL_TRANSACTION + 34,
                T_getMemorySize = IBinder::FIRST_CALL_TRANSACTION + 35,
                T_isIMEDisabled = IBinder::FIRST_CALL_TRANSACTION + 36,
                T_isForceVibrate = IBinder::FIRST_CALL_TRANSACTION + 37,
                T_isHideBstActivityInfo = IBinder::FIRST_CALL_TRANSACTION + 38,
                T_isArmApp = IBinder::FIRST_CALL_TRANSACTION + 39,
                T_isXCpuAbi = IBinder::FIRST_CALL_TRANSACTION + 40,
                T_isModifyDisplayRotationApp = IBinder::FIRST_CALL_TRANSACTION + 41,
                T_isBluestacksPartnerApp = IBinder::FIRST_CALL_TRANSACTION + 42,
                T_getAccelerometerSetting = IBinder::FIRST_CALL_TRANSACTION + 43,
                T_getAccelerometerList = IBinder::FIRST_CALL_TRANSACTION + 44,
                T_getHeadSetList = IBinder::FIRST_CALL_TRANSACTION + 45,
                T_getInstallerPkg = IBinder::FIRST_CALL_TRANSACTION + 46,
                T_getBrowserUrl = IBinder::FIRST_CALL_TRANSACTION + 47,
                T_updateAbiEntry = IBinder::FIRST_CALL_TRANSACTION + 48,
                T_getConfigInfoForPackage = IBinder::FIRST_CALL_TRANSACTION + 49,
                T_getBlackListAction = IBinder::FIRST_CALL_TRANSACTION + 50,
                T_getForceAbiInstallMode = IBinder::FIRST_CALL_TRANSACTION + 51,
                T_isForcedDexoptWithInstallFlag = IBinder::FIRST_CALL_TRANSACTION + 52,
                T_isAppUsingOldHoudini = IBinder::FIRST_CALL_TRANSACTION + 53,
                T_getAdditionalGlExtensions = IBinder::FIRST_CALL_TRANSACTION + 54,
                T_areInputDevicesExposed = IBinder::FIRST_CALL_TRANSACTION + 55,
                T_isShowArmAbiListApp = IBinder::FIRST_CALL_TRANSACTION + 56,
                T_isIgnoreLargeHeapApp = IBinder::FIRST_CALL_TRANSACTION + 57,
                T_isClearCodeCacheApp = IBinder::FIRST_CALL_TRANSACTION + 58,
                T_isForcedInputDisabledApp = IBinder::FIRST_CALL_TRANSACTION + 59,
                T_isImageDetectionEnabled = IBinder::FIRST_CALL_TRANSACTION + 60,
                T_getHeapGrowthLimitSize = IBinder::FIRST_CALL_TRANSACTION + 61,
                T_isHideProcMapsApp = IBinder::FIRST_CALL_TRANSACTION + 62,
                T_isEnableNativeGamePad = IBinder::FIRST_CALL_TRANSACTION + 63,
                T_isPreloadBstHookLibraryApp = IBinder::FIRST_CALL_TRANSACTION + 64,
                T_isIl2cppApp = IBinder::FIRST_CALL_TRANSACTION + 65,
                T_updateIl2cppPkgs = IBinder::FIRST_CALL_TRANSACTION + 66,
                T_isSuppressedNotificationApp = IBinder::FIRST_CALL_TRANSACTION + 67,
                T_isMacrosDisabledApp = IBinder::FIRST_CALL_TRANSACTION + 68,
                T_showFeedbackPopup = IBinder::FIRST_CALL_TRANSACTION + 69,
                T_ffmpegConfidenceForApp = IBinder::FIRST_CALL_TRANSACTION + 70,
                T_isAppUsingSwappy = IBinder::FIRST_CALL_TRANSACTION + 71,
                T_getMouseCursorStyle = IBinder::FIRST_CALL_TRANSACTION + 72,
                T_getCameraSensorRotation = IBinder::FIRST_CALL_TRANSACTION + 73,
                T_isUE4GLFlushApp = IBinder::FIRST_CALL_TRANSACTION + 74,
                T_isGetNowggAccountsListApp = IBinder::FIRST_CALL_TRANSACTION + 75,
                T_isGoogleSignInRequired = IBinder::FIRST_CALL_TRANSACTION + 76,
                T_getMouseAction = IBinder::FIRST_CALL_TRANSACTION + 77,
                T_isVulkanRequired = IBinder::FIRST_CALL_TRANSACTION + 78,
                T_isForceKillApp = IBinder::FIRST_CALL_TRANSACTION + 79,
                T_isFixedDisplayRotationApp = IBinder::FIRST_CALL_TRANSACTION + 80,
                T_getGameDefaultSetting = IBinder::FIRST_CALL_TRANSACTION + 81,
                T_isHppEnabled = IBinder::FIRST_CALL_TRANSACTION + 82,
                T_isHotFixApp = IBinder::FIRST_CALL_TRANSACTION + 83,
                T_isGLInvalidateFramebufferFilterApp = IBinder::FIRST_CALL_TRANSACTION + 84,
                T_getUnityFlickerPatchRequired = IBinder::FIRST_CALL_TRANSACTION + 85,
                T_getDefaultProfile = IBinder::FIRST_CALL_TRANSACTION + 86,
                T_getXperfMode = IBinder::FIRST_CALL_TRANSACTION + 87,
                T_isIntelGLDispatchComputeFlushApp = IBinder::FIRST_CALL_TRANSACTION + 88,
                T_getCameraInitRotation = IBinder::FIRST_CALL_TRANSACTION + 89,
                T_isDhdg = IBinder::FIRST_CALL_TRANSACTION + 90,
                T_isGlNativeSyncDisabled = IBinder::FIRST_CALL_TRANSACTION + 91,
                T_isAngleDisabled = IBinder::FIRST_CALL_TRANSACTION + 92,
                T_isFbScreenLockApp = IBinder::FIRST_CALL_TRANSACTION + 93,
                T_isOneStorePay = IBinder::FIRST_CALL_TRANSACTION + 94,
                T_isGLProgramBinaryApp = IBinder::FIRST_CALL_TRANSACTION + 95,
                T_isGLUnmapBufferPerfApp = IBinder::FIRST_CALL_TRANSACTION + 96,
                T_getGLShaderWorkaround = IBinder::FIRST_CALL_TRANSACTION + 97,
                T_isDrmEnabled = IBinder::FIRST_CALL_TRANSACTION + 98,
                T_isTexTargetCheckDisabled = IBinder::FIRST_CALL_TRANSACTION + 99,
                T_getFixedSurfaceRotationRequired = IBinder::FIRST_CALL_TRANSACTION + 100,
                T_getIapSetting = IBinder::FIRST_CALL_TRANSACTION + 101,
                T_isGlMapBufferRangeHost = IBinder::FIRST_CALL_TRANSACTION + 102,
                T_isIgnoreSyncTimeout = IBinder::FIRST_CALL_TRANSACTION + 103,
                T_isGLVBOCacheDisableApp = IBinder::FIRST_CALL_TRANSACTION + 104,
                T_isBlockEditWhenComposing = IBinder::FIRST_CALL_TRANSACTION + 105,
                T_getGLHostInfo = IBinder::FIRST_CALL_TRANSACTION + 106,
                T_getGLExtensionsIgnore = IBinder::FIRST_CALL_TRANSACTION + 107,
                T_isEGLSurfaceIgnore = IBinder::FIRST_CALL_TRANSACTION + 108,
                T_isHardKeyBoard = IBinder::FIRST_CALL_TRANSACTION + 109,
                T_isIntelAutoGLFlushApp = IBinder::FIRST_CALL_TRANSACTION + 110,
                T_isRotateDisabled = IBinder::FIRST_CALL_TRANSACTION + 111,
                T_isUnreal5App = IBinder::FIRST_CALL_TRANSACTION + 112,
                T_isUE5PBDisabled = IBinder::FIRST_CALL_TRANSACTION + 113,
                T_isBptcApp = IBinder::FIRST_CALL_TRANSACTION + 114,
                T_isExtractNativeLibs = IBinder::FIRST_CALL_TRANSACTION + 115,
                T_isEtherNetType = IBinder::FIRST_CALL_TRANSACTION + 116,
                T_getVkHostInfo = IBinder::FIRST_CALL_TRANSACTION + 117,
                T_getVKDeviceExtIgnore = IBinder::FIRST_CALL_TRANSACTION + 118,
                T_isDefaultXYDpi = IBinder::FIRST_CALL_TRANSACTION + 119,
                T_getPScoreAbove = IBinder::FIRST_CALL_TRANSACTION + 120,
                T_isMapBufRangeReadOnceEnabled = IBinder::FIRST_CALL_TRANSACTION + 121,
                T_isFbCompleteCheckDisabled = IBinder::FIRST_CALL_TRANSACTION + 122,
                T_isUEEGLCrashFixApp = IBinder::FIRST_CALL_TRANSACTION + 123,
            };
    };

    // ----------------------------------------------------------------------
    class BnBstFilterAppsService : public BnInterface<IBstFilterAppsService>
    {
    public:
        // NOLINTNEXTLINE(google-default-arguments)
        virtual status_t    onTransact( uint32_t code,
                                        const Parcel& data,
                                        Parcel* reply,
                                        uint32_t flags = 0);
    };

} // namespace android

