#include "../include/Grid.hpp"


Grid::Grid(int x, int y): length(x), height(y)
{
    cells.resize(length*height);
}

void Grid::setCell(int x, int y) { cells.at((x-1) + (length*(y-1))).flip(); }
bool Grid::getCell(int x, int y) { return cells.at((x-1) + (length*(y-1))); }

void Grid::printGrid()
{
    for (int y = height; y >= 1; y--)
    {
        for (int x = 1; x <= length; x++)
        {
            if(getCell(x, y) == true) { std::cout << " o "; }
            else                      { std::cout << " . "; }
        }
        std::cout << std::endl;
    }
}





