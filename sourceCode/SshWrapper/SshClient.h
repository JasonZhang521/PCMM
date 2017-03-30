#ifndef _SSHWRAPPER_SSHCLIENT_H_
#define _SSHWRAPPER_SSHCLIENT_H_
#include "ISshClient.h"

namespace SshWrapper
{

class ISshClientSession;

class SshClient : public ISshClient
{
    ISshClientSession* session_;
public:
	SshClient();
	virtual ~SshClient();
protected:
	virtual bool setup();
	virtual bool shutdown();
	virtual bool startShell();
	virtual bool shutdownShell();
	virtual bool executeShellCommand(const std::string& cmd, std::string& cmdOutput);
};

}
#endif
