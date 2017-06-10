#ifndef ISYSTEMMONITORMESSAGE_H
#define ISYSTEMMONITORMESSAGE_H
#include "IIpcMessage.h"
namespace SystemMonitorMessage {

class ISystemMonitorMessage : public IpcMessage::IIpcMessage
{
public:
    ISystemMonitorMessage();
    virtual ~ISystemMonitorMessage();
    virtual IpcMessage::IpcMessageType getMessageType() const;
    virtual void serialize(Serialize::WriteBuffer& writeBuffer) const = 0;
    virtual void unserialize(Serialize::ReadBuffer& readBuffer) = 0;
};

}
#endif // ISYSTEMMONITORMESSAGE_H
