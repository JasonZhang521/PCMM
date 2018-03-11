#ifndef CHATMGTCONTROL_H
#define CHATMGTCONTROL_H
#include <memory>
#include <map>
#include "IChatMgtControl.h"

namespace Ipc {
class IIpcServer;
class IIpcConnectionAcceptor;
}

namespace ChatManagement {
class ChatMgtControl : public IChatMgtControl
{
    std::shared_ptr<Ipc::IIpcConnectionAcceptor> acceptor_;
    std::unique_ptr<Ipc::IIpcServer> ipcServer_;
    using IpcClientsMap = std::map<Network::IpSocketEndpoint, std::unique_ptr<Ipc::IIpcClient> >;
    IpcClientsMap clients_;    

public:
    ChatMgtControl(const Network::IpSocketEndpoint& localEndpoint);
    ~ChatMgtControl();
    virtual void startup();
    virtual void shutdown();
    virtual void addAcceptedIpcClient(const Network::IpSocketEndpoint& remoteEndPoint, std::unique_ptr<Ipc::IIpcClient> ipcClient);
    virtual void removeAcceptedIpcClient(const Network::IpSocketEndpoint& remoteEndPoint);
    virtual void handleMessage(IpcMessage::IIpcMessage& msg, const Network::IpSocketEndpoint& remoteIpEndpoint);
};

}
#endif // CHATMGTCONTROL_H
