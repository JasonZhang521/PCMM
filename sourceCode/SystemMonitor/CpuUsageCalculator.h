#ifndef CPUUSAGECALCULATOR_H
#define CPUUSAGECALCULATOR_H
#include "CpuUsageDataType.h"

namespace SystemMonitor {

class CpuUsageCalculator
{
public:
    CpuUsageCalculator();
    CpuUsageEntry operator() (const CpuUsageRawData& data);
};

}

#endif // CPUUSAGECALCULATOR_H
