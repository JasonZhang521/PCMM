#ifndef _IO_IIOCONTROL_H_
#define _IO_IIOCONTROL_H_

namespace EventHandler {
    class IEvent;
}

namespace Io {

enum IoFdType
{
    IoFdNoType = 0,
    IoFdRead = 1,
    IoFdWrite = 1 << 2,
    IoFdExcept = 1 << 3
};

class IIoControl
{
public:
    IIoControl();
    virtual ~IIoControl();
    virtual void registerIoFd(int fd, IoFdType type, EventHandler::IEvent* IEvent) = 0;
    virtual void unRegisterIoFd(int fd) = 0;
};

}

#endif // _IO_IIOCONTROL_H_
