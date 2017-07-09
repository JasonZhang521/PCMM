#include "ClusterMgtClientsManagement.h"
#include "IIpcClient.h"
#include "IIpcServer.h"
#include "IIpcMessage.h"
#include "Trace.h"

namespace ClusterManagement {

ClusterMgtClientsManagment::ClusterMgtClientsManagment(std::shared_ptr<Ipc::IIpcServer> ipcServer)
    :ipcServer_(ipcServer)
{

}

ClusterMgtClientsManagment::~ClusterMgtClientsManagment()
{

}

void ClusterMgtClientsManagment::startup()
{
    TRACE_ENTER();
    ipcServer_->startup();
}

void ClusterMgtClientsManagment::shutdown()
{
    TRACE_ENTER();
    ipcServer_->shutdown();
}

void ClusterMgtClientsManagment::addAcceptedIpcClient(const std::string& remoteEndPoint, std::shared_ptr<Ipc::IIpcClient> ipcClient)
{
    TRACE_DEBUG("Add client:" << remoteEndPoint);
    IpcClientsMap::iterator it= clients_.find(remoteEndPoint);
    if (it != clients_.end())
    {
        TRACE_WARNING("Ipc client :" << remoteEndPoint << " already exist!");
    }

    clients_[remoteEndPoint] = ipcClient;
}

void ClusterMgtClientsManagment::removeAcceptedIpcClient(const std::string& remoteEndPoint)
{
    TRACE_DEBUG("remove client:" << remoteEndPoint);
    IpcClientsMap::iterator it = clients_.find(remoteEndPoint);
    if (it != clients_.end())
    {
        clients_.erase(it);
    }
    else
    {
        TRACE_WARNING("Ipc client :" << remoteEndPoint << " already been removed!");
    }
}

void ClusterMgtClientsManagment::handleMessage(const IpcMessage::IIpcMessage& msg)
{
    const std::string dest = msg.getDestnation().toString();
    if (dest.empty())
    {
        broadcastMsg(msg);
    }
    else
    {
        IpcClientsMap::iterator it = clients_.find(dest);
        forwardIpcMessage(dest, msg);
    }
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
