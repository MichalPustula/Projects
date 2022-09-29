#include "../include/Game.hpp"

Game::Game()
{
    m_snake = std::make_unique<Snake>();
    m_world = std::make_unique<World>(10,8);
}

void Game::placeSnake()
{
    for (auto it : m_snake->m_segments)
    {
        m_world->setFieldState(it, FieldState::Snake);
    }
}

void Game::placeFood()
{
    Field temp{6,6};
    m_world->setFieldState(temp, FieldState::Food);
}

void Game::printWorld() const
{
    m_world->printWorld();
}

void Game::moveSnake()
{
    m_world->setFieldState(m_snake->back(), FieldState::Empty);
    m_snake->removeTail();

    m_snake->addHead(m_snake->calculateNextSegment(Direction::Down));
    m_world->setFieldState(m_snake->front(), FieldState::Snake);
}

void Game::nextStep()
{


}

void Game::play()
{
    placeSnake();
    placeFood();
}

