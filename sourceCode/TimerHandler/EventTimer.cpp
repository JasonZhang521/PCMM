#include "EventTimer.h"
#include "IEvent.h"


namespace TimerHandler {

EventTimer::EventTimer(uint32_t period, TimerType type, EventHandler::IEvent* event)
    :ITimer(period, type)
    ,event_(event)
{
}

EventTimer::~EventTimer()
{
}

void EventTimer::onTime()
{
    if (getTimerType() == TimerType::PeriodTimer)
    {
        resetTimer();
    }
    return event_->run();
}

std::ostream& EventTimer::operator<<(std::ostream& os)
{

    os << "["
       << "timerId=" << getTimerId()
       << ", expiredTime=" << getExpiredTime()
       << ", period=" << getPeriod()
       << ", timerType=" << timerTypeToString(getTimerType())
       << ", event=" << event_
       << "]";

    return os;
}

}
