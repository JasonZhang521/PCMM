#ifndef _SERIALIZE_READBUFFER_H_
#define _SERIALIZE_READBUFFER_H_
#include "BufferToData.h"
namespace Serialize {

class ReadBuffer
{
    unsigned int bufferSize_;
    char* buffer_;
    unsigned int dataSize_;
    unsigned int pos_;
public:
    ReadBuffer(unsigned int bufferSize);
    ~ReadBuffer();
    template <typename T>
    bool Read(T& val)
    {
        if (pos_ + sizeof(T) >= dataSize_)
        {
            return false;
        }
        val = BufferToData::Read<T>(buffer_ + pos_);
        pos_ += sizeof(T);
        return true;
    }

    bool Read(char* newBuffer, unsigned int readSize);

    bool setDataSize(unsigned int dataSize);
    char* getBuffer() const;

public:
    const static unsigned int DefaultReadBufferSize;
};

}

#endif // _SERIALIZE_READBUFFERR_H_
