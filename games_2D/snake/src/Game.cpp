#include "../include/Game.hpp"

Game::Game()
{
    m_snake = std::make_unique<Snake>();
    m_world = std::make_unique<World>(10,8);
}