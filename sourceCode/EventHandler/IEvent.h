#ifndef IEVENT_H
#define IEVENT_H

namespace EventHandler {

class IEvent
{
public:
    IEvent();
    virtual ~IEvent();
    virtual void run() = 0;
};

}

#endif // IEVENT_H
