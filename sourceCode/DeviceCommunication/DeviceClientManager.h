#ifndef _DEVICECOMMUNICATION_DEVICECLIENTMANAGER_H_
#define _DEVICECOMMUNICATION_DEVICECLIENTMANAGER_H_
#include "IDeviceClientManager.h"
#include <map>
#include <memory>

namespace DeviceCommunication {
class DeviceClientManager : public IDeviceClientManager
{
    std::map<Network::IpSocketEndpoint, std::unique_ptr<IDeviceClient> > clients_;
public:
    DeviceClientManager();
    virtual ~DeviceClientManager();
    virtual void addClient(const Network::IpSocketEndpoint& localEndPoint, std::unique_ptr<IDeviceClient> client);
    virtual void removeClient(const Network::IpSocketEndpoint& localEndPoint);
    virtual void handleMessage(DeviceMessage::IDeviceMessage& message);
};

}

#endif // _DEVICECOMMUNICATION_DEVICECLIENTMANAGER_H_
