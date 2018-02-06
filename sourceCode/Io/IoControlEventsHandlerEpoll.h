#ifndef _IO_IOCONTROLEVENTSHANDLEREPOLL_H_
#define _IO_IOCONTROLEVENTSHANDLEREPOLL_H_
#ifndef WIN32
#include "SocketWrapperDef.h"
#include "IIoControl.h"
#include <vector>

namespace Io {
class IoControlEventsHandlerEpoll : public IIoControl
{
    const static uint32_t NumOfEpollFds = 2;
    const static int MaxNumOfFdsEachEpollFd = 1024;
    const static int MaxListenEvents = 50;
    std::vector<SocketEpollFd> epollFds_;
public:
    IoControlEventsHandlerEpoll();
    ~IoControlEventsHandlerEpoll();

protected:
    virtual void run();
    virtual std::ostream& operator<< (std::ostream& os) const;
    virtual void addEvent(int fd, uint32_t type);
    virtual void updateEvent(int fd, uint32_t type);
    virtual void removeEvent(int fd, uint32_t type);
};

}

#endif // WIN32
#endif // _IO_IOCONTROLEVENTSHANDLEREPOLL_H_
