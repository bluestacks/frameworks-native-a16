// BS-A16: Dual-mode header. Vendor modules get the full stub (no binder deps).
// Non-vendor modules get the A13 implementation with real database-backed logic.
#ifdef __ANDROID_VENDOR__

#ifndef ANDROID_BST_FILTER_APPS_MANAGER_STUB_H
#define ANDROID_BST_FILTER_APPS_MANAGER_STUB_H
#include <utils/String16.h>
namespace android {
    class BstFilterAppsManager {
        public:
            BstFilterAppsManager() {}
        bool isImmersiveEnabledApp(const String16&) { return false; }
        bool isSmallScreenApp(const String16&) { return false; }
        bool forceArmInstall(const String16&) { return false; }
        bool forceX86Install(const String16&) { return false; }
        bool isWhiteListed(const String16&) { return false; }
        bool isBlackListed(const String16&, const String16&) { return false; }
        bool isSoftKeyboardRequired(const String16&, const String16&) { return false; }
        const String16 getSoftKeyboardModifier(const String16&) { return String16(); }
        bool isMarketRequired(const String16&) { return false; }
        bool isHeadsetRequired(const String16&) { return false; }
        bool isPortraitDisabled(const String16&) { return false; }
        const String16 getCustomDpi(const String16&) { return String16(); }
        bool isPvrtcApp(const String16&) { return false; }
        bool isS3tcApp(const String16&) { return false; }
        bool isGlv1notimpApp(const String16&) { return false; }
        bool isXarchApp(const int32_t) { return false; }
        bool isClearInstallApp(const String16&) { return false; }
        bool isScreenOrientationFixed(const String16&,const String16&) { return false; }
        int isCameraRotationRequired(const String16&) { return 0; }
        bool forceLandscapeOrientationIfUnspecified(const String16&) { return false; }
        const String16 getGlRenderer(const String16&) { return String16(); }
        const String16 getGlVendor(const String16&) { return String16(); }
        bool isGL3App(const String16&) { return false; }
        const String16 isLoadLibHackReqd(const int32_t) { return String16(); }
        bool isGL3Disabled(const String16&) { return false; }
        bool isZeroMappedPageReqd(const int32_t) { return false; }
        bool isModifysdPathReqd(const String16&) { return false; }
        bool isAGAGL3Disabled(const String16&) { return false; }
        bool isPGAGL3Disabled(const String16&) { return false; }
        bool isShowOrigCpuinfoArmApp(const int32_t) { return false; }
        bool isAstcApp(const String16&) { return false; }
        bool isPatchRelocApp(const int32_t) { return false; }
        const String16 getPgaGlVersion(const String16&) { return String16(); }
        const String16 getAgaGlVersion(const String16&) { return String16(); }
        bool isHardwareAstcDisabledApp(const String16&) { return false; }
        bool isXArmApp(const String16&) { return false; }
        const String16 getMemorySize(const int32_t) { return String16(); }
        bool isAppUsingOldHoudini(const int32_t) { return false; }
        const String16 getAdditionalGlExtensions(const String16&) { return String16(); }
        bool areInputDevicesExposed(const String16&) { return false; }
        bool isShowArmAbiListApp(const int32_t) { return false; }
        bool isIgnoreLargeHeapApp(const String16&) { return false; }
        bool isClearCodeCacheApp(const int32_t) { return false; }
        bool isImageDetectionEnabled(const String16&) { return false; }
        int getHeapGrowthLimitSize(const String16&) { return 0; }
        bool isHideProcMapsApp(const String16&) { return false; }
        bool isEnableNativeGamePad(const String16&) { return false; }
        bool isPreloadBstHookLibraryApp(const String16&) { return false; }
        bool isIl2cppApp(const int32_t) { return false; }
        void updateIl2cppPkgs(const String16&) { }
        bool isSuppressedNotificationApp(const String16&) { return false; }
        bool isMacrosDisabledApp(const String16&) { return false; }
        bool showFeedbackPopup(const String16&) { return false; }
        float ffmpegConfidenceForApp(const String16&) { return 0.0f; }
        bool isAppUsingSwappy(const int32_t) { return false; }
        const String16 getMouseCursorStyle(const String16&) { return String16(); }
        int getCameraSensorRotation(const String16&) { return 0; }
        int getCameraInitRotation(const String16&) { return 0; }
        bool isUE4GLFlushApp(const String16&) { return false; }
        bool isGetNowggAccountsListApp(const int32_t) { return false; }
        bool isGoogleSignInRequired(const String16&) { return false; }
        const String16 isVulkanRequired(const String16&) { return String16(); }
        bool isForceKillApp(const String16&) { return false; }
        bool isFixedDisplayRotationApp(const String16&) { return false; }
        const String16 getGameDefaultSetting(const String16&) { return String16(); }
        bool isHppEnabled(const String16&) { return false; }
        bool isHotFixApp(const String16&) { return false; }
        bool isGLInvalidateFramebufferFilterApp(const String16&) { return false; }
        int getUnityFlickerPatchRequired(const String16&) { return 0; }
        const String16 getDefaultProfile(const String16&) { return String16(); }
        int getXperfMode(const int32_t) { return 0; }
        bool isIntelGLDispatchComputeFlushApp(const String16&) { return false; }
        bool isDhdg(const int32_t) { return false; }
        bool isGlNativeSyncDisabled(const String16&) { return false; }
        bool isAngleDisabled(const String16&) { return false; }
        bool isHotFixAppByUid(const int32_t) { return false; }
        bool isFbScreenLockApp(const String16&) { return false; }
        bool isOneStorePay(const String16&) { return false; }
        bool isGLProgramBinaryApp(const String16&) { return false; }
        bool isGLUnmapBufferPerfApp(const String16&) { return false; }
        const String16 getGLShaderWorkaround(const String16&) { return String16(); }
        bool isDrmEnabled(const String16&) { return false; }
        bool isEtherNetType(const String16&) { return false; }
        bool isTexTargetCheckDisabled(const String16&) { return false; }
        int getFixedSurfaceRotationRequired(const String16&) { return 0; }
        const String16 getIapSetting(const String16&) { return String16(); }
        bool isGlMapBufferRangeHost(const String16&) { return false; }
        bool isIgnoreSyncTimeout(const String16&) { return false; }
        bool isGLVBOCacheDisableApp(const String16&) { return false; }
        bool isBlockEditWhenComposing(const String16&) { return false; }
        const String16 getGLHostInfo(const String16&) { return String16(); }
        const String16 getGLExtensionsIgnore(const String16&) { return String16(); }
        const String16 getVkHostInfo(const String16&) { return String16(); }
        const String16 getVKDeviceExtIgnore(const String16&) { return String16(); }
        bool isEGLSurfaceIgnore(const String16&) { return false; }
        bool isHardKeyBoard(const String16&) { return false; }
        bool isIntelAutoGLFlushApp(const String16&) { return false; }
        bool isRotateDisabled(const String16&) { return false; }
        bool isUnreal5App(const String16&) { return false; }
        bool isUE5PBDisabled(const String16&) { return false; }
        bool isBptcApp(const String16&) { return false; }
        bool isExtractNativeLibs(const String16&) { return false; }
        bool isDefaultXYDpi(const String16&) { return false; }
        int getPScoreAbove(const String16&) { return 0; }
        bool isMapBufRangeReadOnceEnabled(const String16&) { return false; }
        bool isFbCompleteCheckDisabled(const String16&) { return false; }
    };
}
#endif

#else  // !__ANDROID_VENDOR__

#include <binder/IBstFilterAppsService.h>
#include <utils/threads.h>

// ---------------------------------------------------------------------------
namespace android {

    class __attribute__((visibility("default"))) BstFilterAppsManager
    {
        public:
            BstFilterAppsManager();

            bool isImmersiveEnabledApp(const String16& callingPackage);
            bool isSmallScreenApp(const String16& callingPackage);
            bool forceArmInstall(const String16& callingPackage);
            bool forceX86Install(const String16& callingPackage);
            bool isWhiteListed(const String16& callingPackage);
            bool isBlackListed(const String16& callingPackage, const String16& version);
            bool isSoftKeyboardRequired(const String16& callingPackage, const String16& activity);
            const String16 getSoftKeyboardModifier(const String16& callingPackage);
            bool isMarketRequired(const String16& callingPackage);
            bool isHeadsetRequired(const String16& callingPackage);
            bool isPortraitDisabled(const String16& callingPackage);
            const String16 getCustomDpi(const String16& callingPackage);
            bool isPvrtcApp(const String16& callingPackage);
            bool isS3tcApp(const String16& callingPackage);
            bool isGlv1notimpApp(const String16& callingPackage);
            bool isXarchApp(const int32_t uid);
            bool isClearInstallApp(const String16& callingPackage);
            bool isScreenOrientationFixed(const String16& callingPackage,const String16& currentPkgName);
            int isCameraRotationRequired(const String16& callingPackage);
            bool forceLandscapeOrientationIfUnspecified(const String16& callingPackage);
            const String16 getGlRenderer(const String16& callingPackage);
            const String16 getGlVendor(const String16& callingPackage);
            bool isGL3App(const String16& callingPackage);
            const String16 isLoadLibHackReqd(const int32_t uid);
            bool isGL3Disabled(const String16& callingPackage);
            bool isZeroMappedPageReqd(const int32_t uid);
            bool isModifysdPathReqd(const String16& callingPackage);
            bool isAGAGL3Disabled(const String16& callingPackage);
            bool isPGAGL3Disabled(const String16& callingPackage);
            bool isShowOrigCpuinfoArmApp(const int32_t uid);
            bool isAstcApp(const String16& callingPackage);
            bool isPatchRelocApp(const int32_t uid);
            const String16 getPgaGlVersion(const String16& callingPackage);
            const String16 getAgaGlVersion(const String16& callingPackage);
            bool isHardwareAstcDisabledApp(const String16& callingPackage);
            bool isXArmApp(const String16& callingPackage);
            const String16 getMemorySize(const int32_t uid);
            bool isAppUsingOldHoudini(const int32_t uid);
            const String16 getAdditionalGlExtensions(const String16& callingPackage);
            bool areInputDevicesExposed(const String16& callingPackage);
            bool isShowArmAbiListApp(const int32_t uid);
            bool isIgnoreLargeHeapApp(const String16& callingPackage);
            bool isClearCodeCacheApp(const int32_t uid);
            bool isImageDetectionEnabled(const String16& callingPackage);
            int getHeapGrowthLimitSize(const String16& callingPackage);
            bool isHideProcMapsApp(const String16& callingPackage);
            bool isEnableNativeGamePad(const String16& callingPackage);
            bool isPreloadBstHookLibraryApp(const String16& callingPackage);
            bool isIl2cppApp(const int32_t uid);
            void updateIl2cppPkgs(const String16& callingPackage);
            bool isSuppressedNotificationApp(const String16& callingPackage);
            bool isMacrosDisabledApp(const String16& callingPackage);
            bool showFeedbackPopup(const String16& callingPackage);
            float ffmpegConfidenceForApp(const String16& callingPackage);
            bool isAppUsingSwappy(const int32_t uid);
            const String16 getMouseCursorStyle(const String16& callingPackage);
            int getCameraSensorRotation(const String16& callingPackage);
            int getCameraInitRotation(const String16& callingPackage);
            bool isUE4GLFlushApp(const String16& callingPackage);
            bool isGetNowggAccountsListApp(const int32_t uid);
            bool isGoogleSignInRequired(const String16& callingPackage);
            const String16 isVulkanRequired(const String16& callingPackage);
            bool isForceKillApp(const String16& callingPackage);
            bool isFixedDisplayRotationApp(const String16& callingPackage);
            const String16 getGameDefaultSetting(const String16&  pkgName);
            bool isHppEnabled(const String16& callingPackage);
            bool isHotFixApp(const String16& callingPackage);
            bool isGLInvalidateFramebufferFilterApp(const String16& callingPackage);
            int getUnityFlickerPatchRequired(const String16& callingPackage);
            const String16 getDefaultProfile(const String16&  pkgName);
            int getXperfMode(const int32_t uid);
            bool isIntelGLDispatchComputeFlushApp(const String16& callingPackage);
            bool isDhdg(const int32_t uid);
            bool isGlNativeSyncDisabled(const String16& callingPackage);
            bool isAngleDisabled(const String16& callingPackage);
            bool isHotFixAppByUid(const int32_t uid);
            bool isFbScreenLockApp(const String16& callingPackage);
            bool isOneStorePay(const String16& callingPackage);
            bool isGLProgramBinaryApp(const String16& callingPackage);
            bool isGLUnmapBufferPerfApp(const String16& callingPackage);
            const String16 getGLShaderWorkaround(const String16& callingPackage);
            bool isDrmEnabled(const String16& callingPackage);
            bool isEtherNetType(const String16& callingPackage);
            bool isTexTargetCheckDisabled(const String16& callingPackage);
            int getFixedSurfaceRotationRequired(const String16& callingPackage);
            const String16 getIapSetting(const String16&  pkgName);
            bool isGlMapBufferRangeHost(const String16& callingPackage);
            bool isIgnoreSyncTimeout(const String16& callingPackage);
            bool isGLVBOCacheDisableApp(const String16& callingPackage);
            bool isBlockEditWhenComposing(const String16& callingPackage);
            const String16 getGLHostInfo(const String16& callingPackage);
            const String16 getGLExtensionsIgnore(const String16& callingPackage);
            const String16 getVkHostInfo(const String16& callingPackage);
            const String16 getVKDeviceExtIgnore(const String16& callingPackage);
            bool isEGLSurfaceIgnore(const String16& callingPackage);
            bool isHardKeyBoard(const String16& callingPackage);
            bool isIntelAutoGLFlushApp(const String16& callingPackage);
            bool isRotateDisabled(const String16& callingPackage);
            bool isUnreal5App(const String16& callingPackage);
            bool isUE5PBDisabled(const String16& callingPackage);
            bool isBptcApp(const String16& callingPackage);
            bool isExtractNativeLibs(const String16& callingPackage);
            bool isDefaultXYDpi(const String16& callingPackage);
            int getPScoreAbove(const String16& callingPackage);
            bool isMapBufRangeReadOnceEnabled(const String16& callingPackage);
            bool isFbCompleteCheckDisabled(const String16& callingPackage);


        private:
            Mutex mLock;
            sp<IBstFilterAppsService> mService;
            sp<IBstFilterAppsService> getService();
    };
}

#endif // !__ANDROID_VENDOR__
