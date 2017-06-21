#include "ClusterMgtClientsManagement.h"
#include "IIpcClient.h"
#include "IIpcMessage.h"
#include "Trace.h"

namespace ClusterManagement {

ClusterMgtClientsManagment::ClusterMgtClientsManagment()
{

}

ClusterMgtClientsManagment::~ClusterMgtClientsManagment()
{

}

void ClusterMgtClientsManagment::addAcceptedIpcClient(const std::string& remoteEndPoint, std::shared_ptr<Ipc::IIpcClient> ipcClient)
{
    TRACE_DEBUG("Add client:" << remoteEndPoint);
    IpcClientsMap::iterator it= clients_.find(remoteEndPoint);
    if (it != clients_.end())
    {
        TRACE_NOTICE("Ipc client :" << remoteEndPoint << " has been updated!");
    }

    clients_[remoteEndPoint] = ipcClient;
}

void ClusterMgtClientsManagment::forwardIpcMessage(const std::string& remoteEndPoint, const IpcMessage::IIpcMessage& msg)
{
    TRACE_DEBUG("Forward msg to:" << remoteEndPoint << ", msg = " << msg);
    IpcClientsMap::iterator it = clients_.find(remoteEndPoint);
    if (it != clients_.end())
    {
        std::shared_ptr<Ipc::IIpcClient>& ipcClient = it->second;
        ipcClient->send(msg);
    }
}

void ClusterMgtClientsManagment::broadcastMsg(const IpcMessage::IIpcMessage& msg)
{
    for (IpcClientsMap::iterator it= clients_.begin(); it != clients_.end(); ++it)
    {
        std::shared_ptr<Ipc::IIpcClient>& ipcClient = it->second;
        ipcClient->send(msg);
    }
}

}
