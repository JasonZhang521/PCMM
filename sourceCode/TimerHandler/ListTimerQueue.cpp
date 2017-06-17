#include "ListTimerQueue.h"
#include "ITimer.h"
#include "TimeStat.h"
#include "Component.h"
#include "App.h"
#include "AppConst.h"
#include "Trace.h"

namespace TimerHandler {

ListTimerQueue::ListTimerQueue()
{

}

ListTimerQueue::~ListTimerQueue()
{
}

void ListTimerQueue::addTimer(ITimer* timer)
{
    if (timersList_.empty())
    {
        timersList_.push_back(timer);
        return;
    }
    else
    {
        TimersList::iterator it = timersList_.end();
        TimersList::iterator lastIt = it--;
        for (; it != timersList_.begin(); lastIt = it--)
        {
            const ITimer* timerInList = *it;
            if (timer->getExpiredTime() >= timerInList->getExpiredTime())
            {
                timersList_.insert(lastIt, timer);
                return;
            }
        }
        timersList_.push_front( timer);
    }
}

void ListTimerQueue::deleteTimer(uint64_t timerID)
{
    for (TimersList::iterator it = timersList_.begin(); it != timersList_.end(); ++it)
    {
       ITimer* timerInList = *it;
       if (timerInList->getTimerId() == timerID)
       {
           delete timerInList;
           timersList_.erase(it);
           return;
       }
    }
}

void ListTimerQueue::executeTimers()
{
    TimeStat totalStat;
    for (TimersList::iterator it = timersList_.begin(); it != timersList_.end(); ++it)
    {
        ITimer* timerInList = *it;
        if (timerInList->isExpired())
        {
             TimeStat singleStat;
             timerInList->onTime();
             it = timersList_.erase(it);
             const uint64_t singleTimerElapse = singleStat.getElapseTimeAsMilliSecond();
             if (singleTimerElapse > MaxRunningDurationForSingleTimer)
             {
                 TRACE_WARNING("Timer is executing more than " << MaxRunningDurationForSingleTimer
                              << "ms, Timer Information" << timerInList);
                 break;
             }
        }
        else
        {
            break;
        }
        const uint64_t totalElapse = totalStat.getElapseTimeAsMilliSecond();
        if (totalElapse > MaxRunningDurationForTimersInOneLoop)
        {
            TRACE_DEBUG("Timers is executing more than " << MaxRunningDurationForTimersInOneLoop << "ms");
        }
    }
}

std::ostream& ListTimerQueue::operator<<(std::ostream& os) const
{
    os << "[";
    for (TimersList::const_iterator it = timersList_.cbegin(); it != timersList_.cend(); ++it)
    {
        os << "timer=" << *it;
    }
    os << "]";\
    return os;
}

std::ostream& operator<<(std::ostream& os, ITimerQueue* timerQueue)
{
    return timerQueue->operator <<(os);
}

}
