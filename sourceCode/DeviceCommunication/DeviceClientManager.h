#ifndef _DEVICECOMMUNICATION_DEVICECLIENTMANAGER_H_
#define _DEVICECOMMUNICATION_DEVICECLIENTMANAGER_H_
#include "IDeviceClientManager.h"
#include <map>
#include <memory>

namespace DeviceCommunication {

class IDeviceServer;
class DeviceClientManager : public IDeviceClientManager
{
    std::map<Network::IpSocketEndpoint, std::unique_ptr<IDeviceClient> > clients_;
    std::unique_ptr<IDeviceServer> deviceServer_;
public:
    DeviceClientManager();
    virtual ~DeviceClientManager();
    virtual void addClient(const Network::IpSocketEndpoint& localEndPoint, std::unique_ptr<IDeviceClient> client);
    virtual void removeClient(const Network::IpSocketEndpoint& localEndPoint);
    virtual void handleMessage(DeviceMessage::IDeviceMessage& message);
    virtual void setDeviceServer(std::unique_ptr<IDeviceServer> server);
    virtual void startup();
    virtual void shutdown();
};

}

#endif // _DEVICECOMMUNICATION_DEVICECLIENTMANAGER_H_
