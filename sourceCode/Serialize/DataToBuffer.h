#ifndef _SERIALIZE_DATATOBUFFER_H_
#define _SERIALIZE_DATATOBUFFER_H_

namespace Serialize {

class DataToBuffer
{
public:
    DataToBuffer();
    template <typename T>
    static inline unsigned int Write(char* buffer, const T& val)
    {
        const char* from = reinterpret_cast<const char*>(&val);
        const unsigned int len = sizeof(T);
        for(unsigned int i = 0; i < len; ++i)
        {
            buffer[i] = from[i];
        }
        return len;
    }

    static inline unsigned int Write(char* buffer, const char* newBuffer, unsigned int writeSize)
    {
        for(unsigned int i = 0; i < writeSize; ++i)
        {
            buffer[i] = newBuffer[i];
        }
        return writeSize;
    }
};

}

#endif // _SERIALIZE_DATATOBUFFER_H_
