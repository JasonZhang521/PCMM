#include "ManuiConfig.h"
#include "WriteBuffer.h"
#include "ReadBuffer.h"
#include <algorithm>
#include <ostream>

namespace ConfigureManagement {

// ManuiTagValue

ManuiTagValue::ManuiTagValue()
    : isSubTag_(false)
{

}

ManuiTagValue::ManuiTagValue(const ManuiTagValue& tagValue)
    : tag_(tagValue.tag_)
    , value_(tagValue.value_)
    , isSubTag_(tagValue.isSubTag_)
{
}

ManuiTagValue::ManuiTagValue(const std::string& tag, const std::string& value, bool isSubTag)
    : tag_(tag)
    , value_(value)
    , isSubTag_(isSubTag)
{

}

ManuiTagValue& ManuiTagValue::operator = (const ManuiTagValue& tagValue)
{
    tag_ = tagValue.tag_;
    value_ = tagValue.value_;
    isSubTag_ = tagValue.isSubTag_;
    return *this;
}

bool ManuiTagValue::operator == (const ManuiTagValue& tagValue) const
{
    return (tag_ == tagValue.tag_ &&
            value_ == tagValue.value_ &&
            isSubTag_ == tagValue.isSubTag_);
}

bool ManuiTagValue::operator != (const ManuiTagValue& tagValue) const
{
    return !operator ==(tagValue);
}

std::ostream& ManuiTagValue::operator << (std::ostream& os) const
{
    if (isSubTag_)
    {
        os << tag_ << "=" << value_;
    }
    else
    {
        os << tag_ << " " << value_;
    }
    return os;
}

const std::string& ManuiTagValue::getTag() const
{
    return tag_;
}

const std::string& ManuiTagValue::getValue() const
{
    return value_;
}

void ManuiTagValue::serialize(Serialize::WriteBuffer& writeBuffer) const
{
    writeBuffer.write(isSubTag_);
    writeBuffer.write(static_cast<uint8_t>(tag_.size()));
    writeBuffer.write(tag_.c_str(), tag_.size());
    writeBuffer.write(static_cast<uint8_t>(value_.size()));
    writeBuffer.write(value_.c_str(), tag_.size());
}

void ManuiTagValue::unserialize(Serialize::ReadBuffer& readBuffer)
{
    readBuffer.read(isSubTag_);

    char buffer[256];
    std::fill(buffer, buffer + 256, 0);
    uint8_t size = 0;

    readBuffer.read(size);
    readBuffer.read(buffer, size);
    tag_ = std::string(buffer, size);

    readBuffer.read(size);
    readBuffer.read(buffer, size);
    value_ = std::string(buffer, size);
}

// ManuiConfigRecord

ManuiConfigRecord::ManuiConfigRecord()
    : isMultiTag_(false)
{

}

ManuiConfigRecord::ManuiConfigRecord(ManuiTagValue title, bool isMultiTag)
    : title_(title)
    , isMultiTag_(isMultiTag)
{

}

ManuiConfigRecord::ManuiConfigRecord(const ManuiConfigRecord& configureRecord)
    : title_(configureRecord.title_)
    , isMultiTag_(configureRecord.isMultiTag_)
    , subItems_(configureRecord.subItems_)
{

}

ManuiConfigRecord& ManuiConfigRecord::operator = (const ManuiConfigRecord& configureRecord)
{
    title_ = configureRecord.title_;
    isMultiTag_ = configureRecord.isMultiTag_;
    subItems_ = configureRecord.subItems_;
    return *this;
}

bool ManuiConfigRecord::operator == (const ManuiConfigRecord& configureRecord) const
{
    if (title_ != configureRecord.title_ ||
        isMultiTag_ != configureRecord.isMultiTag_ ||
        subItems_.size() != configureRecord.subItems_.size())
    {
        return false;
    }

    for (size_t i = 0; i < subItems_.size(); ++i)
    {
        if (std::find(subItems_.begin(), subItems_.end(), configureRecord.subItems_[i]) == subItems_.end())
        {
            return false;
        }
    }

    return true;
}

bool ManuiConfigRecord::operator != (const ManuiConfigRecord& configureRecord) const
{
    return !operator ==(configureRecord);
}

std::ostream& ManuiConfigRecord::operator << (std::ostream& os) const
{
    if (isMultiTag_)
    {
        os << title_.getTag() << "[" << title_.getValue() << "]";
        for (auto tagValue : subItems_)
        {
            os << " ";
            os << tagValue;
        }
    }
    else
    {
        os << title_;
    }

    return os;
}

void ManuiConfigRecord::serialize(Serialize::WriteBuffer& writeBuffer) const
{
    writeBuffer.write(isMultiTag_);
    title_.serialize(writeBuffer);
    writeBuffer.write(static_cast<uint16_t>(subItems_.size()));
    for (auto it : subItems_)
    {
        it.serialize(writeBuffer);
    }
}

void ManuiConfigRecord::unserialize(Serialize::ReadBuffer& readBuffer)
{
    readBuffer.read(isMultiTag_);
    title_.unserialize(readBuffer);

    std::vector<ManuiTagValue> subItems;
    uint16_t size = 0;
    readBuffer.read(size);
    for (uint16_t i = 0; i < size; ++i)
    {
        ManuiTagValue tagValue;
        tagValue.unserialize(readBuffer);
        subItems.push_back(tagValue);
    }
    subItems_.swap(subItems);
}


ManuiConfig::ManuiConfig()
{
}

ManuiConfig::ManuiConfig(const ManuiConfig& config)
    : records_(config.records_)
{

}

ManuiConfig::ManuiConfig(const std::vector<ManuiConfigRecord>& records)
    :records_(records)
{

}

bool ManuiConfig::operator == (const ManuiConfig& configure) const
{
    if (records_.size() != configure.records_.size())
    {
        return false;
    }

    for (auto record : configure.records_)
    {
        if (std::find(records_.begin(), records_.end(), record) == records_.end())
        {
            return false;
        }
    }

    return true;
}

bool ManuiConfig::operator != (const ManuiConfig& configure) const
{
    return !operator ==(configure);
}

std::ostream& ManuiConfig::operator << (std::ostream& os) const
{
    for (auto record : records_)
    {
        os << record << std::endl;
    }
    return os;
}

const std::vector<ManuiConfigRecord>& ManuiConfig::getRecords() const
{
    return records_;
}

void ManuiConfig::setRecords(const std::vector<ManuiConfigRecord>& records)
{
    records_ = records;
}

void ManuiConfig::updateRecord(const ManuiConfigRecord& newRecord)
{
    std::vector<ManuiConfigRecord>::iterator insertPos = records_.end();
    bool updated = false;
    for (std::vector<ManuiConfigRecord>::iterator it = records_.begin(); it != records_.end(); ++it)
    {
        ManuiConfigRecord& oldRecord = *it;
        if (oldRecord.getTitle() == newRecord.getTitle())
        {
            oldRecord = newRecord;
            updated = true;
            break;
        }
        else
        {
            if (insertPos == records_.end() && oldRecord.getTitle().getTag() == newRecord.getTitle().getTag())
            {
                insertPos = it;
            }
        }
    }

    if (!updated)
    {
        records_.insert(insertPos, newRecord);
    }
}

void ManuiConfig::serialize(Serialize::WriteBuffer& writeBuffer) const
{
    writeBuffer.write(static_cast<uint16_t>(records_.size()));
    for (auto record : records_)
    {
        record.serialize(writeBuffer);
    }
}

void ManuiConfig::unserialize(Serialize::ReadBuffer& readBuffer)
{
    std::vector<ManuiConfigRecord> records;
    uint16_t size = 0;
    readBuffer.read(size);
    for (uint16_t i = 0; i < size; ++i)
    {
        ManuiConfigRecord record;
        record.unserialize(readBuffer);
        records.push_back(record);
    }

    records_.swap(records);
}

}
