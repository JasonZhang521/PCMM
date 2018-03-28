#ifndef _CHATSESSIONMESSAGE_CHATAUTORIZATIONREQUEST_H_
#define _CHATSESSIONMESSAGE_CHATAUTORIZATIONREQUEST_H_
#include "IChatMessage.h"
#include <string>

namespace ChatSessionMessage {
class ChatAuthorizationRequest : public IChatMessage
{
    std::string userName_;
    std::string secret_;
public:
    ChatAuthorizationRequest();
    virtual ~ChatAuthorizationRequest();

protected:
    virtual void serialize(Serialize::WriteBuffer& writeBuffer) const;
    virtual void unserialize(Serialize::ReadBuffer& readBuffer);

    virtual IpcMessage::IpcChatMessageType getChatMessageType() const;
    virtual std::ostream& operator<< (std::ostream& os) const;
};

}

#endif // CHATREGISTERMESSAGE_H
