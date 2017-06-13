#ifndef LOOPMAIN_H
#define LOOPMAIN_H
#include <memory>

namespace Core {

class LoopMain
{
    std::unique_ptr<ICoreLoop> eventLoop_;
    std::unique_ptr<ICoreLoop> timeLoop_;
    std::unique_ptr<ICoreLoop> ioLoop_;
public:
    LoopMain();
    void loop;

};

}

#endif // LOOPMAIN_H
