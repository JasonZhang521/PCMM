#include "SystemMonitorHandler.h"
#include "SystemInfoMessage.h"
#include "IIpcClient.h"
#include "CpuUsage.h"

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
    ipcClient_ = ipcClient;
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
