#ifndef _SSHWRAPPER_ISSHSESION_H_
#define _SSHWRAPPER_ISSHSESION_H_
namespace SshWrapper
{
class ISshSession
{
public:
    ISshSession() {}
	virtual ~ISshSession() {}

	virtual bool setup() = 0;
	virtual bool shutdown() = 0;
};

}
#endif
