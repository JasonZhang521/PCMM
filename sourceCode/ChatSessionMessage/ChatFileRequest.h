#ifndef CHATFILEREQUEST_H
#define CHATFILEREQUEST_H
#include "IChatMessage.h"

namespace ChatSessionMessage {
class ChatFileRequest : public IChatMessage
{
    uint32_t fileId_;
    std::string fileName_;
public:
    ChatFileRequest();
    virtual ~ChatFileRequest();
    void setFileId(uint32_t fileId);
    uint32_t getFileId() const;
    void setFilename(const std::string& fileName);
    const std::string& getFileName() const;

protected:
    virtual void serialize(Serialize::WriteBuffer& writeBuffer) const;
    virtual void unserialize(Serialize::ReadBuffer& readBuffer);

    virtual IpcMessage::IpcChatMessageType getChatMessageType() const;
    virtual std::ostream& operator<< (std::ostream& os) const;
};

}

#endif // CHATFILEREQUEST_H
