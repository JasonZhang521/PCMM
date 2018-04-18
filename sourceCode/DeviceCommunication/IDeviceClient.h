#ifndef _DEVICECOMMUNICATION_IDEVICECLIENT_H_
#define _DEVICECOMMUNICATION_IDEVICECLIENT_H_

namespace DeviceMessage {
class IDeviceMessage;
}

namespace DeviceCommunication {
class IDeviceClient
{
public:
    IDeviceClient();
    virtual ~IDeviceClient();
    virtual void connect() = 0;
    virtual void send(DeviceMessage::IDeviceMessage& msg) = 0;
    virtual void disconnect() = 0;
};
}

#endif // _DEVICECOMMUNICATION_IDEVICECLIENT_H_
