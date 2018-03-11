#include "Component.h"
#include "Macro.h"
#include "Trace.h"
#include "ChatMgtConnectionReceiver.h"
#include "ChatMgtControl.h"
#include "IpSocketEndpoint.h"
#include "IIpcMessage.h"

namespace ChatManagement {

GETCLASSNAME(ChatMgtConnectionReceiver)

ChatMgtConnectionReceiver::ChatMgtConnectionReceiver(IChatMgtControl& chatMgtControl,
                                                     const Network::IpSocketEndpoint remoteIpEndpoint)
    :chatMgtControl_(chatMgtControl)
    ,remoteIpEndpoint_(remoteIpEndpoint)
{

}

ChatMgtConnectionReceiver::~ChatMgtConnectionReceiver()
{

}

void ChatMgtConnectionReceiver::onConnect()
{
    TRACE_NOTICE("client" << remoteIpEndpoint_ << " is connected!");
}

void ChatMgtConnectionReceiver::onReceive(std::unique_ptr<IpcMessage::IIpcMessage> msg)
{
    TRACE_DEBUG("receive message from " << remoteIpEndpoint_ << ": " << *msg);
    chatMgtControl_.handleMessage(*msg, remoteIpEndpoint_);
}

void ChatMgtConnectionReceiver::onDisconnect()
{
    TRACE_NOTICE("client " << remoteIpEndpoint_ << " is disconnected!");
    chatMgtControl_.removeAcceptedIpcClient(remoteIpEndpoint_);
}

}
