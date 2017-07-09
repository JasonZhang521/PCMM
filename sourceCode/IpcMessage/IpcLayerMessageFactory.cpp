#include "IpcLayerMessageFactory.h"
#include "IpcMessageType.h"
#include "IpcHeartbeatReport.h"
#include "IpcAuthorizationRequest.h"
namespace IpcMessage {

IpcLayerMessageFactory::IpcLayerMessageFactory()
    : IIpcMessageFactory(IpcMessageType::IpcMessage_IpcCommunication)
{

}

IpcLayerMessageFactory::~IpcLayerMessageFactory()
{

}

IIpcMessage* IpcLayerMessageFactory::createMessage(IpcMessageIntType type) const
{
    if (type == IpcHeartbeatReportMessage)
    {
        return new IpcHeartbeatReport();
    }
    else if (type == IpcAuthorizationRequstMessage)
    {
        return new IpcAuthorizationRequest();
    }
    else
    {
        return nullptr;
    }
}

}
