#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "ReadBuffer.h"
#include "WriteBuffer.h"
#include "Random.h"

class ReadWriteBufferTest : public ::testing::Test
{

};

TEST_F(ReadWriteBufferTest, TestSameType)
{
    {
        Serialize::WriteBuffer writeBuffer;
        Serialize::ReadBuffer readBuffer;
        int intVal1 = 10;
        int intVal2 = 100;
        writeBuffer.write(intVal1);
        writeBuffer.write(intVal2);
        std::copy(writeBuffer.getBuffer(), writeBuffer.getBuffer() + writeBuffer.getDataSize(), readBuffer.getBuffer());
        int readVal = 0;
        readBuffer.read(readVal);
        ASSERT_EQ(intVal1, readVal);
        readBuffer.read(readVal);
        ASSERT_EQ(intVal2, readVal);
    }

    uint64_t uint64Val = 123445666;
}
