#ifndef _IPCMESSAGE_IIPCMESSAGE_H_
#define _IPCMESSAGE_IIPCMESSAGE_H_
#include "IpcMessageType.h"
#include "IConnectionMessage.h"
#include <stdint.h>

namespace Serialize
{
class WriteBuffer;
class ReadBuffer;
}

namespace IpcMessage {

class IIpcMessage
{
    uint64_t messageId_;
public:
    IIpcMessage();
    virtual ~IIpcMessage();
    virtual uint64_t getMessageId() const;
    virtual IpcMessageType getMessageType() const = 0;
    virtual void serialize(Serialize::WriteBuffer& writeBuffer) const = 0;
    virtual void unserialize(Serialize::ReadBuffer& readBuffer) = 0;
};

}

#endif // _IPCMESSAGE_IIPCMESSAGE_H_
