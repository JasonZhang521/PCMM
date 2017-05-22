#ifndef _EVENTHANDLER_LISTEVENTQUEUE_H_
#define _EVENTHANDLER_LISTEVENTQUEUE_H_
#include "IEventQueue.h"
#include <list>

namespace EventHandler {
class IEvent;

using EventList = std::list<IEvent*>;

class ListEventQueue : public IEventQueue
{
    EventList eventsList_;
public:
    ListEventQueue();
    virtual ~ListEventQueue();
    virtual void AddEvent(IEvent*);
    virtual void deleteEvent(uint64_t eventID);
    virtual void executeEvents();
    virtual std::ostream& operator<<(std::ostream& os);
};

}

#endif // _EVENTHANDLER_EVENTQUEUE_H_
