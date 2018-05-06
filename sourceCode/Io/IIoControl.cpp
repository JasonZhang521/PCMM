#include "IIoControl.h"
#include "IIoEvent.h"
#include "Component.h"
#include "Macro.h"
#include "Generic.h"
#include "Trace.h"
#include <string>


namespace Io {


GETCLASSNAME(IIoControl)

IIoControl::IIoControl()
{
}

IIoControl::~IIoControl()
{
}


void IIoControl::registerIoFd(IoFdType type, IIoEvent* event)
{
    int fd = event->getIoHandle();
    TRACE_NOTICE("fd = " << fd << ", type = " << type << ", event = " << event << ", isRunnint = " << isRunning_);
    if (!isRunning_)
    {
        IoFdEventMap::iterator it = fdEventMap_.find(fd);
        if (it != fdEventMap_.end())
        {
            IoFdEvent& event = it->second;
            // Has the same type, already registered.
            if ((event.fdType & type) != IoFdType::IoFdNoType)
            {
                TRACE_NOTICE("fd = " << fd << ", IoFdType = " << static_cast<int>(type) << " has already registered!");
                return;
            }
            else // Update the event type.
            {
                event.fdType = (event.fdType | type);
                updateEvent(fd, type);
            }
        }
        else // Not registered, add to the map and set the type.
        {
            fdEventMap_.insert(std::pair<int, IoFdEvent>(fd, IoFdEvent(type, event)));
            addEvent(fd, type);
        }
    }
    else
    {
        // If event is running, add to the cache.
        // This is happened when running an event, during the running, need to register a fd.
        // This maybe will make the fdEventMap_ iterator invalid in run function.
        ioEventsCacheList_.push_back(IoEventCache(IoEventCache::Register, fd, event, type));
    }
}

void IIoControl::unRegisterIoFd(IoFdType type, int fd)
{
    TRACE_NOTICE("fd = " << fd << ", type = " << static_cast<int>(type));
    if (!isRunning_)
    {
        IoFdEventMap::iterator it = fdEventMap_.find(fd);
        if (it != fdEventMap_.end())
        {
            IoFdEvent& event = it->second;
            event.fdType &= ~type;
            if (event.fdType == IoFdType::IoFdNoType)
            {
                fdEventMap_.erase(it);
            }

            removeEvent(fd, type);
        }
    }
    else
    {
        ioEventsCacheList_.push_back(IoEventCache(IoEventCache::UnRegister, fd, nullptr, type));
    }
}

void IIoControl::refreshIoEvents()
{
    if (isRunning_)
    {
       TRACE_WARNING("Can not refresh ioEvent during running!");
       return;
    }

    for (IoEventsCacheList::iterator it = ioEventsCacheList_.begin(); it != ioEventsCacheList_.end(); ++it)
    {
        IoEventCache& ioEventCache = *it;
        if (ioEventCache.op_ == IoEventCache::Register)
        {
            registerIoFd(ioEventCache.type_, ioEventCache.event_);
        }
        else if (ioEventCache.op_ == IoEventCache::UnRegister)
        {
            unRegisterIoFd(ioEventCache.type_, ioEventCache.fd_);
        }
        else
        {
            TRACE_WARNING("unkown event operator: eventId = " << ioEventCache.fd_ << ", operator = " << static_cast<int>(ioEventCache.op_));
        }
    }
    ioEventsCacheList_.clear();
}


}
