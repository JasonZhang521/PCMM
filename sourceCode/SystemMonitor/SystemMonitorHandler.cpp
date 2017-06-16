#include "SystemMonitorHandler.h"


namespace SystemMonitor {

SystemMonitorHandler::SystemMonitorHandler(std::shared_ptr<Connection::IConnectionRx> connectionRx)
    :connectionRx_(connectionRx)
{

}

SystemMonitorHandler::~SystemMonitorHandler()
{

}

void SystemMonitorHandler::reportSystemInfo()
{

}

}
