#ifndef _SSHWRAPPER_SSHCLIENTSESSION_H_
#define _SSHWRAPPER_SSHCLIENTSESSION_H_
#include "ISshClientSession.h"
#include "SshConfigure.h"
#include <map>
#include <string>

struct ssh_session_struct;
typedef struct ssh_session_struct* ssh_session;
 
namespace SshWrapper
{
class ISshShellChannel;

class SshClientSession : public ISshClientSession
{
	ssh_session session_;
	SshConfigure configure_;
    ISshShellChannel* shellChannel_;
public:
	SshClientSession(ssh_session session, ISshShellChannel* channel, const SshConfigure& configure);
	virtual ~SshClientSession();

	void configure(const SshConfigure& config);
protected:
	virtual bool setup();
	virtual bool shutdown();
        virtual bool startShellChannel();
        virtual bool shutdownShellChannel();
        virtual bool executeShellCommand(const std::string& cmd, std::string& cmdOutput);
private:
	void setOptions();
	bool connect();
	void disconnect();
	bool verifyKnownhost();
	bool verifyUser();
};

}
#endif
