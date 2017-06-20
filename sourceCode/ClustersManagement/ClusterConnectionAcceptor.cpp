#include "ClusterConnectionAcceptor.h"
#include "TcpSocket.h"
#include "TcpClient.h"

namespace ClustersManagement {
ClusterConnectionAcceptor::ClusterConnectionAcceptor()
{

}

void ClusterConnectionAcceptor::onAccept(int fd,
                                         const Network::IpSocketEndpoint& localEndPoint,
                                         const Network::IpSocketEndpoint& remoteEndPoint)
{
    createClusterConnection(fd, localEndPoint, remoteEndPoint);
}

void ClusterConnectionAcceptor::createClusterConnection(int fd,
                                                        const Network::IpSocketEndpoint& localEndPoint,
                                                        const Network::IpSocketEndpoint& remoteEndPoint)
{
    std::shared_ptr<Network::TcpSocket> socket(new Network::TcpSocket(fd, localEndPoint, remoteEndPoint));
    std::shared_ptr<Network::TcpClient> tcpAcceptedClient(new Network::TcpClient(socket));
}

}
