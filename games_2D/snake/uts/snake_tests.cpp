#include "gtest/gtest.h"
#include "../include/World.hpp"
#include "../include/Snake.hpp"
#include "../include/Game.hpp"


TEST(SnakeTests, placingSnakeplacingFoodPrintingWorld)
{
    Game game(12,10);
    game.placeFood(Field(6,6));
    game.printWorld();
    std::cout << std::endl;
    game.moveSnake();
    game.printWorld();
    std::cout << std::endl;
    game.moveSnake();
    game.printWorld();
}


TEST(SnakeTests, testingSnakeDirections)
{
    Snake snake;
    EXPECT_EQ(snake.getDirection(), Direction::Right);

    snake.setDirection(Direction::Down);
    EXPECT_EQ(snake.getDirection(), Direction::Down);

    snake.setDirection(Direction::Left);
    EXPECT_EQ(snake.getDirection(), Direction::Left);

    snake.setDirection(Direction::Up);
    EXPECT_EQ(snake.getDirection(), Direction::Up);

    snake.setDirection(Direction::Down);
    EXPECT_EQ(snake.getDirection(), Direction::Up);
}

TEST(SnakeTests, testingSnakeDirectionDown)
{
    Snake snake;
    EXPECT_EQ(snake.getDirection(), Direction::Right);
    snake.setDirection(Direction::Down);
    EXPECT_EQ(snake.getDirection(), Direction::Down);
}


TEST(GridTests, printingSnakeWorld)
{
    World world(10,8);
    world.setFieldState({0,0}, FieldState::Food);
}

TEST(GridTests, creatingSnakeWorldSetingField)
{
    World world(10,8);
    EXPECT_EQ(world.getFieldState({0,0}), FieldState::Empty);
    world.setFieldState({0,0}, FieldState::Food);
    EXPECT_EQ(world.getFieldState({0,0}), FieldState::Food);
}
