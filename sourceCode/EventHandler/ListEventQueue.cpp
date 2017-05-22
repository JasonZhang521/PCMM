#include "ListEventQueue.h"
#include "IEvent.h"

namespace EventHandler {

ListEventQueue::ListEventQueue()
{
}

ListEventQueue::~ListEventQueue()
{
    for (EventList::iterator it = eventsList_.begin(); it != eventsList_.end(); ++it)
    {
        delete (*it);
    }
}

void ListEventQueue::AddEvent(IEvent* event)
{
    eventsList_.push_back(event);
}

void ListEventQueue::deleteEvent(uint64_t eventID)
{
    for (EventList::iterator it = eventsList_.begin(); it != eventsList_.end(); ++it)
    {
        if (eventID == (*it)->getEventId())
        {
            eventsList_.erase(it);
            delete (*it);
            return;
        }
    }
}

void ListEventQueue::executeEvents()
{

}

std::ostream& ListEventQueue::operator<<(std::ostream& os)
{

}

}
