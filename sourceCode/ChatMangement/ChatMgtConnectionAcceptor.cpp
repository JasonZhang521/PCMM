#include "ChatMgtConnectionAcceptor.h"
#include "ChatMgtControl.h"
#include "ChatMgtConnectionReceiver.h"
#include "IpcClientCreator.h"
#include "IpSocketEndpoint.h"
#include "IpcClient.h"

namespace ChatManagement {

ChatMgtConnectionAcceptor::ChatMgtConnectionAcceptor(IChatMgtControl& chatMgtControl)
    : chatMgtControl_(chatMgtControl)
{
}

ChatMgtConnectionAcceptor::~ChatMgtConnectionAcceptor()
{
}

void ChatMgtConnectionAcceptor::onAccept(int fd, const Network::IpSocketEndpoint& localEndPoint,
                      const Network::IpSocketEndpoint& remoteEndPoint)
{
    createChatConnection(fd, localEndPoint, remoteEndPoint);
}

void ChatMgtConnectionAcceptor::createChatConnection(int fd,
                                 const Network::IpSocketEndpoint& localEndPoint,
                                 const Network::IpSocketEndpoint& remoteEndPoint)
{
    std::shared_ptr<Ipc::IIpcConnectionReceiver>
           chatMgtConnectionReceiver(new ChatMgtConnectionReceiver(chatMgtControl_,
                                                                           remoteEndPoint));


    IpcMessageFactories factories;
/*
    factories.push_back(std::shared_ptr<IpcMessage::IIpcMessageFactory>(new SystemMonitorMessage::SystemMonitorMessageFactory()));
    factories.push_back(std::shared_ptr<IpcMessage::IIpcMessageFactory>(new IpcMessage::IpcLayerMessageFactory()));
*/
    Ipc::IIpcClient* tcpAcceptedClientPtr =
            Ipc::IpcClientCreator::CreateWithTcpClientStrategy(fd, localEndPoint, remoteEndPoint, chatMgtConnectionReceiver, factories);
    std::unique_ptr<Ipc::IIpcClient> ipcClient(tcpAcceptedClientPtr);

    chatMgtControl_.addAcceptedIpcClient(remoteEndPoint, std::move(ipcClient));
}


}
