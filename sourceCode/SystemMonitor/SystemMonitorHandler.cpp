#include "SystemMonitorHandler.h"
#include "SystemInfoMessage.h"
#include "IIpcClient.h"
#include "CpuUsage.h"
#include "Trace.h"

namespace SystemMonitor {

SystemMonitorHandler::SystemMonitorHandler(std::shared_ptr<Ipc::IIpcClient> ipcClient)
    :ipcClient_(ipcClient)
{

}

SystemMonitorHandler::SystemMonitorHandler()
{

}

SystemMonitorHandler::~SystemMonitorHandler()
{

}

void SystemMonitorHandler::setIpcClient(std::shared_ptr<Ipc::IIpcClient> ipcClient)
{
    TRACE_ENTER();
    ipcClient_ = ipcClient;
}

void SystemMonitorHandler::reportSystemInfo()
{
    SystemMonitorMessage::SystemInfoMessage message(Environment::CpuUsageInfo(Environment::CpuUsage::instance().getCpuUsageEntrys()));
    TRACE_DEBUG("report system information:" << message);
    ipcClient_->send(message);
}

void SystemMonitorHandler::startup()
{
    TRACE_ENTER();
    ipcClient_->connect();
}

void SystemMonitorHandler::shutdown()
{
    TRACE_ENTER();
    ipcClient_->disconnect();
}

}
