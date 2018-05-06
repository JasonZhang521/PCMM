#ifndef _IPCMESSAGE_IPCLAYERMESSAGEFACTORY_H_
#define _IPCMESSAGE_IPCLAYERMESSAGEFACTORY_H_
#include "IIpcMessageFactory.h"

namespace IpcMessage {
class IpcLayerMessageFactory : public IIpcMessageFactory
{
public:
    IpcLayerMessageFactory();
    virtual ~IpcLayerMessageFactory();
    virtual IIpcMessage* createMessage(IpcMessageApplicationIntType type) const;
};

}

#endif // _IPCMESSAGE_IPCLAYERMESSAGEFACTORY_H_
