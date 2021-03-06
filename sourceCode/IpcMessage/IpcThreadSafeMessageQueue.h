#ifndef _IPCMESSAGE_IPCTHREADSAFEMESSAGEQUEUE_H_
#define _IPCMESSAGE_IPCTHREADSAFEMESSAGEQUEUE_H_
#include "IIpcMessageQueue.h"
#include <list>
#include <mutex>

namespace IpcMessage {
class IIpcMessage;
class IpcThreadSafeMessageQueue : public IIpcMessageQueue
{
    using MessageList = std::list<std::unique_ptr<IIpcMessage> >;
    MessageList messageList_;
    std::mutex mutex_;
public:
    IpcThreadSafeMessageQueue();
    ~IpcThreadSafeMessageQueue();
    virtual bool isEmpty();
    virtual size_t getSize();
    virtual std::unique_ptr<IIpcMessage> popFront();
    virtual void pushBack(std::unique_ptr<IIpcMessage> msg);
};

}
#endif // _IPCMESSAGE_IPCTHREADSAFEMESSAGEQUEUE_H_
