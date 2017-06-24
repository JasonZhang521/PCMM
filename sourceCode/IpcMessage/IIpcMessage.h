#ifndef _IPCMESSAGE_IIPCMESSAGE_H_
#define _IPCMESSAGE_IIPCMESSAGE_H_
#include "IpcMessageType.h"
#include <stdint.h>
#include <string>
#include <ostream>

namespace Serialize
{
class WriteBuffer;
class ReadBuffer;
}

namespace IpcMessage {

class IIpcMessage
{
    uint64_t messageId_;
    std::string destnation_;
public:
    IIpcMessage();
    virtual ~IIpcMessage();
    virtual uint64_t getMessageId() const;
    virtual const std::string& getDestnation() const;
    virtual void setDestnation(const std::string& destnation);
    virtual IpcMessageType getMessageType() const = 0;
    virtual void serialize(Serialize::WriteBuffer& writeBuffer) const = 0;
    virtual void unserialize(Serialize::ReadBuffer& readBuffer) = 0;
    virtual std::ostream& operator<< (std::ostream& os) const = 0;
};

}

inline std::ostream& operator<< (std::ostream& os, const IpcMessage::IIpcMessage& msg)
{
    msg.operator<< (os);
    return os;
}

#endif // _IPCMESSAGE_IIPCMESSAGE_H_
