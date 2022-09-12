#include "../include/Grid.hpp"


Grid::Grid(int x, int y): m_Length(x), m_Height(y)
{
    m_Cells.resize(m_Length*m_Height);
}

void Grid::setCell(int x, int y) { m_Cells.at((x-1) + (m_Length*(y-1))).flip(); }

bool Grid::getCell(int x, int y) const
{ 
    return m_Cells.at((x-1) + (m_Length*(y-1))); 
}

void Grid::printGrid() const
{
    for (int y = 1; y <= m_Height; y++)
    {
        for (int x = 1; x <= m_Length; x++)
        {
            if(getCell(x, y) == true) { std::cout << " o "; }
            else                      { std::cout << " . "; }
        }
        std::cout << std::endl;
    }
}

void Grid::clearGrid()
{
    for (auto it : m_Cells)
    {
        if (it == true) { it.flip(); }
    }
}



int Grid::countNeighboursOfCell(bool state, int x, int y) const
{
    int count = 0;

    if(m_Cells.at((x - 1) + (m_Length*((y + m_Height - 2) % m_Height))) == state) { count++; }
    if(m_Cells.at((x - 1) + (m_Length*((y + m_Height) % m_Height))) == state) { count++; }
    if(m_Cells.at(((x + m_Length)% m_Length) + (m_Length*(y-1))) == state)   { count++; }
    if(m_Cells.at(((x + m_Length - 2)% m_Length) + (m_Length*(y-1))) == state) { count++; }
    
    if(m_Cells.at(((x + m_Length)% m_Length) + 
    (m_Length*((y + m_Height - 2) % m_Height))) == state) { count++; }

    if(m_Cells.at(((x + m_Length - 2)% m_Length) + 
    (m_Length*((y + m_Height - 2) % m_Height))) == state) { count++; }

    if(m_Cells.at(((x + m_Length)% m_Length) + 
    (m_Length*((y + m_Height) % m_Height)))  == state)    { count++; }
    
    if(m_Cells.at(((x + m_Length - 2)% m_Length) + 
    (m_Length*((y + m_Height) % m_Height))) == state)     { count++; }

    return count;
}


void Grid::setCellU(int x, int y)
{
    m_Cells.at((x - 1) + 
    (m_Length*((y + m_Height - 2) % m_Height))).flip();
}

void Grid::setCellD(int x, int y)
{
    m_Cells.at((x - 1) + 
    (m_Length*((y + m_Height) % m_Height))).flip();  
}

void Grid::setCellR(int x, int y)
{
    m_Cells.at(((x + m_Length)% m_Length) + 
    (m_Length*(y-1))).flip(); 
}

void Grid::setCellL(int x, int y)
{
    m_Cells.at(((x + m_Length - 2)% m_Length) + 
    (m_Length*(y-1))).flip(); 
}

void Grid::setCellUR(int x, int y)
{
    m_Cells.at(((x + m_Length)% m_Length) +
    (m_Length*((y + m_Height - 2) % m_Height))).flip(); 
}

void Grid::setCellUL(int x, int y)
{
    m_Cells.at(((x + m_Length - 2)% m_Length) + 
    (m_Length*((y + m_Height - 2) % m_Height))).flip(); 
}

void Grid::setCellDR(int x, int y)
{
    m_Cells.at(((x + m_Length)% m_Length) + 
    (m_Length*((y + m_Height) % m_Height))).flip(); 
}

void Grid::setCellDL(int x, int y)
{
    m_Cells.at(((x + m_Length - 2)% m_Length) + 
    (m_Length*((y + m_Height) % m_Height))).flip(); 
}




