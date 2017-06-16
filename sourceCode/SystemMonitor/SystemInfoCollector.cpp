#include "SystemInfoCollector.h"
#include "EventIdGenerator.h"
#include "CpuUsage.h"
#include "Singleton.h"
#include "Trace.h"
#include "App.h"

namespace SystemMonitor {

SystemInfoCollector::SystemInfoCollector()
    :eventId_(EventHandler::EventIdGenerator::generateEventId())
{
    init();
}
SystemInfoCollector::~SystemInfoCollector()
{

}

const Environment::CpuUsageInfo& SystemInfoCollector::getCpuUsageInfo() const
{
    return cpuUsageInfo_;
}

uint64_t SystemInfoCollector::getEventId() const
{
    return eventId_;
}

void SystemInfoCollector::run(EventHandler::EventFlag flag)
{
    static_cast<void> (flag);
    Singleton<Environment::CpuUsage>::instance().update();
    cpuUsageInfo_ = Environment::CpuUsageInfo(Singleton<Environment::CpuUsage>::instance().getCpuUsageEntrys());
}

std::ostream& SystemInfoCollector::operator<< (std::ostream& os) const
{
    os << "["
       << "cpu information:" << cpuUsageInfo_
       << "]";
    return os;
}

void SystemInfoCollector::init()
{
    Singleton<Environment::CpuUsage>::instance().update();
}

}


