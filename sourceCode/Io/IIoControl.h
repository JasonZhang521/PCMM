#ifndef _IO_IIOCONTROL_H_
#define _IO_IIOCONTROL_H_

#include <ostream>
#include <map>
#include <list>


namespace Io {

class IIoEvent;

enum IoFdType
{
    IoFdNoType = 0,
    IoFdRead = 1,
    IoFdWrite = 1 << 2,
    IoFdExcept = 1 << 3,
    IoFdAll = IoFdRead | IoFdWrite | IoFdExcept
};

class IIoControl
{
protected:
    struct IoEventCache
    {
        enum Op{
            Register,
            UnRegister
        };
        Op op_;
        int fd_;
        IIoEvent* event_;
        IoFdType type_;
        IoEventCache(Op op, int fd, IIoEvent* event, IoFdType type)
            :op_(op), fd_(fd), event_(event), type_(type)
        {}
    };

    struct IoFdEvent
    {
        IoFdEvent() : fdType(IoFdNoType), fdEvent(nullptr) {}
        IoFdEvent(IoFdType type, IIoEvent* event) : fdType(type), fdEvent(event) {}
        uint32_t fdType;
        IIoEvent* fdEvent;
    };

    bool isRunning_;
    using IoFdEventMap = std::map<int, IoFdEvent>;
    IoFdEventMap fdEventMap_;
    using IoEventsCacheList = std::list<IoEventCache>;
    IoEventsCacheList ioEventsCacheList_;
public:
    IIoControl();
    virtual ~IIoControl();
    virtual void registerIoFd(IoFdType type, IIoEvent* IEvent);
    virtual void unRegisterIoFd(IoFdType type, int fd);
    virtual void run() = 0;
    virtual std::ostream& operator<< (std::ostream& os) const = 0;
protected:
    virtual void addEvent(int fd, uint32_t type) = 0;
    virtual void updateEvent(int fd, uint32_t type) = 0;
    virtual void removeEvent(int fd, uint32_t type) = 0;
    void refreshIoEvents();

};

}

#endif // _IO_IIOCONTROL_H_
