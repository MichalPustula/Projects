#include "../include/Game.hpp"

Game::Game(int lenght, int heigth) : 
m_lenght(lenght), 
m_heigth(heigth), 
m_gameState(GameState::Running)
{
    m_snake = std::make_unique<Snake>();
    m_world = std::make_unique<World>(lenght, heigth);

    drawWall();
    placeSnake();
}

void Game::placeSnake()
{
    for (auto it : m_snake->m_segments)
    {
        m_world->setFieldState(it, FieldState::Snake);
    }
}

void Game::placeWall(Field field)
{
    m_world->setFieldState(field, FieldState::Wall);
}

void Game::placeFood(Field field)
{
    m_world->setFieldState(field, FieldState::Food);
}

void Game::drawWall()
{
    for (int i = 0; i < m_lenght; i++)
    {
        placeWall(Field(i, 0));
        placeWall(Field(i, (m_heigth-1)));
    }

    for (int i = 0; i < m_heigth; i++)
    {
        placeWall(Field(0, i));
        placeWall(Field((m_lenght-1), i));
    }
}

void Game::printWorld() const
{
    m_world->printWorld();
}

void Game::moveSnake()
{
    m_world->setFieldState(m_snake->back(), FieldState::Empty);
    m_snake->removeTail();

    m_snake->addHead(m_snake->calculateNextSegment());
    m_world->setFieldState(m_snake->front(), FieldState::Snake);
}

void Game::nextStep()
{
    if (m_world->getFieldState(m_snake->calculateNextSegment()) == FieldState::Wall)
    {
        m_gameState = GameState::Defeat;
        return;
    }
    moveSnake();
}

void Game::play()
{
    printWorld();

    while(m_gameState == GameState::Running)
    {
        getUserInput();
        nextStep();
        printWorld();
    }
}

void Game::getUserInput()
{
    char userInput = std::cin.get();

    if (userInput == 'q') { m_gameState = GameState::Defeat; return; }

    if (userInput == 'w') { m_snake->setDirection(Direction::Up); return; }
    if (userInput == 'a') { m_snake->setDirection(Direction::Left); return; }
    if (userInput == 's') { m_snake->setDirection(Direction::Down); return; }
    if (userInput == 'd') { m_snake->setDirection(Direction::Right); return; }

    return;
}

