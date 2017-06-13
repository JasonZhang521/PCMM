#ifndef EVENTLOOP_H
#define EVENTLOOP_H
#include <memory>

namespace EventHanler
{
    class IEventQueue;
}

namespace Core {

class EventLoop : public ICoreLoop
{
    std::shared_ptr<EventHanler::IEventQueue> eventQueue_;
public:
    EventLoop(std::shared_ptr<EventHanler::IEventQueue> eventQueue);
    virtual void runLoop(unsigned int executeTime);
};

}

#endif // EVENTLOOP_H
