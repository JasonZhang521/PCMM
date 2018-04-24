#ifndef _DEVICECOMMUNICATION_IDEVICEMESSAGEHANDLER_H_
#define _DEVICECOMMUNICATION_IDEVICEMESSAGEHANDLER_H_

namespace DeviceMessage {
class IDeviceMessage;
}

namespace DeviceCommunication {
class IDeviceMessageHandler
{
public:
    IDeviceMessageHandler();
    virtual ~IDeviceMessageHandler();
    virtual void handleMessage(const DeviceMessage::IDeviceMessage* message) = 0;
};
}

#endif // _DEVICECOMMUNICATION_IDEVICEMESSAGEHANDLER_H_
