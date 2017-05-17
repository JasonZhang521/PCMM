#include "Socket.h"
#include "Component.h"
#include "AppConst.h"
#include "Trace.h"

#include <sstream>
namespace Network {

Socket::Socket(const SocketAddressFamily& addrFamily,
       const SocketType& type,
       const SocketProtocol& protocol)
    :addrFamily_(addrFamily)
    ,type_(type)
    ,protocol_(protocol)
{
    int ret = InitSocket();
    if (ret != SOCKET_SUCCESS)
    {
        TRACE_ERROR("Can not init the socket, " << getErrorInfo());
    }
    fd_ = CreateSocket(addrFamily, type, protocol);
}

Socket::~Socket()
{

}

std::string Socket::getErrorInfo()
{
    int errno = GetLastSocketErrorNo();
    std::string errorInfo = GetSocketErrorMessageFromErrorCode(errno);
    std::stringstream ss;
    ss << "Errno = " << errno << ", errorInfo = " << errorInfo;
    return ss.str();
}

}
