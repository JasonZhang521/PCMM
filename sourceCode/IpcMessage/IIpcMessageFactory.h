#ifndef IIPCMESSAGEFACTORY_H
#define IIPCMESSAGEFACTORY_H
#include <stdint.h>

namespace IpcMessage {

class IIpcMessage;
using IpcMessageIntType = uint8_t;

class IIpcMessageFactory
{
public:
    IIpcMessageFactory();
    virtual ~IIpcMessageFactory();
    virtual IIpcMessage* createMessage(IpcMessageIntType type) const = 0;
};

}

#endif // IIPCMESSAGEFACTORY_H
