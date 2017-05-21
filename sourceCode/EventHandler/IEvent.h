#ifndef IEVENT_H
#define IEVENT_H

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
    virtual void run(EventFlag flag = EventFlag::Event_NoFlag) = 0;
};

}

#endif // IEVENT_H
