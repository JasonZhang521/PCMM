#ifndef IEVENT_H
#define IEVENT_H
#include <stdint.h>

namespace EventHandler {

enum class EventFlag
{
    Event_NoFlag,
    Event_IoRead,
    Event_IoWrite,
    Event_IoError
};

class IEvent
{
public:
    IEvent();
    virtual ~IEvent();
    virtual uint64_t getEventId() const = 0;
    virtual void run(EventFlag flag = EventFlag::Event_NoFlag) = 0;
};

}

#endif // IEVENT_H
