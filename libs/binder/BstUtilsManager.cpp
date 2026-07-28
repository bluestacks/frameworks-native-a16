#define LOG_TAG "BstUtilsManager"

#include <binder/BstUtilsManager.h>
#include <binder/Binder.h>
#include <binder/IServiceManager.h>

#include <utils/Log.h>
#include <utils/SystemClock.h>

namespace android {

    BstUtilsManager::BstUtilsManager()
    {
    }

    sp<IBstUtilsService> BstUtilsManager::getService()
    {
        //int64_t startTime = uptimeMillis();
        mLock.lock();
        sp<IBstUtilsService> service = mService;
        if (service == NULL || !(IInterface::asBinder(service)->isBinderAlive())) {
            sp<IBinder> binder = defaultServiceManager()->checkService(String16("bstutils"));
            if (binder == NULL) {
                ALOGW("Waited too long for bstutils service, giving up");
            } else {
                service = interface_cast<IBstUtilsService>(binder);
                mService = service;
            }
        }
        mLock.unlock();
        return service;
    }

    bool BstUtilsManager::setProperty(const String16& key, const String16& value)
    {
        sp<IBstUtilsService> service = getService();
        return service != NULL ? service->setProperty(key, value): false;
    }

    const String16 BstUtilsManager::getAppNameFromPid(const int32_t pid)
    {
        sp<IBstUtilsService> service = getService();
        String16 default_return("");
        return service != NULL ? service->getAppNameFromPid(pid): default_return;
    }

    bool BstUtilsManager::setServiceComponentState(const String16& serviceName, const bool enabled)
    {
        sp<IBstUtilsService> service = getService();
        if (service != NULL) {
            service->setServiceComponentState(serviceName, enabled);
            return true;
        }
        return false;
    }
} // namespace android
