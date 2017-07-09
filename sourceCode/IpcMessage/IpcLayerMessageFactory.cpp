#include "IpcLayerMessageFactory.h"
#include "IpcMessageType.h"
#include "IpcHeartbeatReport.h"
namespace IpcMessage {

IpcLayerMessageFactory::IpcLayerMessageFactory()
    : IIpcMessageFactory(IpcMessageType::IpcMessage_IpcComunication)
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
    else
    {
        return nullptr;
    }
}

}
