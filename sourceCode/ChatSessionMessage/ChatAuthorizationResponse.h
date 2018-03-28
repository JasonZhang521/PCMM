#ifndef _CHATSESSIONMESSAGE_CHATAUTORIZATIONRESPONSE_H_
#define _CHATSESSIONMESSAGE_CHATAUTORIZATIONRESPONSE_H_
#include "IChatMessage.h"

namespace ChatSessionMessage {

class ChatAuthorizationResponse : public IChatMessage
{
public:
    enum AuthorizationResult
    {
        Authorized= 0,
        WrongUserName = -1,
        WrongSecret = -2
    };
    static std::string resultToString(AuthorizationResult result);
private:
    AuthorizationResult result_;
public:
    ChatAuthorizationResponse();
    virtual ~ChatAuthorizationResponse();

protected:
    virtual void serialize(Serialize::WriteBuffer& writeBuffer) const;
    virtual void unserialize(Serialize::ReadBuffer& readBuffer);

    virtual IpcMessage::IpcChatMessageType getChatMessageType() const;
    virtual std::ostream& operator<< (std::ostream& os) const;
};

}

#endif // _CHATSESSIONMESSAGE_CHATAUTORIZATIONRESPONSE_H_
