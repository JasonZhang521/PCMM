#ifndef IIOCONTROL_H
#define IIOCONTROL_H

namespace EventHandler {
    class IEvent;
}

namespace Io {

class IIoControl
{
public:
    IIoControl();
    void registerIoFd(int fd, EventHandler::IEvent* IEvent);
    void unRegisterIoFd(int fd);
};

}

#endif // IIOCONTROL_H
