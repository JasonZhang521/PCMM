#include "IEvent.h"

namespace EventHandler {

IEvent::IEvent()
{

}

IEvent::~IEvent()
{

}

std::ostream& operator<< (std::ostream& os, const IEvent* event)
{
    event->operator <<(os);
    return os;
}

}
