#include "ListEventQueue.h"
#include "IEvent.h"
#include "AppConst.h"
#include "Trace.h"
#include "TimeStat.h"


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
    TimeHandler::TimeStat totalStat;
    while (!eventsList_.empty())
    {
        TimeHandler::TimeStat singleStat;
        IEvent* event = eventsList_.front();
        eventsList_.pop_front();
        event->run();
        uint64_t singleTimerElapse = singleStat.getElapseTimeAsMilliSecond();
        if (singleTimerElapse > MaxRunningDurationForSingleTimer)
        {
            TRACE_WARNING("Event is executing more than " << MaxRunningDurationForSingleEvent
                         << "ms, Timer Information" << event);
        }

        delete event;
    }

    uint64_t totalElapse = totalStat.getElapseTimeAsMilliSecond();
    if (totalElapse > MaxRunningDurationForEventsInOneLoop)
    {
        TRACE_DEBUG("Timers is executing more than " << MaxRunningDurationForTimersInOneLoop << "ms");
    }
}

std::ostream& ListEventQueue::operator<<(std::ostream& os)
{

}

}
