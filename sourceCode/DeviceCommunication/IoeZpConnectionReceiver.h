#ifndef _DEVICECOMMUNICATION_IOEZPCONNECTIONRECEIVER_H_
#define _DEVICECOMMUNICATION_IOEZPCONNECTIONRECEIVER_H_
#include "ITcpConnectionReceiver.h"
#include "IpSocketEndpoint.h"

namespace Serialize {
class ReadBuffer;
}
namespace Network {
class IpSocketEndpoint;
}

namespace DeviceCommunication {
class IDeviceClientManager;
class IoeZpConnectionReceiver : public Network::ITcpConnectionReceiver
{
    const Network::IpSocketEndpoint remoteIpEndpoint_;
    IDeviceClientManager& clientManager_;
public:
    IoeZpConnectionReceiver(const Network::IpSocketEndpoint& remoteIpEndpoint, IDeviceClientManager& clientManager);
    virtual ~IoeZpConnectionReceiver();
    virtual void onConnect();
    virtual void onReceive(Serialize::ReadBuffer& readBuffer);
    virtual void onDisconnect();
};

}

#endif // _DEVICECOMMUNICATION_IOEZPCONNECTIONRECEIVER_H_
