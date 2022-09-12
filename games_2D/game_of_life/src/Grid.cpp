#include "../include/Grid.hpp"


Grid::Grid(int x, int y): m_length(x), m_height(y)
{
    m_cells.resize(m_length*m_height);
}

void Grid::setCell(int x, int y) { m_cells.at((x-1) + (m_length*(y-1))).flip(); }

bool Grid::getCell(int x, int y) const
{ 
    return m_cells.at((x-1) + (m_length*(y-1))); 
}

void Grid::printGrid() const
{
    for (int y = 1; y <= m_height; y++)
    {
        for (int x = 1; x <= m_length; x++)
        {
            if(getCell(x, y) == true) { std::cout << " o "; }
            else                      { std::cout << " . "; }
        }
        std::cout << std::endl;
    }
}

void Grid::clearGrid()
{
    for (auto it : m_cells)
    {
        if (it == true) { it.flip(); }
    }
}

void Grid::nextGeneration()
{
    std::vector<bool> next_generation;

}



int Grid::countNeighboursOfCell(bool state, int x, int y) const
{
    int count = 0;

    if(m_cells.at((x - 1) + (m_length*((y + m_height - 2) % m_height))) == state) { count++; }
    if(m_cells.at((x - 1) + (m_length*((y + m_height) % m_height))) == state) { count++; }
    if(m_cells.at(((x + m_length)% m_length) + (m_length*(y-1))) == state)   { count++; }
    if(m_cells.at(((x + m_length - 2)% m_length) + (m_length*(y-1))) == state) { count++; }
    
    if(m_cells.at(((x + m_length)% m_length) + 
    (m_length*((y + m_height - 2) % m_height))) == state) { count++; }

    if(m_cells.at(((x + m_length - 2)% m_length) + 
    (m_length*((y + m_height - 2) % m_height))) == state) { count++; }

    if(m_cells.at(((x + m_length)% m_length) + 
    (m_length*((y + m_height) % m_height)))  == state)    { count++; }
    
    if(m_cells.at(((x + m_length - 2)% m_length) + 
    (m_length*((y + m_height) % m_height))) == state)     { count++; }

    return count;
}


void Grid::setCellU(int x, int y)
{
    m_cells.at((x - 1) + 
    (m_length*((y + m_height - 2) % m_height))).flip();
}

void Grid::setCellD(int x, int y)
{
    m_cells.at((x - 1) + 
    (m_length*((y + m_height) % m_height))).flip();  
}

void Grid::setCellR(int x, int y)
{
    m_cells.at(((x + m_length)% m_length) + 
    (m_length*(y-1))).flip(); 
}

void Grid::setCellL(int x, int y)
{
    m_cells.at(((x + m_length - 2)% m_length) + 
    (m_length*(y-1))).flip(); 
}

void Grid::setCellUR(int x, int y)
{
    m_cells.at(((x + m_length)% m_length) +
    (m_length*((y + m_height - 2) % m_height))).flip(); 
}

void Grid::setCellUL(int x, int y)
{
    m_cells.at(((x + m_length - 2)% m_length) + 
    (m_length*((y + m_height - 2) % m_height))).flip(); 
}

void Grid::setCellDR(int x, int y)
{
    m_cells.at(((x + m_length)% m_length) + 
    (m_length*((y + m_height) % m_height))).flip(); 
}

void Grid::setCellDL(int x, int y)
{
    m_cells.at(((x + m_length - 2)% m_length) + 
    (m_length*((y + m_height) % m_height))).flip(); 
}




