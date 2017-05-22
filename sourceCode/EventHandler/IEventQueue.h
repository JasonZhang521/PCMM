#ifndef IEVENTQUEUE_H
#define IEVENTQUEUE_H

namespace EventHandler {

class IEventQueue
{
public:
    IEventQueue();
    virtual ~IEventQueue();
    virtual void AddEvent(IEvent*) = 0;
    virtual void deleteEvent(uint64_t eventID) = 0;
    virtual void executeEvents() = 0;
    virtual std::ostream& operator<<(std::ostream& os) = 0;
};

}
#endif // IEVENTQUEUE_H
