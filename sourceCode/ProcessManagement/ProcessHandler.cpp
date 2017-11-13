#include "ProcessHandler.h"

namespace ProcessManagement {
ProcessHandler::ProcessHandler()
    :ITimer(500, TimerHandler::TimerType::PeriodTimer)
{
}

ProcessHandler::~ProcessHandler()
{

}

void ProcessHandler::onTime()
{

}

std::ostream& ProcessHandler::operator<<(std::ostream& os)
{

}

}
