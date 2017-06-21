#include "ClustersManagementHandler.h"

namespace ClustersManagement {

ClustersManagementHandler::ClustersManagementHandler()
{

}

ClustersManagementHandler::~ClustersManagementHandler()
{

}

void ClustersManagementHandler::addAcceptedIpcClient(int fd, std::shared_ptr<Ipc::IpcClient> ipcClient)
{

}

void forwardIpcMessage(std::unique_ptr<IpcMessage::IIpcMessage> msg);

}
