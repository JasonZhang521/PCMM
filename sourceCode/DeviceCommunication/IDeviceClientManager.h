#ifndef _DEVICECOMMUNICATION_IDEVICECLIENTMANAGER_H_
#define _DEVICECOMMUNICATION_IDEVICECLIENTMANAGER_H_
#include <memory>

namespace DeviceMessage {
class IDeviceMessage;
}
namespace DeviceCommunication {

class IDeviceClient;
class IDeviceClientManager
{
public:
    IDeviceClientManager();
    virtual ~IDeviceClientManager();
    virtual void addClient(std::unique_ptr<IDeviceClient> client) = 0;
    virtual void handleMessage(DeviceMessage::IDeviceMessage& message) = 0;

};
}
#endif // _DEVICECOMMUNICATION_IDEVICECLIENTMANAGER_H_
