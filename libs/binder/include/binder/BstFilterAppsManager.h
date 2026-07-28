#include <binder/Common.h>
#include <binder/IBstFilterAppsService.h>
#include <utils/threads.h>

// ---------------------------------------------------------------------------
namespace android {

    class LIBBINDER_EXPORTED BstFilterAppsManager
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
    }; // namespace android
    // ---------------------------------------------------------------------------
}
