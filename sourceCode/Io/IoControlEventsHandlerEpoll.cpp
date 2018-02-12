#include "IoControlEventsHandlerEpoll.h"
#include "SocketWrapper.h"
#include "IEvent.h"
#include "IIoEvent.h"
#include "Component.h"
#include "Macro.h"

#ifndef WIN32
namespace Io {

GETCLASSNAME(IoControlEventsHandlerEpoll)

IoControlEventsHandlerEpoll::IoControlEventsHandlerEpoll()
{
    epollFds_.reserve(NumOfEpollFds);
    for (size_t i = 0; i < NumOfEpollFds; ++i)
    {
        epollFds_[i] = PlatformWrapper::EpollCreate(MaxNumOfFdsEachEpollFd);
    }
}

IoControlEventsHandlerEpoll::~IoControlEventsHandlerEpoll()
{
    for (size_t i = 0; i < NumOfEpollFds; ++i)
    {
		PlatformWrapper::EpollClose(epollFds_[i]);
    }
}

void IoControlEventsHandlerEpoll::run()
{
    SocketEpollEventStruct events[MaxListenEvents];
    isRunning_ = true;
    for (size_t i = 0; i < NumOfEpollFds; ++i)
    {
        int numberOfEvents = PlatformWrapper::EpollWait(epollFds_[i],events,MaxListenEvents,0);

        for (size_t j = 0; j < numberOfEvents; ++j)
        {
            if (events[j].events & SOCKET_EPOLLIN)
            {
                IIoEvent* event = reinterpret_cast<IIoEvent*>(events[j].data.ptr);
                event->run(EventHandler::EventFlag::Event_IoRead);
            }

            if (events[j].events & SOCKET_EPOLLOUT)
            {
                IIoEvent* event = reinterpret_cast<IIoEvent*>(events[j].data.ptr);
                event->run(EventHandler::EventFlag::Event_IoWrite);
            }

            if (events[j].events & SOCKET_EPOLLERR)
            {
                IIoEvent* event = reinterpret_cast<IIoEvent*>(events[j].data.ptr);
                event->run(EventHandler::EventFlag::Event_IoExcept);
            }
        }
    }
    isRunning_ = false;

    refreshIoEvents();
}

std::ostream& IoControlEventsHandlerEpoll::operator<< (std::ostream& os) const
{
    return os;
}

void IoControlEventsHandlerEpoll::addEvent(int fd, uint32_t type)
{
    SocketEpollFd& epollFd = epollFds_[fd % NumOfEpollFds];
    SocketEpollEventStruct ev;

    ev.data.fd = fd;
    ev.data.ptr = fdEventMap_[fd].fdEvent;
    if (type & IoFdType::IoFdRead)
    {
        ev.events = SOCKET_EPOLLIN;
        PlatformWrapper::EpollCtl(epollFd, SocketEpollCtlAdd, fd, &ev);
    }

    if(type & IoFdType::IoFdWrite)
    {
        ev.events = SOCKET_EPOLLOUT;
        PlatformWrapper::EpollCtl(epollFd, SocketEpollCtlAdd, fd, &ev);
    }

    if (type & IoFdType::IoFdExcept)
    {
        ev.events = SOCKET_EPOLLERR;
        PlatformWrapper::EpollCtl(epollFd, SocketEpollCtlAdd, fd, &ev);
    }
}

void IoControlEventsHandlerEpoll::updateEvent(int fd, uint32_t type)
{
    SocketEpollFd& epollFd = epollFds_[fd % NumOfEpollFds];
    SocketEpollEventStruct ev;

    ev.data.fd = fd;
    if (type & IoFdType::IoFdRead)
    {
        ev.events = SOCKET_EPOLLIN;
        PlatformWrapper::EpollCtl(epollFd, SocketEpollCtlMod, fd, &ev);
    }

    if(type & IoFdType::IoFdWrite)
    {
        ev.events = SOCKET_EPOLLOUT;
        PlatformWrapper::EpollCtl(epollFd, SocketEpollCtlMod, fd, &ev);
    }

    if (type & IoFdType::IoFdExcept)
    {
        ev.events = SOCKET_EPOLLERR;
        PlatformWrapper::EpollCtl(epollFd, SocketEpollCtlMod, fd, &ev);
    }
}

void IoControlEventsHandlerEpoll::removeEvent(int fd, uint32_t type)
{
    SocketEpollFd& epollFd = epollFds_[fd % NumOfEpollFds];
    SocketEpollEventStruct ev;

    ev.data.fd = fd;
    if (type & IoFdType::IoFdRead)
    {
        ev.events = SOCKET_EPOLLIN;
        PlatformWrapper::EpollCtl(epollFd, SocketEpollCtlDel, fd, &ev);
    }

    if(type & IoFdType::IoFdWrite)
    {
        ev.events = SOCKET_EPOLLOUT;
        PlatformWrapper::EpollCtl(epollFd, SocketEpollCtlDel, fd, &ev);
    }

    if (type & IoFdType::IoFdExcept)
    {
        ev.events = SOCKET_EPOLLERR;
        PlatformWrapper::EpollCtl(epollFd, SocketEpollCtlDel, fd, &ev);
    }
}

}

#endif // WIN32
