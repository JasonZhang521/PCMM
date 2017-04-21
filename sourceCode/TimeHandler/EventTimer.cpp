#include "EventTimer.h"
#include "IEvent.h"
#include "SystemTime.h"

namespace TimeHandler {

EventTimer::EventTimer(uint32_t interval, EventHandler::IEvent* event)
    : expiredTime_(SystemTime::expiredTimeStampAsMillisecond(interval))
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

uint64_t EventTimer::getExpiredTime()
{
    return expiredTime_;
}

}
