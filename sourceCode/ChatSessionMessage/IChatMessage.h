#ifndef _CHATSESSIONMESSAGE_ICHATMESSAGE_H_
#define _CHATSESSIONMESSAGE_ICHATMESSAGE_H_
#include "IIpcMessage.h"
#include "stdint.h"

namespace ChatSessionMessage {

class IChatMessage : public IpcMessage::IIpcMessage
{
public:
    IChatMessage();
    virtual ~IChatMessage();
    virtual IpcMessage::IpcMessageType getMessageType() const;
    virtual void serialize(Serialize::WriteBuffer& writeBuffer) const = 0;
    virtual void unserialize(Serialize::ReadBuffer& readBuffer) = 0;

    virtual IpcMessage::IpcChatMessageType getChatMessageType() const = 0;
    virtual std::ostream& operator<< (std::ostream& os) const = 0;
};

}

#endif // _CHATSESSIONMESSAGE_ICHATMESSAGE_H_
