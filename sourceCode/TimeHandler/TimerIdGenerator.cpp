#include "TimerIdGenerator.h"

namespace TimeHandler {

uint64_t TimerIdGenerator::timerId = 0;

uint64_t TimerIdGenerator::generateTimerId()
{
    return timerId++;
}

}
