#ifndef _CHATSESSIONMESSAGE_CHATLOGINREQUEST_H_
#define _CHATSESSIONMESSAGE_CHATLOGINREQUEST_H_
#include "IChatMessage.h"

namespace ChatSessionMessage {
class ChatLoginRequest : public IChatMessage
{
public:
    ChatLoginRequest();
    virtual ~ChatLoginRequest();
};
}

#endif // _CHATSESSIONMESSAGE_CHATLOGINREQUEST_H_
