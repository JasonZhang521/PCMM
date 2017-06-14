#include "IoLoop.h"
#include "ITimerQueue.h"
namespace Core {

IoLoop::IoLoop(std::shared_ptr<Io::IIoControl> ioControl)
    :ioControl_(ioControl)
{

}

void IoLoop::runLoop(unsigned int executeTime)
{
    if (ioControl_)
    {
        ioControl_->run();
    }
}

void IoLoop::registerIo(int fd, Io::IoFdType type, EventHandler::IEvent* event)
{
    if (ioControl_)
    {
        ioControl_->registerIoFd(fd, type, event);
    }
}

void IoLoop::deRegisterIo(int fd)
{
    if (ioControl_)
    {
        ioControl_->unRegisterIoFd(fd);
    }
}

}
