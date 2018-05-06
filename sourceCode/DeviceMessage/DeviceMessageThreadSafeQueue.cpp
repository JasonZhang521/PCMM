#include "DeviceMessageThreadSafeQueue.h"
#include "IDeviceMessage.h"
#include "Lock.h"
namespace DeviceMessage {
DeviceMessageThreadSafeQueue::DeviceMessageThreadSafeQueue()
{

}

DeviceMessageThreadSafeQueue::~DeviceMessageThreadSafeQueue()
{

}

bool DeviceMessageThreadSafeQueue::isEmpty()
{
    Lock lock(mutex_);
    return messageList_.empty();
}

size_t DeviceMessageThreadSafeQueue::getSize()
{
    Lock lock(mutex_);
    return messageList_.size();
}

std::unique_ptr<IDeviceMessage> DeviceMessageThreadSafeQueue::popFront()
{
    Lock lock(mutex_);
    if (!messageList_.empty())
    {
        std::unique_ptr<IDeviceMessage> msg = std::move(messageList_.front());
        messageList_.pop_front();
        return msg;
    }
    else
    {
        return nullptr;
    }
}

void DeviceMessageThreadSafeQueue::pushBack(std::unique_ptr<IDeviceMessage> msg)
{
    Lock lock(mutex_);
    messageList_.push_back(std::move(msg));
}
}
