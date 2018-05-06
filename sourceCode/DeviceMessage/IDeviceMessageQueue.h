#ifndef _DEVICEMESSAGE_IDEVICEMESSAGEQUEUE_H_
#define _DEVICEMESSAGE_IDEVICEMESSAGEQUEUE_H_
#include <memory>
namespace DeviceMessage {
class IDeviceMessage;
class IDeviceMessageQueue
{
public:
    IDeviceMessageQueue();
    virtual ~IDeviceMessageQueue();
    virtual bool isEmpty() = 0;
    virtual size_t getSize() = 0;
    virtual std::unique_ptr<IDeviceMessage> popFront() = 0;
    virtual void pushBack(std::unique_ptr<IDeviceMessage> msg) = 0;
};
}

#endif // _DEVICEMESSAGE_IDEVICEMESSAGEQUEUE_H_
