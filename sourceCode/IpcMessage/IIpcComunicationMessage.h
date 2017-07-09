#ifndef IIPCCOMUNICATIONMESSAGE_H
#define IIPCCOMUNICATIONMESSAGE_H
#include "IIpcMessage.h"
#include "IpcMessageType.h"

namespace IpcMessage {

class IIpcComunicationMessage : public IIpcMessage
{
public:
    IIpcComunicationMessage();
    virtual ~IIpcComunicationMessage();
    virtual IpcMessage::IpcMessageType getMessageType() const;
    virtual void serialize(Serialize::WriteBuffer& writeBuffer) const = 0;
    virtual void unserialize(Serialize::ReadBuffer& readBuffer) = 0;

    virtual IpcMessage::IpcComunicationMessageType getComunicationMessageType() const = 0;
    virtual std::ostream& operator<< (std::ostream& os) const = 0;
};
}

#endif // IIPCCOMUNICATIONMESSAGE_H
