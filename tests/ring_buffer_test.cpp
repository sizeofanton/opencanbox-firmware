#include <gtest/gtest.h>
#include "../source/data/ring_buffer/ring_buffer.h"

TEST(RinBufferTests, AddTest) {
    RingBuffer rBuffer;
    rBuffer.put(1);
    ASSERT_TRUE(rBuffer.available());
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}