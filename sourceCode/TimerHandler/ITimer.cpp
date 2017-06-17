#include "ITimer.h"
#include "SystemTime.h"
#include "TimerIdGenerator.h"

namespace TimerHandler {

std::string timerTypeToString(TimerType type)
{
    switch (type) {
    case TimerType::PeriodTimer:
        return std::string("PeriodTimer");
    case TimerType::SingleTimer:
        return std::string("SingleTimer");
    default:
        return std::string("NoTimer");;
    }
}

ITimer::ITimer(uint64_t period, TimerType type)
    :timerId_(TimerIdGenerator::generateTimerId())
    ,period_(period)
    ,expiredTime_(SystemTime::expiredTimeStampAsMillisecond(period))
    ,timerType_(type)
{

}

ITimer::~ITimer()
{

}

uint64_t ITimer::getTimerId() const
{
    return timerId_;
}

bool ITimer::isExpired()
{
    return (SystemTime::currentTimeStampAsMillisecond() > expiredTime_);
}

uint64_t ITimer::getExpiredTime() const
{
    return expiredTime_;
}

uint64_t ITimer::getPeriod() const
{
    return period_;
}

TimerType ITimer::getTimerType() const
{
    return timerType_;
}


void ITimer::resetTimer()
{
    expiredTime_ = SystemTime::expiredTimeStampAsMillisecond(period_);
}

std::ostream& operator<<(std::ostream& os, ITimer* timer)
{
    return timer->operator<<(os);
}

}
