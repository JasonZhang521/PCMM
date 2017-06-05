#ifndef _ENVIRONMENT_CPUUSAGE_H_
#define _ENVIRONMENT_CPUUSAGE_H_
#include "CpuUsageDataType.h"

namespace Environment {
#ifndef WIN32

class CpuUsage
{
    unsigned int nCpu_;
    std::string statFile_;
    CpuUsageRawDataVector preRawDatas_;
    CpuUsageRawDataVector curRawDatas_;
public:
    CpuUsage();
private:
    void init();
    void getCpuUsageFromProcStatFile();
};

#endif

}

#endif // _ENVIRONMENT_CPUUSAGE_H_
