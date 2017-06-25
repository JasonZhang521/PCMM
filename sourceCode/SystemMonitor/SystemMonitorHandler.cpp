#include "SystemMonitorHandler.h"
#include "SystemInfoMessage.h"
#include "IIpcClient.h"
#include "CpuUsage.h"

namespace SystemMonitor {

SystemMonitorHandler::SystemMonitorHandler(std::shared_ptr<Ipc::IIpcClient> ipcClient)
    :ipcClient_(ipcClient)
{

}

SystemMonitorHandler::~SystemMonitorHandler()
{

}

void SystemMonitorHandler::reportSystemInfo()
{
    SystemMonitorMessage::SystemInfoMessage message(Environment::CpuUsageInfo(Environment::CpuUsage::instance().getCpuUsageEntrys()));
    ipcClient_->send(message);
}

void SystemMonitorHandler::startup()
{
    ipcClient_->connect();
}

void SystemMonitorHandler::shutdown()
{
    ipcClient_->disconnect();
}

}
