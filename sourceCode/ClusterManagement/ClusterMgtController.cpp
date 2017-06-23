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

void ClusterMgtController::addAcceptedIpcClient(const std::string& remoteEndPoint, std::shared_ptr<Ipc::IIpcClient> ipcClient, ClientType type)
{
    ClientsManagementMap::iterator it = clientsManager_.find(type);
    if (it == clientsManager_.end())
    {
        TRACE_WARNING("Accept client from type = " << type << ", but can not find this type of client manager!");
        return;
    }

    clientsManager_[type]->addAcceptedIpcClient(remoteEndPoint, ipcClient);
}

void ClusterMgtController::handleMessage(const IpcMessage::IIpcMessage& msg, ClientType fromClientType)
{
    switch (fromClientType) {
    case NodeType:
        clientsManager_[UiType]->handleMessage(msg);
        break;
    case UiType:
        clientsManager_[NodeType]->handleMessage(msg);
        break;
    default:
        break;
    }
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
