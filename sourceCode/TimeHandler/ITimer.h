#ifndef _TIMEHANDLER_ITIMER_H_
#define _TIMEHANDLER_ITIMER_H_

#include <stdint.h>

namespace TimeHandler {

class ITimer
{
public:
    ITimer();
    virtual ~ITimer();
    virtual void onTime() = 0;
    virtual bool isExpired() = 0;
    virtual uint64_t getExpiredTime() = 0;
};

}

#endif // ITIMER_H
