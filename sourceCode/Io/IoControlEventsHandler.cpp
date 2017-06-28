#include "IoControlEventsHandler.h"
#include "SocketWrapper.h"
#include "EventIdGenerator.h"
#include "IIoEvent.h"
#include "Generic.h"
#include <string>
#include "Trace.h"

namespace Io {

IoControlEventsHandler::IoControlEventsHandler()
{
    IoPlatformWrapper::FdZero(&readFds_);
    IoPlatformWrapper::FdZero(&writeFds_);
    IoPlatformWrapper::FdZero(&exceptFds_);
}

IoControlEventsHandler::~IoControlEventsHandler()
{
    IoPlatformWrapper::FdZero(&readFds_);
    IoPlatformWrapper::FdZero(&writeFds_);
    IoPlatformWrapper::FdZero(&exceptFds_);
}

void IoControlEventsHandler::registerIoFd(IoFdType type, IIoEvent* event)
{
    int fd = event->getIoHandle();
    TRACE_NOTICE("fd = " << fd << ", type = " << type << ", event = " << event);

    IoFdEventMap::iterator it = fdEventMap_.find(fd);
    if (it != fdEventMap_.end())
    {
        IoFdEvent& event = it->second;
        if ((event.fdType & type) != IoFdType::IoFdNoType)
        {
            TRACE_NOTICE("fd = " << fd << ", IoFdType = " << static_cast<int>(type) << " has already registered!");
            return;
        }
        else
        {
            event.fdType = (event.fdType | type);
            addToFdSet(fd, type);
        }
    }
    else
    {
        fdEventMap_[fd] = IoFdEvent(type, event);
        addToFdSet(fd, type);
    }
}

void IoControlEventsHandler::unRegisterIoFd(int fd, IoFdType type)
{
    TRACE_NOTICE("fd = " << fd << ", type = " << static_cast<int>(type));

    IoFdEventMap::iterator it = fdEventMap_.find(fd);
    if (it != fdEventMap_.end())
    {
        IoFdEvent& event = it->second;
        event.fdType &= ~type;
        if (event.fdType == IoFdType::IoFdNoType)
        {
            fdEventMap_.erase(it);
        }

        removeFromFdSet(fd, type);
    }
}

void IoControlEventsHandler::run()
{
    TRACE_ENTER();
    if (fdEventMap_.empty())
    {
        TRACE_WARNING("No fd to be handled!");
    }
    IoFdEventMap::reverse_iterator rit = fdEventMap_.rbegin();
    int maxFdNum = rit->first + 1;
    SocketTimeVal timeout;
    timeout.tv_sec = 0;
    timeout.tv_usec = 500;
    IoPlatformWrapper::Select(maxFdNum, &readFds_, &writeFds_, &exceptFds_, &timeout);

    for (; rit != fdEventMap_.rend(); ++rit)
    {
        int fd = rit->first;
        IIoEvent* event = rit->second.fdEvent;
        uint32_t fdType = rit->second.fdType;
        if (fdType & IoFdType::IoFdRead && IoPlatformWrapper::FdIsSet(fd, &readFds_))
        {
            event->run(EventHandler::EventFlag::Event_IoRead);
        }

        if (fdType & IoFdType::IoFdWrite && IoPlatformWrapper::FdIsSet(fd, &writeFds_))
        {
            event->run(EventHandler::EventFlag::Event_IoWrite);
        }

        if (fdType & IoFdType::IoFdExcept && IoPlatformWrapper::FdIsSet(fd, &exceptFds_))
        {
            event->run(EventHandler::EventFlag::Event_IoExcept);
        }
    }
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

void IoControlEventsHandler::addToFdSet(int fd, IoFdType type)
{
    if (type & IoFdType::IoFdRead)
    {
        IoPlatformWrapper::FdSet(fd, &readFds_);
    }
    else if(type & IoFdType::IoFdWrite)
    {
        IoPlatformWrapper::FdSet(fd, &writeFds_);
    }
    else if (type & IoFdType::IoFdExcept)
    {
        IoPlatformWrapper::FdSet(fd, &exceptFds_);
    }
    else
    {
        throw std::invalid_argument(std::string("Invalid fd type: ") + lexical_cast<std::string>(static_cast<uint32_t>(type)));
    }
}

void IoControlEventsHandler::removeFromFdSet(int fd, IoFdType type)
{
    if (type & IoFdType::IoFdRead)
    {
        IoPlatformWrapper::FdClear(fd, &readFds_);
    }
    else if(type & IoFdType::IoFdWrite)
    {
        IoPlatformWrapper::FdClear(fd, &writeFds_);
    }
    else if (type & IoFdType::IoFdExcept)
    {
        IoPlatformWrapper::FdClear(fd, &exceptFds_);
    }
    else
    {
        throw std::invalid_argument(std::string("Invalid fd type: ") + lexical_cast<std::string>(static_cast<uint32_t>(type)));
    }
}

}
