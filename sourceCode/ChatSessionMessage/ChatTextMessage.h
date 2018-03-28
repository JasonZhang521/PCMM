#ifndef _CHATSESSIONMESSAGE_CHATTEXTMESSAGE_H_
#define _CHATSESSIONMESSAGE_CHATTEXTMESSAGE_H_
#include "IChatMessage.h"
#include "MessageBuffer.h"

namespace ChatSessionMessage {
class ChatTextMessage : public IChatMessage
{
    MessageBuffer buffer_;
public:
    ChatTextMessage();
    virtual ~ChatTextMessage();

    void setBuffer(const MessageBuffer& buffer);
    const MessageBuffer& getBuffer() const;
protected:
    virtual void serialize(Serialize::WriteBuffer& writeBuffer) const;
    virtual void unserialize(Serialize::ReadBuffer& readBuffer);

    virtual IpcMessage::IpcChatMessageType getChatMessageType() const;
    virtual std::ostream& operator<< (std::ostream& os) const;
};

}

#endif // _CHATSESSIONMESSAGE_CHATTEXTMESSAGE_H_
