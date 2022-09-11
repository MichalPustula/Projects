#pragma once

#include <vector>
#include <iostream>

class Grid
{
public:
    Grid(int x, int y);
    void setCell(int x, int y);
    bool getCell(int x, int y);

    void printGrid();


private:





private:
    int length{};
    int height{};
    std::vector<bool> cells{};
};