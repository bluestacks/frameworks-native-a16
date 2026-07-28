#include <binder/Common.h>
#include <binder/IBstUtilsService.h>
#include <utils/threads.h>

// ---------------------------------------------------------------------------
namespace android {

    class LIBBINDER_EXPORTED BstUtilsManager
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
    }; // namespace android
    // ---------------------------------------------------------------------------
}
