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
    void clearConsole();
    void cutTail(Field field);

private:
    void drawWall() ; 
    void getUserInput();
    bool tryPlaceRandomFood(int x, int y);

private:

const int m_lenght{};
const int m_heigth{};

std::unique_ptr<Snake> m_snake = nullptr;
std::unique_ptr<World> m_world = nullptr;
GameState m_gameState{};
};