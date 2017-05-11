#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "ReadBuffer.h"
#include "WriteBuffer.h"
#include "Random.h"

class ReadWriteBufferTest : public ::testing::Test
{

};

template <typename T>
static TestHelp(std::vector<T> vVal)
{
    Serialize::WriteBuffer writeBuffer;
    Serialize::ReadBuffer readBuffer;
    for (std::vector<T>::iterator it = vVal.begin(); it != vVal.end(); ++it)
    {
        writeBuffer.write(*it);
    }
    std::copy(writeBuffer.getBuffer(), writeBuffer.getBuffer() + writeBuffer.getDataSize(), readBuffer.getBuffer());
    readBuffer.setDataSize(writeBuffer.getDataSize());
    T readVal = T();
    for (std::vector<T>::iterator it = vVal.begin(); it != vVal.end(); ++it)
    {
        readBuffer.read(readVal);
        ASSERT_EQ(*it, readVal);
    }
}

TEST_F(ReadWriteBufferTest, TestSameType)
{
    {
        uint8_t zero = 0;
        uint8_t max = 0xFF;
    }
    {
        Serialize::WriteBuffer writeBuffer;
        Serialize::ReadBuffer readBuffer;
        int intVal1 = 10;
        int intVal2 = 100;
        writeBuffer.write(intVal1);
        writeBuffer.write(intVal2);
        std::copy(writeBuffer.getBuffer(), writeBuffer.getBuffer() + writeBuffer.getDataSize(), readBuffer.getBuffer());
        readBuffer.setDataSize(writeBuffer.getDataSize());
        int readVal = 0;
        readBuffer.read(readVal);
        ASSERT_EQ(intVal1, readVal);
        readBuffer.read(readVal);
        ASSERT_EQ(intVal2, readVal);
    }
    {
        Serialize::WriteBuffer writeBuffer;
        Serialize::ReadBuffer readBuffer;
        int intVal1 = 10;
        int intVal2 = 100;
        writeBuffer.write(intVal1);
        writeBuffer.write(intVal2);
        std::cout << writeBuffer.getDataSize() << std::endl;
        std::copy(writeBuffer.getBuffer(), writeBuffer.getBuffer() + writeBuffer.getDataSize(), readBuffer.getBuffer());
        readBuffer.setDataSize(writeBuffer.getDataSize());
        int readVal = 0;
        readBuffer.read(readVal);
        std::cout << "read:" << readVal << std::endl;
        ASSERT_EQ(intVal1, readVal);
        readBuffer.read(readVal);
        std::cout << "read:" << readVal << std::endl;
        ASSERT_EQ(intVal2, readVal);
    }
}
