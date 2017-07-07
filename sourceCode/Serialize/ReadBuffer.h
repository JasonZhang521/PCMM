#ifndef _SERIALIZE_READBUFFER_H_
#define _SERIALIZE_READBUFFER_H_
#include "BufferToData.h"
#include "Component.h"
#include "Macro.h"
#include <ostream>
namespace Serialize {

class ReadBuffer
{
public:
    const static unsigned int DefaultReadBufferSize;
private:
    unsigned int bufferSize_;
    char* buffer_;
    unsigned int dataSize_;
    unsigned int pos_;
public:
    ReadBuffer(unsigned int bufferSize = DefaultReadBufferSize);
    ~ReadBuffer();
    template <typename T>
    bool read(T& val)
    {
        if (pos_ + sizeof(T) > dataSize_)
        {
            return false;
        }
        val = BufferToData::Read<T>(buffer_ + pos_);
        pos_ += sizeof(T);
        return true;
    }

    bool read(void* newBuffer, unsigned int readSize);

    template <typename T>
    bool peek(T& val, unsigned int start = 0)
    {
        if (pos_ + start + sizeof(T) > dataSize_)
        {
            return false;
        }
        val = BufferToData::Read<T>(buffer_ + pos_ + start);
        return true;
    }

    void* getBuffer() const;
    unsigned int getDataSize() const;
    void setDataSize(unsigned int dataSize);
    unsigned int getBufferSize() const;

    void swap(ReadBuffer& buffer);
    bool operator==(const ReadBuffer& buffer);

    std::ostream& operator << (std::ostream& os) const;

public:
    GETCLASSNAME(ReadBuffer)
};

}

inline std::ostream& operator << (std::ostream& os, const Serialize::ReadBuffer& buffer)
{
    return buffer.operator <<(os);
}


#endif // _SERIALIZE_READBUFFERR_H_
