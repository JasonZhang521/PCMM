#include "EventTimer.h"
#include "IEvent.h"
#include "SystemTime.h"
#include "TimerIdGenerator.h"

namespace TimeHandler {

EventTimer::EventTimer(uint32_t interval, EventHandler::IEvent* event)
: timerId_(TimerIdGenerator::generateTimerId())
, expiredTime_(SystemTime::expiredTimeStampAsMillisecond(interval))
, event_(event)
{
}

EventTimer::~EventTimer()
{
    delete event_;
}

void EventTimer::onTime()
{
    return event_->run();
}

bool EventTimer::isExpired()
{
    return (SystemTime::currentTimeStampAsMillisecond() > expiredTime_);
}

uint64_t EventTimer::getExpiredTime() const
{
    return expiredTime_;
}

uint64_t EventTimer::getTimerId() const
{
    return timerId_;
}

std::ostream& EventTimer::operator<<(std::ostream& os)
{
    os << "["
       << "timerId=" << timerId_
       << ", expiredTime=" << expiredTime_
       << ", event=" << event_
       << "]";

    return os;
}

}
