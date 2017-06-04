#include "IpcClient.h"
#include "IIpcConnectionClientStrategy.h"
#include "Trace.h"

namespace Ipc {

IpcClient::IpcClient(std::shared_ptr<IIpcConnectionClientStrategy> strategy)
    :strategy_(strategy)
{

}

IpcClient::~IpcClient()
{

}

void IpcClient::connect()
{
    TRACE_ENTER();
    strategy_->connect();
}

void IpcClient::send(Serialize::WriteBuffer& writeBuffer)
{
    TRACE_ENTER();
    strategy_->send(writeBuffer);
}

void IpcClient::disconnect()
{
    TRACE_ENTER();
    strategy_->disconnect();
}

}
