#ifndef _DEVICECOMMUNICATION_IDEVICECLIENTMANAGER_H_
#define _DEVICECOMMUNICATION_IDEVICECLIENTMANAGER_H_
#include <memory>

namespace Network {
class IpSocketEndpoint;
}
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
    virtual void addClient(const Network::IpSocketEndpoint& localEndPoint, std::unique_ptr<IDeviceClient> client) = 0;
    virtual void removeClient(const Network::IpSocketEndpoint& localEndPoint) = 0;
    virtual void handleMessage(DeviceMessage::IDeviceMessage& message) = 0;

};
}
#endif // _DEVICECOMMUNICATION_IDEVICECLIENTMANAGER_H_
