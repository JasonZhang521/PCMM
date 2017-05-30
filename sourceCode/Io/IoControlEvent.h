#ifndef _IO_IOCONTROLEVENT_H_
#define _IO_IOCONTROLEVENT_H_
#include "SocketWrapperDef.h"
#include "IIoControl.h"
#include "IEvent.h"
#include "Component.h"
#include "Macro.h"
#include <map>

namespace Io {

struct IoFdEvent
{
    IoFdEvent(IoFdType type, EventHandler::IEvent* event) : fdType(type), fdEvent(event) {}
    IoFdType fdType;
    EventHandler::IEvent* fdEvent;
};
using IoFdEventMap = std::map<int, IoFdEvent>;


class IoControlEvent : public IIoControl, public EventHandler::IEvent
{
    uint64_t eventId_;
    SocketFdSet readFds_;
    SocketFdSet writeFds_;
    SocketFdSet exceptFds_;
    IoFdEventMap fdEventMap_;
public:
    IoControlEvent();
    virtual ~IoControlEvent();
    virtual void registerIoFd(int fd, IoFdType type, EventHandler::IEvent* IEvent);
    virtual void unRegisterIoFd(int fd);
    virtual uint64_t getEventId() const;
    virtual void run(EventHandler::EventFlag flag = EventHandler::EventFlag::Event_NoFlag);
    virtual std::ostream& operator<< (std::ostream& os) const;

public:
     GETCLASSNAME(SocketImp)
};

}

#endif // _IO_IOCONTROLEVENT_H_
