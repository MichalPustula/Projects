#pragma once

#include <vector>
#include <iostream>

class Grid
{
public:
    Grid(int x, int y);
    void setCell(int x, int y);

    bool getCell(int x, int y) const;

    void printGrid()const;
    void clearGrid();

    int countNeighboursOfCell(bool state, int x, int y) const;

    void setCellU(int x, int y);
    void setCellUR(int x, int y);
    void setCellR(int x, int y);
    void setCellDR(int x, int y);
    void setCellD(int x, int y);
    void setCellDL(int x, int y);
    void setCellL(int x, int y);
    void setCellUL(int x, int y);


private:
    int m_Length{};
    int m_Height{};
    std::vector<bool> m_Cells{};
};