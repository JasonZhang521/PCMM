#ifndef _CHATSESSIONMESSAGE_ICHATMESSAGE_H_
#define _CHATSESSIONMESSAGE_ICHATMESSAGE_H_
#include "IIpcMessage.h"
#include <vector>
#include "stdint.h"


namespace ChatSessionMessage {
using GroupDestination = std::vector<Network::IpSocketEndpoint>;
class IChatMessage : public IpcMessage::IIpcMessage
{
    GroupDestination groupDestination_;
public:
    IChatMessage();
    virtual ~IChatMessage();
    virtual IpcMessage::IpcMessageType getMessageType() const;
    virtual void serialize(Serialize::WriteBuffer& writeBuffer) const = 0;
    virtual void unserialize(Serialize::ReadBuffer& readBuffer) = 0;

    virtual IpcMessage::IpcChatMessageType getChatMessageType() const = 0;
    virtual std::ostream& operator<< (std::ostream& os) const = 0;

    //Common function
    const GroupDestination& getGroupDestination() const;

protected:
    void write(Serialize::WriteBuffer& writeBuffer) const;
    void read(Serialize::ReadBuffer& readBuffer);
    void print(std::ostream& os) const;
};

}

#endif // _CHATSESSIONMESSAGE_ICHATMESSAGE_H_
