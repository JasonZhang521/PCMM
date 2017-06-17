#ifndef _CORE_LOOPMAIN_H_
#define _CORE_LOOPMAIN_H_
#include "EventLoop.h"
#include "IoLoop.h"
#include "TimerLoop.h"
#include <memory>

namespace TimerHandler {
class ITimer;
}

namespace EventHandler {
class IEvent;
}
namespace Core {

class LoopMain
{
    EventLoop eventLoop_;
    TimerLoop timeLoop_;
    IoLoop ioLoop_;
    unsigned int timeExcuteInOneLoop;
public:
    LoopMain();
    void registerTimer(TimerHandler::ITimer* timer);
    void deRegisterTimer(uint64_t timerID);
    void registerEvent(EventHandler::IEvent* event);
    void deRegisterEvent(uint64_t eventID);
    void registerIo(int fd, Io::IoFdType type, Io::IIoEvent* IEvent);
    void deRegisterIo(int fd);
    void loop();

};

}

#endif // _CORE_LOOPMAIN_H_
