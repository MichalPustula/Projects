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

void Game::growSnake()
{
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

    if (m_world->getFieldState(m_snake->calculateNextSegment()) == FieldState::Snake)
    {
        cutTail(m_snake->calculateNextSegment());
        return;
    }

    if (m_world->getFieldState(m_snake->calculateNextSegment()) == FieldState::Food)
    {
        growSnake();
        placeNewFood();
        return;
    }

    moveSnake();
}

void Game::placeNewFood()
{
    int bx = m_snake->back().x;
    int by = m_snake->back().y;

    for (int i = -4; i < 4; i++)
    {
        if (tryPlaceRandomFood(bx+i, by-i) == true)
        {
            return;
        }
    }

    for (int i = 0; i < m_lenght; i++)
    {
        for (int j = 0; j < m_heigth; j++)
        {
            if (m_world->getFieldState(Field(i, j)) == FieldState::Empty)
            {
                placeFood(Field(i, j));
                return;
            }
        }
    }
}


bool Game::tryPlaceRandomFood(int x, int y)
{
    if (x >= 1 && y >= 1 && x < m_lenght - 1 && y < m_heigth - 1)
    {
        if (m_world->getFieldState(Field(x, y)) == FieldState::Empty)
        {
            placeFood(Field(x,y));
            return true;
        }
    }

    return false;
}

void Game::cutTail(Field field)
{
    while(true)
    {
        if(m_snake->back() == field)
        {
            moveSnake();
            return;
        }
        else 
        {
            m_world->setFieldState(m_snake->back(), FieldState::Empty);
            m_snake->removeTail();
        }
    }
}

void Game::play()
{
    std::cout << std::endl;
    std::cout << "temp interface: w,a,s,d to control, enter to iterate, q to quit " << std::endl;
    placeFood(Field(m_lenght/2, m_heigth/2));
    while(m_gameState == GameState::Running)
    {
        printWorld();
        getUserInput();
        nextStep();
        clearConsole();
    }
}

void Game::getUserInput()
{
    std::string userInput = "";
    std::getline(std::cin, userInput);
    if (userInput.length() == 0) { return; }
    if (userInput == "q") { m_gameState = GameState::Defeat; return; }

    if (userInput == "w") { m_snake->setDirection(Direction::Up); return; }
    if (userInput == "a") { m_snake->setDirection(Direction::Left); return; }
    if (userInput == "s") { m_snake->setDirection(Direction::Down); return; }
    if (userInput == "d") { m_snake->setDirection(Direction::Right); return; }

    return;
}

void Game::clearConsole()
{
    system("clear");
}



