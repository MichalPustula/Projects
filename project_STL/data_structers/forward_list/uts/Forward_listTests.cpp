#include "gtest/gtest.h"

#include "../include/Forward_list.hpp"



TEST(Forward_listTests, ReverseMethod)
{
    Forward_list list;
    list.push_front(10);
    list.push_front(20);
    list.push_front(30);

    EXPECT_EQ(list.front(), 30);
    list.reverse();
    EXPECT_EQ(list.front(), 10);

}

TEST(Forward_listTests, PopFrontOnOneElementList)
{
    Forward_list list;
    list.push_front(10);
    list.pop_front();
    list.push_front(20);
    EXPECT_EQ(list.front(), 20);
}


TEST(Forward_listTests, PushFrontPopFront)
{
    Forward_list list;
    list.push_front(10);
    list.push_front(20);
    EXPECT_EQ(list.front(), 20);
    list.pop_front();
    EXPECT_EQ(list.front(), 10);
}

TEST(Forward_listTests, BeginFunction)
{
    Forward_list list;
    list.push_front(1);
    list.push_front(2);
    int temp = list.begin()->getData();
    EXPECT_EQ(temp, 2);
}


TEST(ListTests, CreatingListAdingOneElement)
{
    Forward_list list;
    list.push_front(5);
    EXPECT_EQ(list.front(), 5);
}

TEST(ListTests, CreatingEmptyList)
{
    Forward_list list;
    list.print();
}

