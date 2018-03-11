#ifndef ICHATMGTCONTROL_H
#define ICHATMGTCONTROL_H
#include <memory>

namespace Network {
class IpSocketEndpoint;
}

namespace Ipc {
class IIpcClient;
}

namespace IpcMessage {
class IIpcMessage;
}

namespace ChatManagement {
class IChatMgtControl
{
public:
    IChatMgtControl();
    virtual ~IChatMgtControl();
    virtual void startup() = 0;
    virtual void shutdown() = 0;
    virtual void addAcceptedIpcClient(const Network::IpSocketEndpoint& remoteEndPoint, std::unique_ptr<Ipc::IIpcClient> ipcClient) = 0;
    virtual void removeAcceptedIpcClient(const Network::IpSocketEndpoint& remoteEndPoint) = 0;
    virtual void handleMessage(IpcMessage::IIpcMessage& msg, const Network::IpSocketEndpoint& remoteIpEndpoint) = 0;

};

}

#endif // ICHATMGTCONTROL_H
