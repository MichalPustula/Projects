#include "gtest/gtest.h"

#include "../include/Vector.hpp"

TEST(VectorTests, atMethodAssigningToConstRef)
{
    Vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    const auto& vec_ref = vec;

    EXPECT_EQ(vec_ref.at(0), 10);
    EXPECT_EQ(vec_ref.at(1), 20);
    EXPECT_EQ(vec_ref.size(), 2);
}

TEST(VectorTests, atMethodOutOfBond)
{
    Vector<int> vec;
    EXPECT_THROW(vec.at(0), std::out_of_range);

    vec.push_back(10);
    EXPECT_EQ(vec.at(0), 10);
    EXPECT_THROW(vec.at(1), std::out_of_range);
}

TEST(VectorTests, atMethodWithinBond)
{
    Vector<int> vec;
    vec.push_back(2);
    EXPECT_EQ(vec.at(0), 2);
}

TEST(VectorTests, PushBackElementsAccesElements)
{
    Vector<int> vec;
    int var1 = 10;
    int var2 = 20;
    int var3 = 30;

    vec.push_back(var1);
    EXPECT_EQ(vec[0], 10);

    vec.push_back(var2);
    EXPECT_EQ(vec[0], 10);
    EXPECT_EQ(vec[1], 20);

    vec.push_back(var3);
    EXPECT_EQ(vec[0], 10);
    EXPECT_EQ(vec[1], 20);
    EXPECT_EQ(vec[2], 30);
}

TEST(VectorTests, PushBackTempElementsAccesElements)
{
    Vector<int> vec;

    vec.push_back(10);
    EXPECT_EQ(vec[0], 10);

    vec.push_back(20);
    EXPECT_EQ(vec[0], 10);
    EXPECT_EQ(vec[1], 20);

    vec.push_back(30);
    EXPECT_EQ(vec[0], 10);
    EXPECT_EQ(vec[1], 20);
    EXPECT_EQ(vec[2], 30);
}

TEST(VectorTests, PushBackElementTestSize)
{
    Vector<int> vec;
    EXPECT_EQ(vec.size(), 0);

    vec.push_back(20);
    EXPECT_EQ(vec.size(), 1);

    vec.push_back(30);
    EXPECT_EQ(vec.size(), 2);

    vec.push_back(40);
    EXPECT_EQ(vec.size(), 3);
}

TEST(VectorTests, PushBackElementTestCapacity)
{
    Vector<int> vec;
    EXPECT_EQ(vec.capacity(), 2);

    vec.push_back(20);
    EXPECT_EQ(vec.capacity(), 2);

    vec.push_back(30);
    EXPECT_EQ(vec.capacity(), 2);

    vec.push_back(40);
    EXPECT_EQ(vec.capacity(), 4);
}

TEST(VectorTests, CreatingVectorAssigningToConstRef)
{
    Vector<int> vec;
    vec[0] = 10;
    vec[1] = 20;

    const auto& vec_ref = vec;

    EXPECT_EQ(vec_ref[0], 10);
    EXPECT_EQ(vec_ref[1], 20);
}

TEST(VectorTests, CreatingVectorAccessingElement)
{
    Vector<int> vec;
    vec[0] = 10;
    vec[1] = 20;

    EXPECT_EQ(vec[0], 10);
    EXPECT_EQ(vec[1], 20);
}


TEST(VectorTests, CreatingVector)
{
    Vector<int> vec;
    EXPECT_EQ(vec.capacity(), 2);
    EXPECT_EQ(vec.size(), 0);
}
