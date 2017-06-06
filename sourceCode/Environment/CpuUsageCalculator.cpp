#include "CpuUsageCalculator.h"

namespace Environment {

CpuUsageEntry CpuUsageEntryCalculator::operator() (const CpuUsageRawData& data)
{
    CpuUsageEntry entry;
    if (data.size() != CPU_USAGE_TYPE_NUMBER)
    {
        return entry;
    }
    else
    {
        uint64_t      sum = 0;
        for (CpuUsageRawData::const_iterator it = data.begin(); it != data.end(); ++it)
        {
            sum += *it;
        }

        if (sum != 0)
        {
            entry.setTotalUsage((100 * (sum - data[CPU_IDLE]) + sum / 2) / sum);
            entry.setUserUsage((100 * data[CPU_USER] + sum / 2) / sum);
            entry.setNiceUsage((100 * data[CPU_NICE] + sum / 2) / sum);
            entry.setSysUsage((100 * data[CPU_SYS] + sum / 2) / sum);
            entry.setIntrUsage((100 * (data[CPU_IRQ] + data[CPU_SOFTIRQ]) + sum / 2) / sum);
        }

        entry.setTotalUsage(sum);
        return entry;
    }
}

CpuUsageRawData CpuUsageRawDataDiffCalculator::operator() (const CpuUsageRawData& curData, const CpuUsageRawData& preData)
{
    CpuUsageRawData data;
    return data;
}

}
