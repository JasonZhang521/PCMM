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
class IDeviceServer;
class IDeviceClientManager
{
public:
    IDeviceClientManager();
    virtual ~IDeviceClientManager();
    virtual void addClient(const Network::IpSocketEndpoint& localEndPoint, std::unique_ptr<IDeviceClient> client) = 0;
    virtual void removeClient(const Network::IpSocketEndpoint& localEndPoint) = 0;
    virtual void handleMessage(DeviceMessage::IDeviceMessage& message) = 0;
    virtual void setDeviceServer(std::unique_ptr<IDeviceServer> server) = 0;
    virtual void startup() = 0;
    virtual void shutdown() = 0;

};
}
#endif // _DEVICECOMMUNICATION_IDEVICECLIENTMANAGER_H_
