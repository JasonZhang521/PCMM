#ifndef _DEVICECOMMUNICATION_DEVICESERVERCREATOR_H_
#define _DEVICECOMMUNICATION_DEVICESERVERCREATOR_H_
#include "DeviceType.h"
#include <memory>

namespace Network {
class IpSocketEndpoint;
}

namespace DeviceCommunication {
class IDeviceServer;
class IDeviceClientManager;

class DeviceServerCreator
{
public:
    DeviceServerCreator();
    static std::unique_ptr<IDeviceServer> CreateDeviceServer(DeviceType type, IDeviceClientManager& deviceClientManager, const Network::IpSocketEndpoint& localEndPoint);
};
}
#endif // _DEVICECOMMUNICATION_DEVICESERVERCREATOR_H_
