#ifndef CHATMGTCONNECTIONACCEPTOR_H
#define CHATMGTCONNECTIONACCEPTOR_H
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

#endif // CHATMGTCONNECTIONACCEPTOR_H
