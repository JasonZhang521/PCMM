#include "ShellCommandRequest.h"
#include "WriteBuffer.h"
#include "ReadBuffer.h"
namespace ShellCommandMessage {

ShellCommandRequest::ShellCommandRequest()
{
}

ShellCommandRequest::~ShellCommandRequest()
{

}

void ShellCommandRequest::serialize(Serialize::WriteBuffer& writeBuffer) const
{

}
void ShellCommandRequest::unserialize(Serialize::ReadBuffer& readBuffer)
{

}

IpcMessage::IpcShellCommandMessageType ShellCommandRequest::getShellCommandMessageType() const
{

}

std::ostream& ShellCommandRequest::operator<< (std::ostream& os) const
{

}

}
