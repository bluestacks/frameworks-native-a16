#pragma once

#include <binder/Common.h>
#include <binder/IInterface.h>
#include <utils/String16.h>

namespace android {

    // ----------------------------------------------------------------------

    class LIBBINDER_EXPORTED IBstUtilsService : public IInterface
    {
        public:
            DECLARE_META_INTERFACE(BstUtilsService)

            virtual bool setProperty(const String16& key, const String16& value) = 0;
            virtual const String16 getAppNameFromPid(const int32_t pid) = 0;
            virtual bool setServiceComponentState(const String16& service, const bool enabled) = 0;

            /**
             * These should be in sync with the ordering in services's Aidl.
             * Here, it directly relates with IBstUtilsService.aidl.
             * If not in sync, these remote calls may call different functions than intended.
             */
            enum {
                T_setProperty = IBinder::FIRST_CALL_TRANSACTION + 0,
                T_getAppNameFromPid = IBinder::FIRST_CALL_TRANSACTION + 1,
                T_setServiceComponentState = IBinder::FIRST_CALL_TRANSACTION + 2,
                T_isBstSoftKeyboardEnabled = IBinder::FIRST_CALL_TRANSACTION + 3,
                T_setBstSoftKeyboardStatus = IBinder::FIRST_CALL_TRANSACTION + 4,
                T_setBstProposedRotation = IBinder::FIRST_CALL_TRANSACTION + 5,
                T_getApkDownloadSource = IBinder::FIRST_CALL_TRANSACTION + 6,
                T_launchAppStore = IBinder::FIRST_CALL_TRANSACTION + 7,
                T_getSessionToken = IBinder::FIRST_CALL_TRANSACTION + 8,
            };
    };

    // ----------------------------------------------------------------------
    class BnBstUtilsService : public BnInterface<IBstUtilsService>
    {
    public:
        // NOLINTNEXTLINE(google-default-arguments)
        virtual status_t    onTransact( uint32_t code,
                                        const Parcel& data,
                                        Parcel* reply,
                                        uint32_t flags = 0);
    };


} // namespace android

