#ifndef _CHATMANAGEMENTCHATMGTCONNECTIONRECEIVER_H_
#define _CHATMANAGEMENTCHATMGTCONNECTIONRECEIVER_H_
#include "IIpcConnectionReceiver.h"
#include "IpSocketEndpoint.h"
namespace ChatManagement {
class IChatMgtControl;
class ChatMgtConnectionReceiver : public Ipc::IIpcConnectionReceiver
{
    IChatMgtControl& chatMgtControl_;
    const Network::IpSocketEndpoint remoteIpEndpoint_;
public:
    ChatMgtConnectionReceiver(IChatMgtControl& chatMgtControl,
                              const Network::IpSocketEndpoint remoteIpEndpoint);
    virtual ~ChatMgtConnectionReceiver();
protected:
    virtual void onConnect();
    virtual void onReceive(std::unique_ptr<IpcMessage::IIpcMessage> msg);
    virtual void onDisconnect();
};
}

#endif // _CHATMANAGEMENTCHATMGTCONNECTIONRECEIVER_H_
