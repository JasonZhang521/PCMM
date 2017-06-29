#ifndef _IO_IOCONTROLEVENT_H_
#define _IO_IOCONTROLEVENT_H_
#include "SocketWrapperDef.h"
#include "IIoControl.h"
#include "Component.h"
#include "Macro.h"
#include <map>

namespace Io {

struct IoFdEvent
{
    IoFdEvent() : fdType(IoFdNoType), fdEvent(nullptr) {}
    IoFdEvent(IoFdType type, IIoEvent* event) : fdType(type), fdEvent(event) {}
    uint32_t fdType;
    IIoEvent* fdEvent;
};
using IoFdEventMap = std::map<int, IoFdEvent>;


class IoControlEventsHandler : public IIoControl
{
    SocketFdSet readFds_;
    SocketFdSet writeFds_;
    SocketFdSet exceptFds_;
    IoFdEventMap fdEventMap_;
public:
    IoControlEventsHandler();
    virtual ~IoControlEventsHandler();
protected:
    virtual void registerIoFd(IoFdType type, IIoEvent* event);
    virtual void unRegisterIoFd(int fd, IoFdType type);
    virtual void run();
    virtual std::ostream& operator<< (std::ostream& os) const;
private:
    void addToFdSet(int fd, uint32_t type);
    void removeFromFdSet(int fd, uint32_t type);

    void clearFdSet(uint32_t type);
    void clearAllFdSet();

public:
     GETCLASSNAME(IoControlEvent)
};

}

#endif // _IO_IOCONTROLEVENT_H_
