#define LOG_TAG "BstUtilsService"

#include <binder/IBstUtilsService.h>

#include <utils/Debug.h>
#include <utils/Log.h>
#include <binder/Parcel.h>
#include <utils/String8.h>
#include <utils/String16.h>
#include <Static.h>

namespace android {

// ----------------------------------------------------------------------

class BpBstUtilsService : public BpInterface<IBstUtilsService>
{
public:
    explicit BpBstUtilsService(const sp<IBinder>& impl)
        : BpInterface<IBstUtilsService>(impl)
    {
    }

    virtual bool setProperty(const String16& key, const String16& value) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstUtilsService::getInterfaceDescriptor());
        data.writeString16(key);
        data.writeString16(value);
        remote()->transact(T_setProperty, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return false;
        int32_t res = reply.readInt32();
        if (res == 1)
            return true;
        else
            return false;
    }

    virtual const String16 getAppNameFromPid(const int32_t pid) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstUtilsService::getInterfaceDescriptor());
        data.writeInt32(pid);
        remote()->transact(T_getAppNameFromPid, data, &reply);
        // fail on exception
        String16 default_return("");
        if (reply.readExceptionCode() != 0)
            return default_return;
        return reply.readString16();
    }

    virtual bool setServiceComponentState(const String16& service, const bool enabled) {
        Parcel data, reply;
        data.writeInterfaceToken(IBstUtilsService::getInterfaceDescriptor());
        data.writeString16(service);
        data.writeInt32((enabled ? 1 : 0));
        remote()->transact(T_setServiceComponentState, data, &reply);
        // fail on exception
        if (reply.readExceptionCode() != 0) return false;
        return true;
    }
};

IMPLEMENT_META_INTERFACE(BstUtilsService, "com.bluestacks.os.IBstUtilsService")

// ----------------------------------------------------------------------

// NOLINTNEXTLINE(google-default-arguments)
status_t BnBstUtilsService::onTransact(
        uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags)
{
   // printf("BstUtilsService!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! received: "); data.print();
    switch(code) {
        case T_setProperty: {
            CHECK_INTERFACE(IBstUtilsService, data, reply);
            String16 key = data.readString16();
            String16 value = data.readString16();
            bool res = setProperty(key, value);
            reply->writeNoException();
            if (res == true)
                reply->writeInt32(1);
            else
                reply->writeInt32(0);
            return NO_ERROR;
        } break;
        case T_getAppNameFromPid: {
            CHECK_INTERFACE(IBstUtilsService, data, reply);
            int32_t pid = data.readInt32();
            String16 res = getAppNameFromPid(pid);
            reply->writeNoException();
            reply->writeString16(res);
            return NO_ERROR;
        } break;
        case T_setServiceComponentState: {
            CHECK_INTERFACE(IBstUtilsService, data, reply);
            String16 service = data.readString16();
            bool enabled = (data.readInt32() ? true : false);
            setServiceComponentState(service, enabled);
            reply->writeNoException();
            return NO_ERROR;
        } break;

        default:
            return BBinder::onTransact(code, data, reply, flags);
    }
}

//----------------------------------------------------------------------

} // namespace android
