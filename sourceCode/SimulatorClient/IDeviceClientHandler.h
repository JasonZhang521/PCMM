#ifndef _SIMULATORCLIENT_IDEVICECLIENTHANDLER_H_
#define _SIMULATORCLIENT_IDEVICECLIENTHANDLER_H_
#include "DeviceClient.h"

namespace SimulatorClient {

class IDeviceClientHandler
{
public:
    IDeviceClientHandler();
    virtual ~IDeviceClientHandler();
    virtual void setDeviceClient(std::shared_ptr<DeviceCommunication::IDeviceClient> deviceClient) = 0;
    virtual void startup() = 0;
    virtual void shutdown() = 0;
    virtual void reStartup() = 0;
    virtual void onStartup() = 0;
    virtual void onShutdown() = 0;
};

}

#endif // _SIMULATORCLIENT_IDEVICECLIENTHANDLER_H_
