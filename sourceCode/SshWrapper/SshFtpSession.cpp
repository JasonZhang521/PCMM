#include "SshFtpSession.h"
#include "FilePathHandler.h"
#include "App.h"
#include "Trace.h"

#include <libssh/sftp.h>
#include <fstream>
#include <fcntl.h>

namespace SshWrapper
{

SshFtpSession::SshFtpSession(ssh_session session)
: session_(session)
, sftpSession_(sftp_new(session_))
{
    if (sftpSession_ == NULL)
    {
        TRACE_WARNING("Session is NULL when initial shell channel!");
        App::ExitNormal();
    }

    if (sftpSession_ == NULL)
    {
        TRACE_WARNING("Session is NULL when initial shell channel!");
        App::ExitNormal();
    }
}

SshFtpSession::~SshFtpSession()
{
    if (sftpSession_ != NULL)
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
    if (file == NULL)
    {
        TRACE_WARNING("Error open remote file:" << remoteFile << ", error info:" << sftp_get_error(sftpSession_));
        return false;
    }

    // create a empty file in local
    const std::string FileName = FilePathHandler::getFileName(remoteFile);
    const std::string FilePathTemp = localDir + "/" + FileName;
    const std::string FilePath = FilePathHandler::generateUniqueFileName(FilePathTemp);
    std::ofstream outfile(FilePath.c_str(), std::ofstream::binary);
    char buffer[MAX_XFER_BUF_SIZE];
    int nbytes = sftp_read(file, buffer, sizeof(buffer));
    while (nbytes > 0)
    {
        outfile.write(buffer, nbytes);
        nbytes = sftp_read(file, buffer, sizeof(buffer));
    }

    if (nbytes < 0)
    {
        TRACE_WARNING("Error read remote file:" << remoteFile << ", error info:" << sftp_get_error(sftpSession_));
        sftp_close(file);
        return false;
    }

    int rc = sftp_close(file);
    if (rc != SSH_OK)
    {
        TRACE_WARNING("Error close the remote file:" << remoteFile << ", error info:" << sftp_get_error(sftpSession_));
        return false;
    }

    return true;
}

bool SshFtpSession::putFile(const std::string& localFile, const std::string& remoteDir)
{
    std::ifstream infile(localFile.c_str(), std::ifstream::binary);
    // create a empty file in remote
    const std::string FileName = FilePathHandler::getFileName(localFile);
    const std::string FilePath = remoteDir + "/" + FileName;
    sftp_file file = sftp_open(sftpSession_, FilePath.c_str(), O_CREAT, 0);
    if (file == NULL)
    {
        TRACE_WARNING("Error create remote file:" << FilePath << ", error info:" << sftp_get_error(sftpSession_));
        return false;
    }

    char buffer[MAX_XFER_BUF_SIZE];
    std::streamsize nbytes = infile.readsome(buffer, sizeof(buffer));
    while (nbytes > 0)
    {
        int nwritten = sftp_write(file, buffer, nbytes);
        if (nwritten != nbytes)
        {
            TRACE_WARNING("Error write remote file:" << FilePath << ", error info:" << sftp_get_error(sftpSession_));
            sftp_close(file);
            return false;
        }
        nbytes = infile.readsome(buffer, sizeof(buffer));
    }

    int rc = sftp_close(file);
    if (rc != SSH_OK)
    {
        TRACE_WARNING("Error close remote file:" << FilePath << ", error info:" << sftp_get_error(sftpSession_));
        return false;
    }

    return true;
}

}
