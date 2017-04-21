#ifndef TIMESTAT_H
#define TIMESTAT_H

#include <stdint.h>

namespace TimeHandler {

class TimeStat
{
    uint64_t startTime_;
public:
    TimeStat();
    void restart();
    uint64_t getElapseTimeAsMilliSecond();
    uint64_t getElapseTimeAsSecond();
};

}
#endif // TIMESTAT_H
