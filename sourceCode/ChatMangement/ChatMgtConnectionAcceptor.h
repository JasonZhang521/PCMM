#ifndef _CHATMANAGEMENTCHATMGTCONNECTIONACCEPTOR_H_
#define _CHATMANAGEMENTCHATMGTCONNECTIONACCEPTOR_H_
#include <memory>
#include "IIpcConnectionAcceptor.h"

namespace ChatManagement {

class IChatMgtControl;

class ChatMgtConnectionAcceptor : public Ipc::IIpcConnectionAcceptor
{
    IChatMgtControl& chatMgtControl_;
public:
    ChatMgtConnectionAcceptor(IChatMgtControl& chatMgtControl);
    virtual ~ChatMgtConnectionAcceptor();
protected:
    virtual void onAccept(int fd,
                          const Network::IpSocketEndpoint& localEndPoint,
                          const Network::IpSocketEndpoint& remoteEndPoint);

private:
    void createChatConnection(int fd,
                                 const Network::IpSocketEndpoint& localEndPoint,
                                 const Network::IpSocketEndpoint& remoteEndPoint);
};

}

#endif // _CHATMANAGEMENTCHATMGTCONNECTIONACCEPTOR_H_
