#include "Component.h"
#include "Macro.h"
#include "Trace.h"
#include "ChatMgtControl.h"
#include "ChatMgtConnectionAcceptor.h"
#include "IChatMessage.h"
#include "IpcServerCreator.h"
#include "IpcClient.h"
#include "IpcServer.h"
#include "IpSocketEndpoint.h"
#include "IIpcMessage.h"


namespace ChatManagement {

GETCLASSNAME(ChatMgtControl)
ChatMgtControl::ChatMgtControl(const Network::IpSocketEndpoint& localEndpoint)
    : acceptor_(new ChatMgtConnectionAcceptor(*this))
    , ipcServer_(Ipc::IpcServerCreator::CreateWithTcpServer(localEndpoint, acceptor_))
{
}

ChatMgtControl::~ChatMgtControl()
{
}

void ChatMgtControl::startup()
{
    TRACE_ENTER();
    ipcServer_->startup();
}

void ChatMgtControl::shutdown()
{
    TRACE_ENTER();
    ipcServer_->shutdown();
}

void ChatMgtControl::addAcceptedIpcClient(const Network::IpSocketEndpoint& remoteEndPoint, std::unique_ptr<Ipc::IIpcClient> ipcClient)
{
    TRACE_DEBUG("Add client:" << remoteEndPoint);
    IpcClientsMap::iterator it= clients_.find(remoteEndPoint);
    if (it != clients_.end())
    {
        TRACE_WARNING("Ipc client :" << remoteEndPoint << " already exist!");
    }
    clients_[remoteEndPoint] = std::move(ipcClient);
}

void ChatMgtControl::removeAcceptedIpcClient(const Network::IpSocketEndpoint& remoteEndPoint)
{
    TRACE_DEBUG("remove client:" << remoteEndPoint);
    IpcClientsMap::iterator it = clients_.find(remoteEndPoint);
    if (it != clients_.end())
    {
        clients_.erase(it);
    }
    else
    {
        TRACE_WARNING("Ipc client :" << remoteEndPoint << " already been removed!");
    }
}

void ChatMgtControl::handleMessage(IpcMessage::IIpcMessage& msg, const Network::IpSocketEndpoint& remoteIpEndpoint)
{
    static_cast<void>(remoteIpEndpoint);
    ChatSessionMessage::IChatMessage* chatMessage = dynamic_cast<ChatSessionMessage::IChatMessage*>(&msg);
    if (nullptr == chatMessage)
    {
        TRACE_NOTICE("Not chat message, Can't parse!");
        return;
    }

    const ChatSessionMessage::GroupDestination& dests = chatMessage->getGroupDestination();
    for (ChatSessionMessage::GroupDestination::const_iterator it = dests.begin(); it != dests.end(); ++it)
    {
        IpcClientsMap::iterator clientIt = clients_.find(*it);
        if (clientIt != clients_.end())
        {
            std::unique_ptr<Ipc::IIpcClient>& client = clientIt->second;
            msg.setDestnation(*it);
            client->send(msg);
        }
    }
}

}

