#include "IpcServer.h"
#include "IIpcConnectionServerStrategy.h"
#include "Trace.h"
#include "Component.h"
#include "Macro.h"

namespace Ipc {

GETCLASSNAME(IpcServer)

IpcServer::IpcServer(std::shared_ptr<IIpcConnectionServerStrategy> strategy)
    :strategy_(strategy)
{

}

IpcServer::~IpcServer()
{

}

void IpcServer::startup()
{
    TRACE_NOTICE("Ipc server startup");
    strategy_->startup();
}

void IpcServer::shutdown()
{
    TRACE_NOTICE("Ipc server down");
    strategy_->shutdown();
}

}
