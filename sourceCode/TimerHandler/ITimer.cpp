#include "ITimer.h"

namespace TimerHandler {

ITimer::ITimer()
{

}

ITimer::~ITimer()
{

}

std::ostream& operator<<(std::ostream& os, ITimer* timer)
{
    return timer->operator<<(os);
}

}
