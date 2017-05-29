#ifndef _IO_IIOCONTROL_H_
#define _IO_IIOCONTROL_H_

namespace EventHandler {
    class IEvent;
}

namespace Io {

class IIoControl
{
public:
    IIoControl();
    virtual ~IIoControl();
    virtual void registerIoFd(int fd, EventHandler::IEvent* IEvent) = 0;
    virtual void unRegisterIoFd(int fd) = 0;
};

}

#endif // _IO_IIOCONTROL_H_
