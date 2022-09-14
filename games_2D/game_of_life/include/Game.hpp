#pragma once

#include "../include/Grid.hpp"

#include <memory>
#include <string>

class Game
{
public:
    Game(int length, int height);

    void play();
    void placeGlider(int x, int y);

private:

std::unique_ptr<Grid> m_grid = nullptr;
};