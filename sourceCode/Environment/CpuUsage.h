#ifndef _ENVIRONMENT_CPUUSAGE_H_
#define _ENVIRONMENT_CPUUSAGE_H_
#include "CpuUsageDataType.h"
#include "Component.h"
#include "Macro.h"
#include <string>

namespace Environment {
#ifdef WIN32

#else
class CpuUsage
{
    unsigned int nCpu_;
    std::string statFilePath_;
    CpuUsageRawDatas preRawDatas_;
    CpuUsageRawDatas curRawDatas_;
    CpuUsageRawDatas usageRawDatas_;
    CpuUsageEntrys   usageEntrys_;
public:
    CpuUsage();
    void update();
    const CpuUsageRawDatas& getCpuUsageRawData() const;
    const CpuUsageEntrys& getCpuUsageEntrys() const;
private:
    void init();
    void getCpuUsageFromProcStatFile();

public:
     GETCLASSNAME(CpuUsage)
};

#endif

}

#endif // _ENVIRONMENT_CPUUSAGE_H_
