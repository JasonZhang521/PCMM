#ifndef _IPCMESSAGE_IIPCMESSAGEQUEUE_H_
#define _IPCMESSAGE_IIPCMESSAGEQUEUE_H_
#include <memory>

namespace IpcMessage {
class IIpcMessage;

class IIpcMessageQueue
{
public:
    IIpcMessageQueue();
    virtual ~IIpcMessageQueue();
    virtual bool isEmpty() = 0;
    virtual size_t getSize() = 0;
    virtual std::unique_ptr<IIpcMessage> popFront() = 0;
    virtual void pushBack(std::unique_ptr<IIpcMessage> msg) = 0;
};

}

#endif // _IPCMESSAGE_IIPCMESSAGEQUEUE_H_
