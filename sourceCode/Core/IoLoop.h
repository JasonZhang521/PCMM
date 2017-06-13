#ifndef IOLOOP_H
#define IOLOOP_H
#include <memory>

namespace Io {
    class IIoControl;
}

namespace Core {

class IoLoop : public ICoreLoop
{
    std::shared_ptr<IIoControl> timerQueue_;
public:
    IoLoop();
};

}

#endif // IOLOOP_H
