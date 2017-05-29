#include "IoControlEvent.h"

namespace Io {

IoControlEvent::IoControlEvent()
{

}

IoControlEvent::~IoControlEvent()
{

}

void IoControlEvent::registerIoFd(int fd, EventHandler::IEvent* IEvent)
{

}

void IoControlEvent::unRegisterIoFd(int fd)
{

}

uint64_t IoControlEvent::getEventId() const
{

}

void IoControlEvent::run(EventHandler::EventFlag flag)
{

}

std::ostream& IoControlEvent::operator<< (std::ostream& os) const
{

}

}
