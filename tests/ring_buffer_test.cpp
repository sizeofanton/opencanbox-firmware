#include <gtest/gtest.h>
#include "../source/data/ring_buffer/ring_buffer.h"

namespace {

TEST(RinBufferTests, AddTest) {
    RingBuffer rBuffer;
    rBuffer.put(1);
    EXPECT_EQ(true, rBuffer.available());
}

}
