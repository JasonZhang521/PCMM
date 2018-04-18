#ifndef _DEVICECOMMUNICATION_DEVICECONNECTIONRECEIVERCREATOR_H_
#define _DEVICECOMMUNICATION_DEVICECONNECTIONRECEIVERCREATOR_H_
#include "DeviceType.h"

namespace Network {
class ITcpConnectionReceiver;
class IpSocketEndpoint;
}

namespace DeviceCommunication {
class IDeviceClientManager;
class DeviceConnectionReceiverCreator
{
public:
    DeviceConnectionReceiverCreator();
    static Network::ITcpConnectionReceiver* create(DeviceType type, const Network::IpSocketEndpoint& remoteIpEndpoint, IDeviceClientManager& manager);
};
}

#endif // _DEVICECOMMUNICATION_DEVICECONNECTIONRECEIVERCREATOR_H_
