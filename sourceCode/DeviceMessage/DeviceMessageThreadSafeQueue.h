#ifndef _DEVICEMESSAGE_DEVICEMESSAGETHREADSAFEQUEUE_H_
#define _DEVICEMESSAGE_DEVICEMESSAGETHREADSAFEQUEUE_H_
#include "IDeviceMessageQueue.h"
#include <list>
#include <mutex>

namespace DeviceMessage {
class DeviceMessageThreadSafeQueue : public IDeviceMessageQueue
{
    using MessageList = std::list<std::unique_ptr<IDeviceMessage> >;
    MessageList messageList_;
    std::mutex mutex_;
public:
    DeviceMessageThreadSafeQueue();
    ~DeviceMessageThreadSafeQueue();
    virtual bool isEmpty();
    virtual size_t getSize();
    virtual std::unique_ptr<IDeviceMessage> popFront();
    virtual void pushBack(std::unique_ptr<IDeviceMessage> msg);
};
}

#endif // _DEVICEMESSAGE_DEVICEMESSAGETHREADSAFEQUEUE_H_
