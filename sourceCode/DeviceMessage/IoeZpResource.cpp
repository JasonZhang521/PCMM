#include "IoeZpResource.h"
#include "WriteBuffer.h"
#include "ReadBuffer.h"
namespace DeviceMessage {

void UsrOptsBz06::serialize(Serialize::WriteBuffer& writeBuffer) const
{
    writeBuffer.write(devName, 16);
    writeBuffer.write(upInfoDelay);
}

void UsrOptsBz06::unserialize(Serialize::ReadBuffer& readBuffer)
{
    readBuffer.read(devName, 16);
    readBuffer.read(upInfoDelay);
}

void UsrOptsBz06::print(std::ostream& os) const
{
    os << "["
       << "devName=" << std::string(devName, 16)
       << ", upInfoDelay=" << upInfoDelay
       << "]";
}

void DevoptsBz06::serialize(Serialize::WriteBuffer& writeBuffer) const
{
    writeBuffer.write(devNumber);
    writeBuffer.write(modeINum);
    writeBuffer.write(date);
}

void DevoptsBz06::unserialize(Serialize::ReadBuffer& readBuffer)
{
    readBuffer.read(devNumber);
    readBuffer.read(modeINum);
    readBuffer.read(date);
}

void DevoptsBz06::print(std::ostream& os) const
{
    os << "["
       << "devNumber=" << devNumber
       << ", modeINum=" << modeINum
       << ", date=" << date
       << "]";
}

void RunDataBz06::serialize(Serialize::WriteBuffer& writeBuffer) const
{
    writeBuffer.write(temp1);
    writeBuffer.write(temp2);
    writeBuffer.write(hum);
    writeBuffer.write(output);
    writeBuffer.write(input);
    writeBuffer.write(battVol);
}

void RunDataBz06::unserialize(Serialize::ReadBuffer& readBuffer)
{
    readBuffer.read(temp1);
    readBuffer.read(temp2);
    readBuffer.read(hum);
    readBuffer.read(output);
    readBuffer.read(input);
    readBuffer.read(battVol);
}

void RunDataBz06::print(std::ostream& os) const
{
    os << "["
       << "temp1=" << temp1
       << ", temp2=" << temp2
       << ", hum=" << hum
       << ", output=" << static_cast<int>(output)
       << ", input=" << input
       << ", battVol=" << battVol
       << "]";
}

void OutCtlBz06::serialize(Serialize::WriteBuffer& writeBuffer) const
{
    writeBuffer.write(delay);
    writeBuffer.write(reserved);
}

void OutCtlBz06::unserialize(Serialize::ReadBuffer& readBuffer)
{
    readBuffer.read(delay);
    readBuffer.read(reserved);
}

void OutCtlBz06::print(std::ostream& os) const
{
    os << "["
       << "delay=" << delay
       << ", reserved=" << static_cast<int>(reserved)
       << "]";
}

IoeZpResource::IoeZpResource()
    : resourceId(0)
    , resource(nullptr)
{}

IoeZpResource::IoeZpResource(uint16_t resId)
    :resourceId(resId)
{
    allocate();
}

IoeZpResource::IoeZpResource(const IoeZpResource& res)
    :resourceId(res.resourceId)
{
    allocate();
    copy(res.resource);
}

IoeZpResource& IoeZpResource::operator=(const IoeZpResource& res)
{
    if (resourceId == res.resourceId)
    {
        copy(res.resource);
    }
    else
    {
        resourceId = res.resourceId;
        dellocate();
        allocate();
        copy(res.resource);
    }
    return *this;
}


IoeZpResource::~IoeZpResource()
{
    dellocate();
}

void IoeZpResource::serialize(Serialize::WriteBuffer& writeBuffer) const
{
    switch (resourceId) {
    case USROPTS_BZ06:
    {
        UsrOptsBz06* pRes = reinterpret_cast<UsrOptsBz06*>(resource);
        pRes->serialize(writeBuffer);
        break;
    }
    case DEVOPTS_BZ06:
    {
        DevoptsBz06* pRes = reinterpret_cast<DevoptsBz06*>(resource);
        pRes->serialize(writeBuffer);
        break;
    }
    case RUNDATA_BZ06:
    {
        RunDataBz06* pRes = reinterpret_cast<RunDataBz06*>(resource);
        pRes->serialize(writeBuffer);
        break;
    }
    case OUTCTL_BZ06:
    {
        OutCtlBz06* pRes = reinterpret_cast<OutCtlBz06*>(resource);
        pRes->serialize(writeBuffer);
        break;
    }
    case RELATED_BZ06:
        break;
    default:
        break;
    }
}

void IoeZpResource::unserialize(Serialize::ReadBuffer& readBuffer)
{
    switch (resourceId) {
    case USROPTS_BZ06:
    {
        UsrOptsBz06* pRes = reinterpret_cast<UsrOptsBz06*>(resource);
        pRes->unserialize(readBuffer);
        break;
    }
    case DEVOPTS_BZ06:
    {
        DevoptsBz06* pRes = reinterpret_cast<DevoptsBz06*>(resource);
        pRes->unserialize(readBuffer);
        break;
    }
    case RUNDATA_BZ06:
    {
        RunDataBz06* pRes = reinterpret_cast<RunDataBz06*>(resource);
        pRes->unserialize(readBuffer);
        break;
    }
    case OUTCTL_BZ06:
    {
        OutCtlBz06* pRes = reinterpret_cast<OutCtlBz06*>(resource);
        pRes->unserialize(readBuffer);
        break;
    }
    case RELATED_BZ06:
        break;
    default:
        break;
    }
}

void IoeZpResource::print(std::ostream& os) const
{
    switch (resourceId) {
    case USROPTS_BZ06:
    {
        UsrOptsBz06* pRes = reinterpret_cast<UsrOptsBz06*>(resource);
        pRes->print(os);
        break;
    }
    case DEVOPTS_BZ06:
    {
        DevoptsBz06* pRes = reinterpret_cast<DevoptsBz06*>(resource);
        pRes->print(os);
        break;
    }
    case RUNDATA_BZ06:
    {
        RunDataBz06* pRes = reinterpret_cast<RunDataBz06*>(resource);
        pRes->print(os);
        break;
    }
    case OUTCTL_BZ06:
    {
        OutCtlBz06* pRes = reinterpret_cast<OutCtlBz06*>(resource);
        pRes->print(os);
        break;
    }
    case RELATED_BZ06:
        break;
    default:
        break;
    }
}

void IoeZpResource::dellocate()
{
    switch (resourceId) {
    case USROPTS_BZ06:
        delete reinterpret_cast<UsrOptsBz06*>(resource);
        break;
    case DEVOPTS_BZ06:
        delete reinterpret_cast<DevoptsBz06*>(resource);
        break;
    case RUNDATA_BZ06:
        delete reinterpret_cast<RunDataBz06*>(resource);
        break;
    case OUTCTL_BZ06:
        delete reinterpret_cast<OutCtlBz06*>(resource);
        break;
    case RELATED_BZ06:
        break;
    default:
        break;
    }
}

void IoeZpResource::allocate()
{
    switch (resourceId) {
    case USROPTS_BZ06:
        resource = new UsrOptsBz06();
        break;
    case DEVOPTS_BZ06:
        resource = new DevoptsBz06();
        break;
    case RUNDATA_BZ06:
        resource = new RunDataBz06();
        break;
    case OUTCTL_BZ06:
        resource = new OutCtlBz06();
        break;
    case RELATED_BZ06:
        break;
    default:
        break;
    }
}

void IoeZpResource::copy(void* otherResource)
{
    size_t len = 0;
    switch (resourceId) {
    case USROPTS_BZ06:
        len = sizeof(UsrOptsBz06);
        break;
    case DEVOPTS_BZ06:
        len = sizeof(DevoptsBz06);
        break;
    case RUNDATA_BZ06:
        len = sizeof(RunDataBz06);
        break;
    case OUTCTL_BZ06:
        len = sizeof(OutCtlBz06);
        break;
    case RELATED_BZ06:
    default:
        break;
    }

    memcpy(resource, otherResource, len);
}

}
