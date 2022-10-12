#pragma once

#include "../include/World.hpp"
#include "../include/Snake.hpp"

#include <memory>
#include <string>

enum class GameState{Running, Stopped, Defeat, Victory};

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
    void growSnake();
    void placeNewFood();
    void play();

private:
    void drawWall() ; 
    void getUserInput();
    bool tryPlaceRandomFood(int bx, int by, int arg1 , int arg2 );

private:

const int m_lenght{};
const int m_heigth{};

std::unique_ptr<Snake> m_snake = nullptr;
std::unique_ptr<World> m_world = nullptr;
GameState m_gameState{};
};