#include "IpcHeartbeatReport.h"
#include "WriteBuffer.h"
#include "ReadBuffer.h"
namespace IpcMessage {

IpcHeartbeatReport::IpcHeartbeatReport()
{

}

IpcHeartbeatReport::~IpcHeartbeatReport()
{

}

IpcMessage::IpcComunicationMessageType IpcHeartbeatReport::getComunicationMessageType() const
{
    return IpcMessage::IpcComunicationMessageType::IpcHeartbeatReportMessage;
}

void IpcHeartbeatReport::serialize(Serialize::WriteBuffer& writeBuffer) const
{
    writeBuffer.write<uint8_t>(static_cast<uint8_t>(IpcMessage_IpcComunication));
    writeBuffer.write<uint8_t>(static_cast<uint8_t>(IpcHeartbeatReportMessage));
    IIpcMessage::write(writeBuffer);
}
void IpcHeartbeatReport::unserialize(Serialize::ReadBuffer& readBuffer)
{
    uint8_t temp = 0;
    readBuffer.read(temp);
    readBuffer.read(temp);
    IIpcMessage::read(readBuffer);
}

std::ostream& IpcHeartbeatReport::operator<< (std::ostream& os) const
{
    os << "["
       << ", ipcMessageType=" << IpcMessageTypeString(IpcMessage_IpcComunication)
       << ", IpcHeartbeatType=" << IpcHeartbeatTypeString(IpcHeartbeatReportMessage);
    IpcMessage::IIpcMessage::print(os);
    return os;
}

}
