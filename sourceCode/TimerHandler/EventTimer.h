#ifndef _TIMEHANDLER_EVENTTIMER_H_
#define _TIMEHANDLER_EVENTTIMER_H_

#include "ITimer.h"
#include <stdint.h>

namespace EventHandler {
    class IEvent;
}
namespace TimeHandler {

class EventTimer : public ITimer
{
    uint64_t timerId_;
    uint64_t expiredTime_;
    EventHandler::IEvent* event_;
public:
    EventTimer(uint32_t interval, EventHandler::IEvent* event);
    virtual ~EventTimer();
protected:
    virtual void onTime();
    virtual bool isExpired();
    virtual uint64_t getExpiredTime() const;
    virtual uint64_t getTimerId() const;
    virtual std::ostream& operator<<(std::ostream& os);
};

}

#endif // _TIMEHANDLER_EVENTTIMER_H_
