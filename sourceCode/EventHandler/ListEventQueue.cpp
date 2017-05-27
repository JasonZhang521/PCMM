#include "ListEventQueue.h"
#include "IEvent.h"
#include "AppConst.h"
#include "Trace.h"
#include "TimeStat.h"
#include <memory>

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
    TimeStat totalStat;
    while (!eventsList_.empty())
    {
        TimeStat singleStat;
        std::unique_ptr<IEvent> event(eventsList_.front());
        eventsList_.pop_front();
        event->run();
        uint64_t singleTimerElapse = singleStat.getElapseTimeAsMilliSecond();
        if (singleTimerElapse > MaxRunningDurationForSingleTimer)
        {
            TRACE_WARNING("Event is executing more than " << MaxRunningDurationForSingleEvent
                         << "ms, Timer Information" << event.get());
        }
    }

    uint64_t totalElapse = totalStat.getElapseTimeAsMilliSecond();
    if (totalElapse > MaxRunningDurationForEventsInOneLoop)
    {
        TRACE_WARNING("Timers is executing more than " << MaxRunningDurationForTimersInOneLoop << "ms");
    }
}

std::ostream& ListEventQueue::operator<<(std::ostream& os) const
{
    os << "[";
    for (EventList::const_iterator it = eventsList_.begin(); it != eventsList_.end(); ++it)
    {
       os << "event=" << *it;
    }
    os << "]";

    return os;
}

}
