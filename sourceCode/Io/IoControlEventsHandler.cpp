#include "IoControlEventsHandler.h"
#include "SocketWrapper.h"
#include "EventIdGenerator.h"
#include "IIoEvent.h"
#include "Generic.h"
#include <string>
#include "Component.h"
#include "Macro.h"
#include "Trace.h"

namespace Io {

GETCLASSNAME(IoControlEvent)

IoControlEventsHandler::IoControlEventsHandler()
{
    PlatformWrapper::FdZero(&readFds_);
    PlatformWrapper::FdZero(&writeFds_);
    PlatformWrapper::FdZero(&exceptFds_);
}

IoControlEventsHandler::~IoControlEventsHandler()
{
    PlatformWrapper::FdZero(&readFds_);
    PlatformWrapper::FdZero(&writeFds_);
    PlatformWrapper::FdZero(&exceptFds_);
}

void IoControlEventsHandler::run()
{
    TRACE_ENTER();
    if (fdEventMap_.empty())
    {
        TRACE_DEBUG3("No fd to be handled!");
        refreshIoEvents();
        return;
    }

    isRunning_ = true;

    clearAllFdSet();
    IoFdEventMap::iterator it = fdEventMap_.begin();
    for (; it != fdEventMap_.end(); ++it)
    {
        int fd = it->first;
        const IoFdEvent& event = it->second;
        addToFdSet(fd, event.fdType);
    }

    IoFdEventMap::reverse_iterator rit = fdEventMap_.rbegin();
    int maxFdNum = rit->first + 1;
    SocketTimeVal timeout;
    timeout.tv_sec = 0;
    timeout.tv_usec = 500;
    PlatformWrapper::Select(maxFdNum, &readFds_, &writeFds_, &exceptFds_, &timeout);

    for (; rit != fdEventMap_.rend(); ++rit)
    {
        int fd = rit->first;
        IIoEvent* event = rit->second.fdEvent;
        uint32_t fdType = rit->second.fdType;

        if (fdType & IoFdType::IoFdRead && PlatformWrapper::FdIsSet(fd, &readFds_))
        {
            event->run(EventHandler::EventFlag::Event_IoRead);
        }

        if (fdType & IoFdType::IoFdWrite && PlatformWrapper::FdIsSet(fd, &writeFds_))
        {
            event->run(EventHandler::EventFlag::Event_IoWrite);
        }

        if (fdType & IoFdType::IoFdExcept && PlatformWrapper::FdIsSet(fd, &exceptFds_))
        {
            event->run(EventHandler::EventFlag::Event_IoExcept);
        }
    }

    isRunning_ = false;

    refreshIoEvents();
}

std::ostream& IoControlEventsHandler::operator<< (std::ostream& os) const
{
    os << "[";

    for (IoFdEventMap::const_iterator it = fdEventMap_.cbegin(); it != fdEventMap_.cend(); ++it)
    {
        os << "fd=" << it->first << ", eventType=" << it->second.fdType << ", event=" << it->second.fdEvent;
    }
    os << "]";

    return os;
}

void IoControlEventsHandler::addEvent(int fd, uint32_t type)
{
    addToFdSet(fd, type);
}

void IoControlEventsHandler::updateEvent(int fd, uint32_t type)
{
    addToFdSet(fd, type);
}

void IoControlEventsHandler::removeEvent(int fd, uint32_t type)
{
    removeFromFdSet(fd, type);
}

void IoControlEventsHandler::addToFdSet(int fd, uint32_t type)
{
    if (type & IoFdType::IoFdRead)
    {
        PlatformWrapper::FdSet(fd, &readFds_);
    }

    if(type & IoFdType::IoFdWrite)
    {
        PlatformWrapper::FdSet(fd, &writeFds_);
    }

    if (type & IoFdType::IoFdExcept)
    {
        PlatformWrapper::FdSet(fd, &exceptFds_);
    }
}

void IoControlEventsHandler::clearFdSet(uint32_t type)
{
    if (type & IoFdType::IoFdRead)
    {
        PlatformWrapper::FdZero(&readFds_);
    }

    if(type & IoFdType::IoFdWrite)
    {
        PlatformWrapper::FdZero(&writeFds_);
    }

    if (type & IoFdType::IoFdExcept)
    {
        PlatformWrapper::FdZero(&exceptFds_);
    }
}

void IoControlEventsHandler::clearAllFdSet()
{
    clearFdSet(IoFdType::IoFdRead | IoFdType::IoFdWrite | IoFdType::IoFdExcept);
}

void IoControlEventsHandler::removeFromFdSet(int fd, uint32_t type)
{
    if (type & IoFdType::IoFdRead)
    {
        PlatformWrapper::FdClear(fd, &readFds_);
    }

    if(type & IoFdType::IoFdWrite)
    {
        PlatformWrapper::FdClear(fd, &writeFds_);
    }

    if (type & IoFdType::IoFdExcept)
    {
        PlatformWrapper::FdClear(fd, &exceptFds_);
    }
}

}
