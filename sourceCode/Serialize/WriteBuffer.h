#ifndef _SERIALIZE_WRITEBUFFER_H_
#define _SERIALIZE_WRITEBUFFER_H_
#include "DataToBuffer.h"
namespace Serialize {

class WriteBuffer
{
    unsigned int bufferSize_;
    char* buffer_;
    unsigned int dataSize_;
    unsigned int pos_;
public:
    WriteBuffer(unsigned int size);
    ~WriteBuffer();

    template <typename T>
    void Write(const T& val)
    {
        if (pos_ + sizeof(T) >= dataSize_)
        {
            resizeBuffer(sizeof(T));
        }
        DataToBuffer::Write<T>(buffer_ + pos_, val);
        pos_ += sizeof(T);
    }

    void Write(const char* newBuffer, unsigned int writeSize);
    char* getBuffer() const;
private:
    void resizeBuffer(unsigned int additionSize);

public:
    const static unsigned int DefaultWriteBufferSize;
};

}

#endif // WRITEBUFFER_H
