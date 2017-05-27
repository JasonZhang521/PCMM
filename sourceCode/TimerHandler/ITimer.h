#ifndef _TIMERHANDLER_ITIMER_H_
#define _TIMERHANDLER_ITIMER_H_
#include <stdint.h>
#include <ostream>

namespace TimerHandler {

class ITimer
{
public:
    ITimer();
    virtual ~ITimer();
    virtual void onTime() = 0;
    virtual bool isExpired() = 0;
    virtual uint64_t getExpiredTime() const = 0;
    virtual uint64_t getTimerId() const = 0;
    virtual std::ostream& operator<<(std::ostream& os) = 0;
};

std::ostream& operator<<(std::ostream& os, ITimer* timer);

}

#endif // _TIMERHANDLER_ITIMER_H_