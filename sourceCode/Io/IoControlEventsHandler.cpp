#include "IoControlEventsHandler.h"
#include "SocketWrapper.h"
#include "EventIdGenerator.h"
#include "Generic.h"
#include <string>
#include "Trace.h"

namespace Io {

IoControlEventsHandler::IoControlEventsHandler()
    :eventId_(EventHandler::EventIdGenerator::generateEventId())
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

void IoControlEventsHandler::registerIoFd(int fd, IoFdType type, EventHandler::IEvent* event)
{
    TRACE_NOTICE("fd = " << fd << ", type = " << type << ", event = " << event);

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

    fdEventMap_[fd] = IoFdEvent(type, event);
}

void IoControlEventsHandler::unRegisterIoFd(int fd)
{
    TRACE_NOTICE("fd = " << fd);

    IoFdEventMap::iterator it = fdEventMap_.find(fd);
    if (it != fdEventMap_.end())
    {
        const IoFdEvent& event = it->second;
        fdEventMap_.erase(it);

        if (event.fdType & IoFdType::IoFdRead)
        {
            IoPlatformWrapper::FdClear(fd, &readFds_);
        }
        else if(event.fdType & IoFdType::IoFdWrite)
        {
            IoPlatformWrapper::FdClear(fd, &writeFds_);
        }
        else if (event.fdType & IoFdType::IoFdExcept)
        {
            IoPlatformWrapper::FdClear(fd, &exceptFds_);
        }
        else
        {
            return;
        }
    }
}

uint64_t IoControlEventsHandler::getEventId() const
{
    return eventId_;
}

void IoControlEventsHandler::run(EventHandler::EventFlag flag)
{
    TRACE_DEBUG("flag = " << EventFlagString(flag));
    if (fdEventMap_.empty())
    {
        TRACE_WARNING("No fd to be handled!");
    }
    IoFdEventMap::reverse_iterator rit = fdEventMap_.rbegin();
    int maxFdNum = rit->first + 1;
    IoPlatformWrapper::Select(maxFdNum, &readFds_, &writeFds_, &exceptFds_, nullptr);
    for (; rit != fdEventMap_.rend(); ++rit)
    {
        int fd = rit->first;
        EventHandler::IEvent* event = rit->second.fdEvent;
        IoFdType fdType = rit->second.fdType;
        switch (flag) {
        case EventHandler::EventFlag::Event_IoRead:
            if (fdType & IoFdType::IoFdRead && IoPlatformWrapper::FdIsSet(fd, &readFds_))
            {
                event->run(flag);
            }
            break;
        case EventHandler::EventFlag::Event_IoWrite:
            if (fdType & IoFdType::IoFdWrite && IoPlatformWrapper::FdIsSet(fd, &writeFds_))
            {
                event->run(flag);
            }
            break;
        case EventHandler::EventFlag::Event_IoExcept:
            if (fdType & IoFdType::IoFdExcept && IoPlatformWrapper::FdIsSet(fd, &exceptFds_))
            {
                event->run(flag);
            }
            break;
        default:
            TRACE_WARNING("Error Event Flag = " << EventFlagString(flag));
            break;
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

}
