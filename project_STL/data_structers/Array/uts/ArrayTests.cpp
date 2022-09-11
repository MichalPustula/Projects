#include "gtest/gtest.h"

#include "../include/Array.hpp"





TEST(ArrayTests, CreatingArray)
{
    Array<int, 5> array;
    array[2] = 5;
    EXPECT_EQ(array[2], 5);
}

