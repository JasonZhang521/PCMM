#ifndef _SSHWRAPPER_SSHCLIENT_H_
#define _SSHWRAPPER_SSHCLIENT_H_
#include "ISshClient.h"
#include "Componet.h"
#include "Macro.h"

namespace SshWrapper
{

class ISshClientSession;

class SshClient : public ISshClient
{
    ISshClientSession* session_;
public:
	SshClient(ISshClientSession* session);
	virtual ~SshClient();
protected:
	virtual bool setup();
	virtual bool shutdown();
	virtual bool startShell();
	virtual bool shutdownShell();
	virtual bool executeShellCommand(const std::string& cmd, std::string& cmdOutput);

    virtual bool startSftp();
    virtual bool shutdownSftp();
    virtual bool getFile(const std::string& remoteFile, const std::string& localDir);
    virtual bool putFile(const std::string& localFile, const std::string& remoteDir);

public:
     GETCLASSNAME(SshClient)
};

}
#endif
