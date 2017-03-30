#ifndef _SSHWRAPPER_ISSHCLIENT_H_
#define _SSHWRAPPER_ISSHCLIENT_H_
#include <string>

namespace SshWrapper
{

class ISshClient
{
public:
	ISshClient();
	virtual ~ISshClient();
	virtual bool setup() = 0;
	virtual bool shutdown() = 0;
	virtual bool startShell() = 0;
	virtual bool shutdownShell() = 0;
	virtual bool executeShellCommand(const std::string& cmd, std::string& cmdOutput) = 0;
};

}
#endif
