#include "TimeLoop.h"

namespace Core {

TimeLoop::TimeLoop(std::shared_ptr<TimerHandler::ListTimerQueue> timerQueue)
    :timerQueue_(timerQueue)
{

}

void TimeLoop::runLoop(unsigned int executeTime)
{
    static_cast<void>(executeTime);
    timerQueue_->executeTimers();
}

}
