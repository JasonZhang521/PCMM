#include "ClusterMgtMessageFactory.h"
#include "ClusterMgtBrieflyRequest.h"
#include "ClusterMgtBrieflyResponse.h"
#include "Trace.h"
namespace ClusterMgtMessage {
ClusterMgtMessageFactory::ClusterMgtMessageFactory()
    :IpcMessage::IIpcMessageFactory(IpcMessage::IpcMessage_ClusterMgt)
{

}

ClusterMgtMessageFactory::~ClusterMgtMessageFactory()
{

}

IpcMessage::IIpcMessage* ClusterMgtMessageFactory::createMessage(IpcMessage::IpcMessageApplicationIntType type) const
{
    if (static_cast<IpcMessage::IpcClusterMgtMessageType>(type) == IpcMessage::ClusterMgtBrieflyRequestMessage)
    {
        return new ClusterMgtBrieflyRequest();
    }
    else if (static_cast<IpcMessage::IpcClusterMgtMessageType>(type) == IpcMessage::ClusterMgtBrieflyResponseMessage)
    {
        return new ClusterMgtBrieflyResponse();
    }
    else
    {
        TRACE_ERROR("Only support message type: MonitorRequest and MonitorMessage!");
        return nullptr;
    }
}

}
