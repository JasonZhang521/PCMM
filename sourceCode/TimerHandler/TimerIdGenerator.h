#ifndef _TIMEHANDLER_TIMERIDGENERATOR_H_
#define _TIMEHANDLER_TIMERIDGENERATOR_H_
#include <stdint.h>

namespace TimeHandler {

class TimerIdGenerator
{
    static uint64_t timerId;

private:
    TimerIdGenerator();
public:
    static uint64_t generateTimerId();
};

}

#endif // _TIMEHANDLER_TIMERIDGENERATOR_H_
