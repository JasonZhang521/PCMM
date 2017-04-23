#ifndef _TIMEHANDLER_ITIMERQUEUE_H_
#define _TIMEHANDLER_ITIMERQUEUE_H_
#include <stdint.h>

namespace TimeHandler {

class ITimer;

class ITimerQueue
{
public:
    ITimerQueue();
    virtual ~ITimerQueue();
    virtual void AddTimer(ITimer*) = 0;
    virtual void deleteTimer(uint64_t timerID) = 0;
    virtual void executeTimers() = 0;
};

}
#endif // _TIMEHANDLER_ITIMERQUEUE_H_
