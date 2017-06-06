#ifndef _ENVIRONMENT_CPUUSAGECALCULATOR_H_
#define _ENVIRONMENT_CPUUSAGECALCULATOR_H_
#include "CpuUsageDataType.h"

namespace Environment {

class CpuUsageEntryCalculator
{
public:
    CpuUsageEntry operator() (const CpuUsageRawData& data);
};

class CpuUsageRawDataDiffCalculator
{
    CpuUsageRawData operator() (const CpuUsageRawData& curData, const CpuUsageRawData& preData);
};

}

#endif // _ENVIRONMENT_CPUUSAGECALCULATOR_H_
