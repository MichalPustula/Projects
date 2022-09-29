#pragma once

#include "../include/World.hpp"
#include "../include/Snake.hpp"

#include <memory>


class Game
{
public:
    Game();

    void play();

private:

std::unique_ptr<Snake> m_snake = nullptr;
std::unique_ptr<World> m_world = nullptr;
};