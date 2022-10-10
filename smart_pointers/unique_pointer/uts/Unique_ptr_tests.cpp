#include "gtest/gtest.h"

#include "../include/Unique_ptr.hpp"

#include <string>


TEST(UptrTests, DereferenceOperatorTest)
{
    std::string test = "testString";
    Unique_ptr<std::string> ptr(new std::string(test));

    EXPECT_EQ(ptr->size(), test.size());
    EXPECT_EQ(*ptr, test);
};
    
TEST(UptrTests, ArrowOperatorTest)
{
    std::string test = "testString";
    
    Unique_ptr<std::string> ptr(new std::string(test));
    
    EXPECT_EQ(ptr->size(), test.size());
    EXPECT_EQ(*ptr, test);
};

TEST(UptrTests, Unique_ptrMoveOperator)
{
    Unique_ptr<int> ptr(new int(10));
    Unique_ptr<int> ptr2(new int(20));

    ptr = std::move(ptr2);

    EXPECT_EQ(*(ptr.get()), 20);
};

TEST(UptrTests, UniquePtrMoveConstructorCheckValue)
{
    const int test = 10;

    Unique_ptr<int> ptr(new int(test));
    Unique_ptr<int> ptr2(std::move(ptr));

    EXPECT_EQ(*(ptr2.get()), test);
    EXPECT_EQ(ptr.get(), nullptr);
};

TEST(UptrTests, Unique_ptrMoveConstructor)
{
    Unique_ptr<int> ptr(new int(10));
    Unique_ptr<int> ptr2(std::move(ptr));
};

TEST(UptrTests, UniquePtGetFunction)
{
    Unique_ptr<int> ptr(new int(10));
    EXPECT_EQ(*ptr.get(), 10);
};

TEST(UptrTests, Unique_ptrIsConstructedWithArgument)
{
    Unique_ptr<int> ptr(new int(10));
};  

TEST(UptrTests, Unique_ptrIsConstructedWithDefaultConstructor)
{
    Unique_ptr<int> ptr;
};