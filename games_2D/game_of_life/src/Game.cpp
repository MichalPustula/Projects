#include "../include/Game.hpp"


Game::Game(int length, int height)
{
    m_grid = std::make_unique<Grid>(length, height);
}

void Game::play()
{
    for (int i = 0; i < 400; i++)
    {
        std::cout << "to continue press enter, to stop type anything" << '\n';
        m_grid->printGrid();

        if (std::cin.get() != '\n') { return; }

        m_grid->nextGeneration();
    }
}

void Game::placeGlider(int x, int y)
{
    m_grid->setCell(x,y+2);
    m_grid->setCell(x+1,y+2);
    m_grid->setCell(x+1,y);
    m_grid->setCell(x+2,y+1);
    m_grid->setCell(x+2,y+2);
}

void Game::placeSpaceShip(int x, int y)
{
    m_grid->setCell(x, y+1);
    m_grid->setCell(x, y+2);
    m_grid->setCell(x+1, y);
    m_grid->setCell(x+1, y+1);
    m_grid->setCell(x+1, y+2);
    m_grid->setCell(x+2, y);
    m_grid->setCell(x+2, y+1);
    m_grid->setCell(x+2, y+3);
    m_grid->setCell(x+3, y+1);
    m_grid->setCell(x+3, y+2);
    m_grid->setCell(x+3, y+3);
    m_grid->setCell(x+4, y+2);
}


