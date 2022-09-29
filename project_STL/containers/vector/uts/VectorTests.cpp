#include "gtest/gtest.h"

#include "../include/Vector.hpp"





TEST(VectorTests, CreatingVector)
{
    Vector<int> vector;
    EXPECT_EQ(vector.capacity(), 0);
}
