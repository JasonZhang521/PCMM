#ifndef _CHATSESSIONMESSAGE_CHATLOGINRESPONSE_H_
#define _CHATSESSIONMESSAGE_CHATLOGINRESPONSE_H_
#include "IChatMessage.h"

namespace ChatSessionMessage {
class ChatLoginResponse : public IChatMessage
{
public:
    ChatLoginResponse();
    virtual ~ChatLoginResponse();
};
}
#endif // _CHATSESSIONMESSAGE_CHATLOGINRESPONSE_H_
