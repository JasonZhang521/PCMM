#include "LoopMain.h"
#include "ListEventQueue.h"
#include "ListTimerQueue.h"
#include "IoControlEventsHandler.h"
#include "AppConst.h"
namespace Core {
LoopMain::LoopMain()
    : eventLoop_(std::shared_ptr<EventHandler::IEventQueue>(new EventHandler::ListEventQueue()))
    , timeLoop_(std::shared_ptr<TimerHandler::ITimerQueue>(new TimerHandler::ListTimerQueue))
    , ioLoop_(std::shared_ptr<Io::IIoControl>(new Io::IoControlEventsHandler()))
    , timeExcuteInOneLoop(MaxRunningTimeInOneLoop)
{

}

void LoopMain::registerTimer(TimerHandler::ITimer* timer)
{
    timeLoop_.registerTimer(timer);
}

void LoopMain::deRegisterTimer(uint64_t timerID)
{
    timeLoop_.deRegisterTimer(timerID);
}

void LoopMain::registerEvent(EventHandler::IEvent* event)
{
    eventLoop_.registerEvent(event);
}

void LoopMain::deRegisterEvent(uint64_t eventID)
{
    eventLoop_.deRegisterEvent(eventID);
}

void LoopMain::registerIo(int fd, Io::IoFdType type, EventHandler::IEvent* event)
{
    ioLoop_.registerIo(fd, type, event);
}

void LoopMain::deRegisterIo(int fd)
{
    ioLoop_.deRegisterIo(fd);
}

void LoopMain::loop()
{

}
}
