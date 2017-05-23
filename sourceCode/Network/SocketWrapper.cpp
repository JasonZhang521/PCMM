#include "SocketWrapper.h"
#ifdef WIN32
#include <algorithm>
#else

#endif

namespace Network {
#ifdef WIN32
int InitSocket()
{
    WORD wVersionRequested = MAKEWORD( 2, 2 );
    WSADATA wsaData;
    int err = WSAStartup( wVersionRequested, &wsaData );
    if ( err != 0 ) {
        /* Tell the user that we could not find a usable */
        /* WinSock DLL.                                  */
        return err;
    }

    /* Confirm that the WinSock DLL supports 2.2.*/
    /* Note that if the DLL supports versions greater    */
    /* than 2.2 in addition to 2.2, it will still return */
    /* 2.2 in wVersion since that is the version we      */
    /* requested.                                        */

    if ( LOBYTE( wsaData.wVersion ) != 2 ||
            HIBYTE( wsaData.wVersion ) != 2 ) {
        /* Tell the user that we could not find a usable */
        /* WinSock DLL.                                  */
        WSACleanup( );
        return UNSUPPORTED_SOCKET_VERION;
    }

    return SOCKET_SUCCESS;
}

std::string GetLastSocketErrorMessage()
{
    int nErrno = WSAGetLastError();
    return GetSocketErrorMessageFromErrorCode(nErrno);
}

std::string GetSocketErrorMessageFromErrorCode(int errorCode)
{
    LPTSTR lpMsgBuf;
    FormatMessage(
        FORMAT_MESSAGE_ALLOCATE_BUFFER |
        FORMAT_MESSAGE_FROM_SYSTEM |
        FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL,
        errorCode,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        (LPTSTR)&lpMsgBuf,
        0,
        NULL
        );
    std::string errorMsg = std::string(reinterpret_cast<char*>(lpMsgBuf));
    LocalFree(lpMsgBuf);
    return errorMsg;
}

#if (_WIN32_WINNT < 0x0600)
int InetPton(SocketAddressFamily af, const char *src, void *dst)
{
    if (af == SOCKET_AF_INET)
    {
        unsigned long addr = ::inet_addr(src);
        *reinterpret_cast<unsigned long*>(dst) = addr;
        return 1;
    }
    else
    {
        return -1;
    }
}

const char* InetNtop(SocketAddressFamily af, const void *src, char *dst, SocketAddresstLength size)
{
    if (af == SOCKET_AF_INET)
    {
        char* to = inet_ntoa(*reinterpret_cast<const struct in_addr*>(src));
        SocketAddresstLength toSize = strlen(to);
        if (toSize > size)
        {
            return nullptr;
        }
        std::copy(to, to + toSize, dst);
        return dst;
    }
    else
    {
        return nullptr;
    }
}
#endif

#else
#endif


int SetBlocking(SocketHandle sockfd, bool blocking)
{
#ifdef WIN32
    unsigned long ul = blocking ? 0 : 1;
    int ret = ioctlsocket(sockfd,FIONBIO, &ul);
    return ret;
#else
    int flags = ::fcntl(fd_, F_GETFL, 0);
    flags = blocking ? flags & (~O_NONBLOCK) : flags | O_NONBLOCK;
    int res = ::fcntl(sockfd, F_SETFL, flags);
    return res;
#endif
}

}
