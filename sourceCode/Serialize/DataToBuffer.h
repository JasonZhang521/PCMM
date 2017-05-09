#ifndef _SERIALIZE_DATATOBUFFER_H_
#define _SERIALIZE_DATATOBUFFER_H_

namespace Serialize {

class DataToBuffer
{
public:
    DataToBuffer();
    template <typename T>
    static inline void Write(char* buffer, const T& val)
    {
        *(reinterpret_cast<T*>(buffer)) = val;
    }

    static inline void Write(char* buffer, const char* newBuffer, unsigned int writeSize)
    {
        for(unsigned int i = 0; i < writeSize; ++i)
        {
            buffer[i] = newBuffer[i];
        }
    }
};

}

#endif // _SERIALIZE_DATATOBUFFER_H_
