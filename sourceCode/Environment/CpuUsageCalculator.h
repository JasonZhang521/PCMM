#ifndef _ENVIRONMENT_CPUUSAGECALCULATOR_H_
#define _ENVIRONMENT_CPUUSAGECALCULATOR_H_
#include "CpuUsageDataType.h"

namespace Environment {

class CpuUsageCalculator
{
public:
    CpuUsageCalculator();
    CpuUsageEntry operator() (const CpuUsageRawData& data);
};

}

#endif // _ENVIRONMENT_CPUUSAGECALCULATOR_H_
