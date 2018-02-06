#ifndef _IO_IOCONTROLEVENT_H_
#define _IO_IOCONTROLEVENT_H_
#include "SocketWrapperDef.h"
#include "IIoControl.h"
#include "Component.h"
#include "Macro.h"

namespace Io {

class IoControlEventsHandler : public IIoControl
{
    SocketFdSet readFds_;
    SocketFdSet writeFds_;
    SocketFdSet exceptFds_;
public:
    IoControlEventsHandler();
    virtual ~IoControlEventsHandler();
protected:
    virtual void run();
    virtual std::ostream& operator<< (std::ostream& os) const;
private:
    virtual void addEvent(int fd, uint32_t type);
    virtual void updateEvent(int fd, uint32_t type);
    virtual void removeEvent(int fd, uint32_t type);

    void addToFdSet(int fd, uint32_t type);
    void removeFromFdSet(int fd, uint32_t type);

    void clearFdSet(uint32_t type);
    void clearAllFdSet();
};

}

#endif // _IO_IOCONTROLEVENT_H_
