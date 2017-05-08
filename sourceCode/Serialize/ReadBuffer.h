#ifndef _SERIALIZE_READBUFFER_H_
#define _SERIALIZE_READBUFFER_H_

namespace Serialize {

class ReadBuffer
{
    char* buffer_;
    unsigned int size_;
    unsigned int pos_;
public:
    ReadBuffer(unsigned int size);
    ~ReadBuffer();
    template <typename T>
    T Read()
    {
        return *(reinterpret_cast<T*>(&buffer_[pos_]));
        pos_ += sizeof(T);
    }

    void Read(char* newBuffer, unsigned int readSize)
    {
        for (unsigned int i = 0; i < readSize; ++i)
        {
            newBuffer[i] = buffer[pos_ + i];
        }
        pos_ += readSize;
    }
public:
    const static unsigned int DefaultReadBufferSize;
};

}

#endif // _SERIALIZE_READBUFFERR_H_
