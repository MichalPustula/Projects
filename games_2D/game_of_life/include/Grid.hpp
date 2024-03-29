#pragma once

#include <vector>
#include <iostream>

class Grid
{
public:
    Grid(int x, int y);
    void setCell(int x, int y);

    bool getCell(int x, int y) const;

    void printGrid() const;
    void clearGrid();

    int countNeighboursOfCell(bool state, int x, int y) const;
    int countNeighboursOfCell(bool state, int index) const;

    void nextGeneration();

    void setCellU(int x, int y);
    void setCellUR(int x, int y);
    void setCellR(int x, int y);
    void setCellDR(int x, int y);
    void setCellD(int x, int y);
    void setCellDL(int x, int y);
    void setCellL(int x, int y);
    void setCellUL(int x, int y);
    // functions that were helpfull for testing and creating logic of countNeighbours...()

private:
    const int m_length{};
    const int m_height{};
    std::vector<bool> m_cells{};
};