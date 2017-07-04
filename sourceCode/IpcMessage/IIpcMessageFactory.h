#ifndef IIPCMESSAGEFACTORY_H
#define IIPCMESSAGEFACTORY_H
#include "IpcMessageType.h"
#include <stdint.h>

namespace IpcMessage {

class IIpcMessage;
using IpcMessageIntType = uint8_t;

class IIpcMessageFactory
{
public:
    IIpcMessageFactory();
    IIpcMessageFactory(IpcMessageType type);
    virtual ~IIpcMessageFactory();
    virtual IIpcMessage* createMessage(IpcMessageIntType type) const = 0;
    virtual IpcMessageType messageType();

private:
    IpcMessageType type_;
};

}

#endif // IIPCMESSAGEFACTORY_H
