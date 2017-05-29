#ifndef _IO_IOCONTROLEVENT_H_
#define _IO_IOCONTROLEVENT_H_
#include "IIoControl.h"
#include "IEvent.h"
#include <map>

namespace Io {

using IoFdEventMap = std::map<int, EventHandler::IEvent*>;
class IoControlEvent : public IIoControl, public EventHandler::IEvent
{
    IoFdEventMap fdEventMap;
public:
    IoControlEvent();
    virtual ~IoControlEvent();
    virtual void registerIoFd(int fd, EventHandler::IEvent* IEvent);
    virtual void unRegisterIoFd(int fd);
    virtual uint64_t getEventId() const;
    virtual void run(EventHandler::EventFlag flag = EventHandler::EventFlag::Event_NoFlag);
    virtual std::ostream& operator<< (std::ostream& os) const;
};

}

#endif // _IO_IOCONTROLEVENT_H_
