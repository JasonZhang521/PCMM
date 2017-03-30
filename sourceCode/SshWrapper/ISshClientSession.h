#ifndef _SSHWRAPPER_ISSHCLIENTSESION_H_
#define _SSHWRAPPER_ISSHCLIENTSESION_H_
#include <string>
namespace SshWrapper
{
class ISshClientSession
{
public:
        ISshClientSession() {}
	virtual ~ISshClientSession() {}

	virtual bool setup() = 0;
	virtual bool shutdown() = 0;
    virtual bool startShellChannel() = 0;
    virtual bool shutdownShellChannel() = 0;
    virtual bool executeShellCommand(const std::string& cmd, std::string& cmdOutput) = 0;
};

}
#endif
