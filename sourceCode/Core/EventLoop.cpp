#include "EventLoop.h"
#include "IEventQueue.h"

namespace Core {

EventLoop::EventLoop(std::shared_ptr<EventHanler::IEventQueue> eventQueue)
    :eventQueue_(eventQueue)
{

}

void EventLoop::runLoop(unsigned int executeTime)
{
    eventQueue_->executeEvent(executeTime);
}

}
