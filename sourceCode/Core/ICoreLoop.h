#ifndef ICORELOOP_H
#define ICORELOOP_H

namespace Core {

class ICoreLoop
{
public:
    ICoreLoop();
    virtual ~ICoreLoop();
    virtual void runLoop(unsigned int executeTime) = 0;
};

}

#endif // ICORELOOP_H
