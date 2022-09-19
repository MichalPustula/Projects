#include "gtest/gtest.h"

#include "../include/Array.hpp"
#include <vector>

TEST(ArrayTests, atMethodPastSize)
{
    Array<int, 5> array;
    EXPECT_THROW(array.at(5), std::out_of_range);
}

TEST(ArrayTests, atMethodWithinBond)
{
    Array<int, 5> array{};
    EXPECT_EQ(array.at(0), 0);
}


TEST(ArrayTests, TestingReadingWithAccesOperator)
{
    Array<int, 2> array;
    array[0] = 4;
    array[1] = 7;

    const auto& array_ref = array;
    EXPECT_EQ(array_ref[1], 7);
}


TEST(ArrayTests, CreatingArrayWith5elementsAssigningAndReadingWithAccessOperator)
{
    Array<int, 5> array;

    for (size_t i = 0; i < array.size(); i++)
    {
        array[i] = i;
    }

    for (size_t i = 0; i < array.size(); i++)
    {
        EXPECT_EQ(array[i], i);
    }
}

TEST(ArrayTests, CreatingEmptyArraySetingElementWithAccessOperator)
{
    Array<int, 1> array;

    array[0] = 7;
    EXPECT_EQ(array.size(), 1);
}


