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
    EXPECT_EQ(calculate_next_odd(3), 10);
}

TEST(series_tests, calculate_even)
{
    EXPECT_EQ(calculate_next_even(4), 2);
}