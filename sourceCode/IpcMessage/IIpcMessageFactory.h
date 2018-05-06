#ifndef _IPCMESSAGE_IIPCMESSAGEFACTORY_H_
#define _IPCMESSAGE_IIPCMESSAGEFACTORY_H_
#include "IpcMessageType.h"
#include <stdint.h>

namespace IpcMessage {

class IIpcMessage;
using IpcMessageApplicationIntType = uint8_t;

class IIpcMessageFactory
{
public:
    IIpcMessageFactory();
    IIpcMessageFactory(IpcMessageType type);
    virtual ~IIpcMessageFactory();
    virtual IIpcMessage* createMessage(IpcMessageApplicationIntType type) const = 0;
    virtual IpcMessageType messageType();

private:
    IpcMessageType type_;
};

}

#endif // _IPCMESSAGE_IIPCMESSAGEFACTORY_H_
