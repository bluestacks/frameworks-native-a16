// BS-A16: Dual-mode header. Vendor modules get stubs (no binder deps).
// Non-vendor modules get the A13 implementation.
#ifdef __ANDROID_VENDOR__

#ifndef ANDROID_BST_UTILS_MANAGER_STUB_H
#define ANDROID_BST_UTILS_MANAGER_STUB_H
#include <utils/String16.h>
namespace android {
    class BstUtilsManager {
        public:
            BstUtilsManager() {}
            bool setProperty(const String16&, const String16&) { return false; }
            const String16 getAppNameFromPid(const int32_t) { return String16(); }
            bool setServiceComponentState(const String16&, const bool) { return false; }
    };
}
#endif

#else  // !__ANDROID_VENDOR__

#include <binder/IBstUtilsService.h>
#include <utils/threads.h>

// ---------------------------------------------------------------------------
namespace android {

    class __attribute__((visibility("default"))) BstUtilsManager
    {
        public:
            BstUtilsManager();
            bool setProperty(const String16& key, const String16& value);
            const String16 getAppNameFromPid(const int32_t pid);
            bool setServiceComponentState(const String16& service, const bool enabled);

        private:
            Mutex mLock;
            sp<IBstUtilsService> mService;
            sp<IBstUtilsService> getService();
    };
    // ---------------------------------------------------------------------------
}

#endif // !__ANDROID_VENDOR__
