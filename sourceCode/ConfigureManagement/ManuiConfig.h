#ifndef _CONFIGUREMANAGEMENT_MANUICONFIG_H_
#define _CONFIGUREMANAGEMENT_MANUICONFIG_H_
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
    bool operator == (const ManuiTagValue& tagValue) const;
    bool operator != (const ManuiTagValue& tagValue) const;
    std::ostream& operator << (std::ostream& os) const;

    const std::string& getTag() const;
    const std::string& getValue() const;

    void serialize(Serialize::WriteBuffer& writeBuffer) const;
    void unserialize(Serialize::ReadBuffer& readBuffer);
};

inline std::ostream& operator << (std::ostream& os, const ManuiTagValue& tagValue)
{
    return tagValue.operator <<(os);
}

class ManuiConfigRecord
{
    ManuiTagValue title_;
    bool isMultiTag_;
    std::vector<ManuiTagValue> subItems_;
public:
    ManuiConfigRecord();
    ManuiConfigRecord(ManuiTagValue title, bool isMultiTag = false);
    ManuiConfigRecord(const ManuiConfigRecord& configureRecord);
    ManuiConfigRecord& operator = (const ManuiConfigRecord& configureRecord);
    bool operator == (const ManuiConfigRecord& configureRecord) const;
    bool operator != (const ManuiConfigRecord& configureRecord) const;
    std::ostream& operator << (std::ostream& os) const;

    const ManuiTagValue& getTitle() const {return title_;}
    void setTitle(const ManuiTagValue& title) {title_ = title;}
    const std::vector<ManuiTagValue>& getSubItems() const {return subItems_;}
    void setSubItems(const std::vector<ManuiTagValue>& subItems)
    {
        subItems_ = subItems;
    }

    void serialize(Serialize::WriteBuffer& writeBuffer) const;
    void unserialize(Serialize::ReadBuffer& readBuffer);
};

inline std::ostream& operator << (std::ostream& os, const ManuiConfigRecord& record)
{
    return record.operator <<(os);
}

class ManuiConfig
{
    std::vector<ManuiConfigRecord> records_;
public:
    ManuiConfig();
    ManuiConfig(const ManuiConfig& config);
    ManuiConfig(const std::vector<ManuiConfigRecord>& records);

    bool operator == (const ManuiConfig& configure) const;
    bool operator != (const ManuiConfig& configure) const;
    std::ostream& operator << (std::ostream& os) const;

    const std::vector<ManuiConfigRecord>& getRecords() const;
    void setRecords(const std::vector<ManuiConfigRecord>& records);
    void updateRecord(const ManuiConfigRecord& newRecord);

    void serialize(Serialize::WriteBuffer& writeBuffer) const;
    void unserialize(Serialize::ReadBuffer& readBuffer);
};

inline std::ostream& operator << (std::ostream& os, const ManuiConfig& config)
{
    return config.operator <<(os);
}

}

#endif // _CONFIGUREMANAGEMENT_MANUICONFIG_H_
