#include "IpcClient.h"
#include "IIpcMessage.h"
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

void IpcClient::send(const IpcMessage::IIpcMessage& msg)
{
    TRACE_ENTER();
    strategy_->send(msg);
}

void IpcClient::disconnect()
{
    TRACE_ENTER();
    strategy_->disconnect();
}

}
