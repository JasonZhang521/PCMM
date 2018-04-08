#ifndef _CHATSESSIONMESSAGE_CHATFILEMESSAGE_H_
#define _CHATSESSIONMESSAGE_CHATFILEMESSAGE_H_
#include <stdint.h>
#include "IChatMessage.h"
#include "MessageBuffer.h"

namespace ChatSessionMessage {
class ChatFileMessage : public IChatMessage
{
    uint32_t fileId_;
    std::string fileName_;
    uint32_t sequence_;
    uint32_t totalFragment_;
    uint32_t startPos_;
    uint32_t endPos_;
    MessageBuffer buffer_;
public:
    ChatFileMessage();
    virtual ~ChatFileMessage();
    void setFileId(uint32_t fileId);
    uint32_t getFileId() const;
    void setFilename(const std::string& fileName);
    const std::string& getFileName() const;
    void setSequence(uint32_t sequence);
    uint32_t getSequence() const;
    void setTotalFragment(uint32_t totalFragment);
    uint32_t getTotalFragment() const;
    void setStartPos(uint32_t startPos);
    uint32_t getStartPos() const;
    void setEndPos(uint32_t endPos);
    uint32_t getEndPos() const;
    void setBuffer(const MessageBuffer& buffer);
    const MessageBuffer& getBuffer() const;

protected:
    virtual void serialize(Serialize::WriteBuffer& writeBuffer) const;
    virtual void unserialize(Serialize::ReadBuffer& readBuffer);

    virtual IpcMessage::IpcChatMessageType getChatMessageType() const;
    virtual std::ostream& operator<< (std::ostream& os) const;

};

}

#endif // CHATFILEMESSAGE_H
