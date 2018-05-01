#ifndef _SIMULATORCLIENT_DEVICECLIENTHANDLER_H_
#define _SIMULATORCLIENT_DEVICECLIENTHANDLER_H_
#include "IDeviceClientHandler.h"

namespace SimulatorClient {

class DeviceClientHandler : public IDeviceClientHandler
{
    std::unique_ptr<DeviceCommunication::IDeviceClient> client_;
public:
    DeviceClientHandler();
    virtual ~DeviceClientHandler();
    virtual void setDeviceClient(std::unique_ptr<DeviceCommunication::IDeviceClient> client);
    virtual void startup();
    virtual void shutdown();
    virtual void reStartup();
    virtual void onStartup();
    virtual void onShutdown();
};
}

#endif // _SIMULATORCLIENT_DEVICECLIENTHANDLER_H_
