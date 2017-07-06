#include "SystemMonitorHandler.h"
#include "SystemInfoMessage.h"
#include "IIpcClient.h"
#include "CpuUsage.h"
#include "LoopMain.h"
#include "Trace.h"

namespace SystemMonitor {

SystemMonitorHandler::SystemMonitorRestartTimer::SystemMonitorRestartTimer(ISystemMonitorHandler* handler)
    : ITimer(3000)
    , handler_(handler)
{

}

void SystemMonitorHandler::SystemMonitorRestartTimer::onTime()
{
    handler_->startup();
}

std::ostream& SystemMonitorHandler::SystemMonitorRestartTimer::operator<<(std::ostream& os)
{
    os << "["
       << "timerId=" << getTimerId()
       << ", period=" << getPeriod()
       << ", expiredTime=" << getExpiredTime()
       << ", timerType=" << timerTypeToString(getTimerType())
       << "]";
    return os;
}

SystemMonitorHandler::SystemMonitorHandler(std::shared_ptr<Ipc::IIpcClient> ipcClient)
    : ipcClient_(ipcClient)
    , isStartup_(false)
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
    if (isStartup_)
    {
        SystemMonitorMessage::SystemInfoMessage message(Environment::CpuUsageInfo(Environment::CpuUsage::instance().getCpuUsageEntrys()));
        TRACE_DEBUG("report system information:" << message);
        ipcClient_->send(message);
    }
    else
    {
        TRACE_NOTICE("SystemMonitor is not start up!");
    }
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

void SystemMonitorHandler::reStartup()
{
    TRACE_ENTER();
    if (!systemMonitorRestartTimer_)
    {
        systemMonitorRestartTimer_ = std::shared_ptr<SystemMonitorRestartTimer>(new SystemMonitorRestartTimer(this));
    }
    systemMonitorRestartTimer_.reset();
    Core::LoopMain::instance().registerTimer(systemMonitorRestartTimer_.get());
}

void SystemMonitorHandler::onStartup()
{
    isStartup_ = true;
}
void SystemMonitorHandler::onShutdown()
{
    isStartup_ = false;
    reStartup();
}

}
