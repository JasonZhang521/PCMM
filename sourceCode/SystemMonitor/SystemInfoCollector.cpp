#include "SystemInfoCollector.h"
#include "EventIdGenerator.h"
#include "CpuUsage.h"
#include "Singleton.h"
#include "Trace.h"
#include "App.h"

namespace SystemMonitor {

SystemInfoCollector::SystemInfoCollector(std::shared_ptr<ISystemMonitorHandler> monitorHandler)
    :eventId_(EventHandler::EventIdGenerator::generateEventId())
    ,monitorHandler_(monitorHandler)
{
    init();
}
SystemInfoCollector::~SystemInfoCollector()
{

}

uint64_t SystemInfoCollector::getEventId() const
{
    return eventId_;
}

void SystemInfoCollector::run(EventHandler::EventFlag flag)
{
    static_cast<void> (flag);
    Singleton<Environment::CpuUsage>::instance().update();
 }

std::ostream& SystemInfoCollector::operator<< (std::ostream& os) const
{
    os << "["
       << "eventId_:" << eventId_
       << "]";
    return os;
}

void SystemInfoCollector::init()
{
    Singleton<Environment::CpuUsage>::instance().update();
}

}


