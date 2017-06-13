#ifndef TIMELOOP_H
#define TIMELOOP_H
#include <memory>

namespace TimerHandler
{
    class ListTimerQueue;
}

namespace Core {

class TimeLoop : public ICoreLoop
{
    std::shared_ptr<TimerHandler::ListTimerQueue> timerQueue_;
public:
    TimeLoop(std::shared_ptr<TimerHandler::ListTimerQueue> timerQueue);
    virtual void runLoop(unsigned int executeTime = 0);
};

}

#endif // TIMELOOP_H
