#ifndef _SERIALIZE_READBUFFER_H_
#define _SERIALIZE_READBUFFER_H_
#include "BufferToData.h"
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

    bool setDataSize(unsigned int dataSize);
    char* getBuffer() const;
    unsigned int getBufferSize() const;
    unsigned int getDataSize() const;

    void swap(ReadBuffer& buffer);
    bool operator==(const ReadBuffer& buffer);
};

}

#endif // _SERIALIZE_READBUFFERR_H_
