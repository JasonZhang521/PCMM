#ifndef _DEVICECOMMUNICATION_DEVICECONNECTIONACCEPTOR_H_
#define _DEVICECOMMUNICATION_DEVICECONNECTIONACCEPTOR_H_

#include "ITcpConnectionAcceptor.h"
#include "DeviceType.h"

namespace Network {
class IpSocketEndpoint;
}

namespace DeviceCommunication {

class IDeviceClientManager;
class DeviceConnectionAcceptor : public Network::ITcpConnectionAcceptor
{
    IDeviceClientManager& clientManager_;
    DeviceType type_;
public:
    DeviceConnectionAcceptor() = delete;
    DeviceConnectionAcceptor(IDeviceClientManager& clientManager, DeviceType type);
    virtual ~DeviceConnectionAcceptor();
    virtual void onAccept(int fd, const Network::IpSocketEndpoint& localEndPoint, const Network::IpSocketEndpoint& remoteEndPoint);
};
}

#endif // _DEVICECOMMUNICATION_DEVICECONNECTIONACCEPTOR_H_
