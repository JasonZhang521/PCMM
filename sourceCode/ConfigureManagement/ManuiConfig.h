#ifndef MANUICONFIG_H
#define MANUICONFIG_H
#include <string>
#include <vector>

namespace Serialize {
    class WriteBuffer;
    class ReadBuffer;
}

namespace ConfigureManagement {

class ManuiTagValue
{
    std::string tag_;
    std::string value_;
    bool isSubTag_;
public:
    ManuiTagValue();
    ManuiTagValue(const ManuiTagValue& tagValue);
    ManuiTagValue(const std::string& tag, const std::string& value, bool isSubTag = false);

    ManuiTagValue& operator = (const ManuiTagValue& tagValue);
    bool operator == (const ManuiTagValue& tagValue);
    bool operator != (const ManuiTagValue& tagValue);
    std::ostream& operator << (std::ostream& os) const;

    const std::string& getTag() const;
    const std::string& getValue() const;

    void serialize(Serialize::WriteBuffer& writeBuffer) const;
    void unserialize(Serialize::ReadBuffer& readBuffer);
};

std::ostream& operator << (std::ostream& os, const ManuiTagValue& tagValue);

class ManuiConfigRecord
{
    ManuiTagValue title_;
    bool isMultiTag_;
    std::vector<ManuiTagValue> subItems_;
public:
    ManuiConfigRecord(ManuiTagValue title, bool isMultiTag = false);
    ManuiConfigRecord(const ManuiConfigRecord& configureRecord);
    ManuiConfigRecord& operator = (const ManuiConfigRecord& configureRecord);
    bool operator == (const ManuiConfigRecord& configureRecord);
    bool operator != (const ManuiConfigRecord& configureRecord);
    std::ostream& operator << (std::ostream& os) const;

    void serialize(Serialize::WriteBuffer& writeBuffer) const;
    void unserialize(Serialize::ReadBuffer& readBuffer);
private:
    ManuiConfigRecord();
};

class ManuiConfig
{
public:
    ManuiConfig();
};
}

#endif // MANUICONFIG_H
