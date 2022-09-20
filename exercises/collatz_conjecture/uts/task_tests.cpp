#include "gtest/gtest.h"

#include "../include/collatz_conjecture.hpp"


TEST(series_tests, calculateSeriesExmple3)
{
    Result result = calculate(27);
    EXPECT_EQ(result.max, 9232);
    EXPECT_EQ(result.steps, 111);
}

TEST(series_tests, calculateSeriesExmple2)
{
    Result result = calculate(12);
    EXPECT_EQ(result.max, 16);
    EXPECT_EQ(result.steps, 9);
}

TEST(series_tests, calculateSeriesExample1)
{
    Result result = calculate(5);
    EXPECT_EQ(result.max, 16);
    EXPECT_EQ(result.steps, 5);
}

TEST(series_tests, calculate_odd)
{
    uint32_t temp = 3;
    calculate_next_odd(temp);
    EXPECT_EQ(temp, 10);
}

TEST(series_tests, calculate_even)
{
    uint32_t temp = 4;
    calculate_next_even(temp);
    EXPECT_EQ(temp, 2);
}