#include "gtest/gtest.h"
#include "../include/World.hpp"




TEST(GridTests, printingSnakeWorld)
{
    World world(10,8);
    world.setFieldState({0,0}, FieldState::Food);
    world.printWorld();
}

TEST(GridTests, creatingSnakeWorldSetingField)
{
    World world(10,8);
    EXPECT_EQ(world.getFieldState({0,0}), FieldState::Empty);
    world.setFieldState({0,0}, FieldState::Food);
    EXPECT_EQ(world.getFieldState({0,0}), FieldState::Food);
}
