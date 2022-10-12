#pragma once

#include "../include/World.hpp"
#include "../include/Snake.hpp"

#include <memory>

class Game
{
public:
    Game(int lenght, int heigth);

    void printWorld() const;
    void placeSnake();
    void placeFood(Field field);
    void placeWall(Field field);
    void nextStep();
    void moveSnake();
    void play();

private:
    void drawWall() ; 

private:

const int m_lenght{};
const int m_heigth{};

std::unique_ptr<Snake> m_snake = nullptr;
std::unique_ptr<World> m_world = nullptr;
};