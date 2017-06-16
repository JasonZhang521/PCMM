#ifndef SYSTEMMONITORHANDLER_H
#define SYSTEMMONITORHANDLER_H
#include "ISystemMonitorHandler.h"
#include "SystemInfoCollector.h"
#include "IConnectionTx.h"
#include "Component.h"
#include "Macro.h"
#include <memory>

namespace Connection {
class connectionRx;
class connectionTx;
}

namespace SystemMonitor {

class SystemMonitorHandler : public ISystemMonitorHandler
{
    std::shared_ptr<Connection::IConnectionRx> connectionRx_;
    SystemInfoCollector collector;
public:
    SystemMonitorHandler(std::shared_ptr<Connection::IConnectionRx> connectionRx);
    ~SystemMonitorHandler();
private:
    virtual void reportSystemInfo();

public:
     GETCLASSNAME(SystemInfoCollector)
};

}

#endif // SYSTEMMONITORHANDLER_H
