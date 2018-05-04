#ifndef _SIMULATORCLIENT_IOEZPCLIENTMANAGER_H_
#define _SIMULATORCLIENT_IOEZPCLIENTMANAGER_H_
#include "IDeviceClientManager.h"

namespace DeviceCommunication{
class IDeviceClient;
}

namespace SimulatorClient {
class IoeZpClientManager : public DeviceCommunication::IDeviceClientManager
{
public:
    IoeZpClientManager();
    virtual ~IoeZpClientManager();
    virtual void addClient(const Network::IpSocketEndpoint& localEndPoint, std::unique_ptr<DeviceCommunication::IDeviceClient> client);
    virtual void removeClient(const Network::IpSocketEndpoint& localEndPoint);
    virtual void handleMessage(DeviceMessage::IDeviceMessage& message);
    virtual void setDeviceServer(std::unique_ptr<DeviceCommunication::IDeviceServer> server);
    virtual void startup();
    virtual void shutdown();
};
}

#endif // _SIMULATORCLIENT_IOEZPCLIENTMANAGER_H_
