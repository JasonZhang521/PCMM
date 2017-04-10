#include "SshFtpSession.h"
#include "FilePathHandler.h"
#include "App.h"
#include "Trace.h"

#include <libssh/sftp.h>

namespace SshWrapper
{

SshFtpSession::SshFtpSession(ssh_session session)
: session_(session)
, sftpSession_(sftp_new(session_))
{
    if (sftpSession_ == nullptr)
    {
        TRACE_WARNING("Session is NULL when initial shell channel!");
        App::ExitNormal();
    }

    if (sftpSession_ == nullptr)
    {
        TRACE_WARNING("Session is NULL when initial shell channel!");
        App::ExitNormal();
    }
}

SshFtpSession::~SshFtpSession()
{
    if (sftpSession_ != nullptr)
    {
        sftp_free(sftpSession_);
    }
}

bool SshFtpSession::setup()
{
    int rc = sftp_init(sftpSession_);
    if (rc != SSH_OK)
    {
      TRACE_WARNING("Error init FTP: rc = " << rc << ", error info:" << sftp_get_error(sftpSession_));
      return false;
    }
    return true;
}

bool SshFtpSession::shutdown()
{
    return true;
}

bool SshFtpSession::getFile(const std::string& remoteFile, const std::string& localDir)
{
    sftp_file file = sftp_open(sftpSession_, remoteFile.c_str(), O_RDONLY, 0);
    if (file == nullptr)
    {
        TRACE_WARNING("Error open remote file:" << remoteFile << ", error info:" << sftp_get_error(sftpSession_));
        return false;
    }

    // create a empty file in local
    const std::string FileName = FilePathHandler::getFileName(remoteFile);
    const std::string FilePath = localDir + "/" + FileName;
    int fd = open(FilePath.c_str(), O_CREAT);
    if (fd < 0)
    {
        TRACE_WARNING("Error create local file:" << FilePath << ", error info:" << strerror(errno));
        sftp_close(file);
        return false;
    }

    char buffer[MAX_XFER_BUF_SIZE];
    int nbytes = sftp_read(file, buffer, sizeof(buffer));
    while (nbytes > 0)
    {
        int nwritten = write(fd, buffer, nbytes);
        if (nwritten != nbytes)
        {
            TRACE_WARNING("Error write local file:" << FilePath << ", error info:" << strerror(errno));
            close(fd);
            sftp_close(file);
            return false;
        }
    }

    int rc = close(fd);
    if (rc < 0)
    {
        TRACE_WARNING("Error close local file:" << FilePath << ", error info:" << strerror(errno));
        sftp_close(file);
        return false;
    }

    if (nbytes < 0)
    {
        TRACE_WARNING("Error read remote file:" << remoteFile << ", error info:" << sftp_get_error(sftpSession_));
        sftp_close(file);
        return false;
    }

    rc = sftp_close(file);
    if (rc != SSH_OK)
    {
        TRACE_WARNING("Error close the remote file:" << remoteFile << ", error info:" << sftp_get_error(sftpSession_));
        return false;
    }

    return true;
}

bool putFile(const std::string& localFile, const std::string& remoteDir)
{
    int fd = open(localFile.c_str(), O_RDONLY);
    if (fd < 0)
    {
        TRACE_WARNING("Error create local file:" << FilePath << ", error info:" << strerror(errno));
        return false;
    }
    // create a empty file in local
    const std::string FileName = FilePathHandler::getFileName(localFile);
    const std::string FilePath = remoteDir + "/" + FileName;
    sftp_file file = sftp_open(sftpSession_, FilePath.c_str(), O_CREAT);
    if (file == nullptr)
    {
        TRACE_WARNING("Error create remote file:" << FilePath << ", error info:" << sftp_get_error(sftpSession_));
        close(fd);
        return false;
    }

    char buffer[MAX_XFER_BUF_SIZE];
    int nbytes = read(fd, buffer, sizeof(buffer));
    while (nbytes > 0)
    {
        int nwritten = sftp_write(file, buffer, nbytes);
        if (nwritten != nbytes)
        {
            TRACE_WARNING("Error write remote file:" << FilePath << ", error info:" << sftp_get_error(sftpSession_));
            sftp_close(file);
            close(fd);
            return false;
        }
    }

    int rc = sftp_close(file);
    if (rc != SSH_OK)
    {
        TRACE_WARNING("Error close remote file:" << FilePath << ", error info:" << sftp_get_error(sftpSession_));
        close(fd);
        return false;
    }

    if (nbytes < 0)
    {
        TRACE_WARNING("Error read local file:" << remoteFile << ", error info:" << strerror(errno));
        close(fd);
        return false;
    }

    rc = close(fd);
    if (rc < 0)
    {
        TRACE_WARNING("Error close the local file:" << remoteFile << ", error info:" << strerror(errno));
        return false;
    }

    return true;
}

}
