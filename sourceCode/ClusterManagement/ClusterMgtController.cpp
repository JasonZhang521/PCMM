#include "ClusterMgtController.h"
#include "IClusterMgtClientsManagement.h"
#include "Trace.h"

namespace ClusterManagement
{

ClusterMgtController::ClusterMgtController()
{

}

ClusterMgtController::~ClusterMgtController()
{

}

void ClusterMgtController::startup()
{
    for (ClientsManagementMap::iterator it = clientsManager_.begin(); it != clientsManager_.end(); ++it)
    {
        std::shared_ptr<IClusterMgtClientsManagement> clusterMgtClientManagement = it->second;
        clusterMgtClientManagement->startup();
    }
}

void ClusterMgtController::shutdown()
{
    for (ClientsManagementMap::iterator it = clientsManager_.begin(); it != clientsManager_.end(); ++it)
    {
        std::shared_ptr<IClusterMgtClientsManagement> clusterMgtClientManagement = it->second;
        clusterMgtClientManagement->shutdown();
    }
}

void ClusterMgtController::addAcceptedIpcClient(const Network::IpSocketEndpoint& remoteEndPoint, std::shared_ptr<Ipc::IIpcClient> ipcClient, ClientType type)
{
    ClientsManagementMap::iterator it = clientsManager_.find(type);
    if (it == clientsManager_.end())
    {
        TRACE_WARNING("Accept client from type = " << type << ", but can not find this type of client manager!");
        return;
    }

    clientsManager_[type]->addAcceptedIpcClient(remoteEndPoint, ipcClient);
}

void ClusterMgtController::removeAcceptedIpcClient(const Network::IpSocketEndpoint& remoteEndPoint, ClientType type)
{
    ClientsManagementMap::iterator it = clientsManager_.find(type);
    if (it == clientsManager_.end())
    {
        TRACE_WARNING("Accept client from type = " << type << ", but can not find this type of client manager!");
        return;
    }

    clientsManager_[type]->removeAcceptedIpcClient(remoteEndPoint);
}

void ClusterMgtController::handleMessage(const IpcMessage::IIpcMessage& msg, ClientType fromClientType)
{
    TRACE_DEBUG("fromClientType:" << static_cast<int>(fromClientType));
    clientsManager_[UiType]->handleMessage(msg, fromClientType);
    clientsManager_[NodeType]->handleMessage(msg, fromClientType);
}

void ClusterMgtController::addClientManager(ClientType type, std::shared_ptr<IClusterMgtClientsManagement> clientManager)
{
    ClientsManagementMap::iterator it = clientsManager_.find(type);
    if (it != clientsManager_.end())
    {
        TRACE_NOTICE("Client Manager is already exist for client type = " << type);
    }

    clientsManager_[type] = clientManager;
}

}
