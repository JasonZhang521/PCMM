#include "ITimer.h"

namespace TimeHandler {

ITimer::ITimer()
{

}

ITimer::~ITimer()
{

}

std::ostream& operator<<(std::ostream& os, ITimer* timer)
{
    return timer->operator <<(os);
}

}
