#ifndef SYSTEMMONITORCONNECTIONTX_H
#define SYSTEMMONITORCONNECTIONTX_H
#include "ISystemMonitorHandler.h"
#include "IConnectionTx.h"
#include "Component.h"
#include "Macro.h"
#include <memory>

namespace SystemMonitor {

class SystemMonitorConnectionTx : public Connection::IConnectionTx
{
    std::shared_ptr<ISystemMonitorHandler> monitorHandler_;
public:
    SystemMonitorConnectionTx(std::shared_ptr<ISystemMonitorHandler> monitorHandler);
    ~SystemMonitorConnectionTx();
protected:
    virtual void onConnect();
    virtual void onReceive(Serialize::ReadBuffer& readBuffer);
    virtual void onDisconnect();
};

}

#endif // SYSTEMMONITORCONNECTIONTX_H
