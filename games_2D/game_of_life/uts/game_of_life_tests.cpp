#include "gtest/gtest.h"
#include "../include/Grid.hpp"


TEST(GridTests, setAllNeighboursInCorner)
{
    Grid grid(7,5);

    grid.setCellU(7,1);
    EXPECT_TRUE(grid.getCell(7,5));
    grid.setCellR(7,1);
    EXPECT_TRUE(grid.getCell(1,1));
    grid.setCellD(7,1);
    EXPECT_TRUE(grid.getCell(7,2));
    grid.setCellL(7,1);
    EXPECT_TRUE(grid.getCell(6,1));
    grid.setCellUR(7,1);
    EXPECT_TRUE(grid.getCell(1,5));
    grid.setCellDR(7,1);
    EXPECT_TRUE(grid.getCell(1,2));
    grid.setCellUL(7,1);
    EXPECT_TRUE(grid.getCell(6,5));
    grid.setCellDL(7,1);
    EXPECT_TRUE(grid.getCell(6,2));

    EXPECT_EQ(grid.countNeighboursOfCell(true, 7,1), 8);
    EXPECT_EQ(grid.countNeighboursOfCell(false, 7,1), 0);
    grid.printGrid();
}

TEST(GridTests, setAllNeighboursInMiddle)
{
    Grid grid(7,5);

    grid.setCellU(4,3);
    EXPECT_TRUE(grid.getCell(4,2));
    grid.setCellR(4,3);
    EXPECT_TRUE(grid.getCell(5,3));
    grid.setCellD(4,3);
    EXPECT_TRUE(grid.getCell(4,2));
    grid.setCellL(4,3);
    EXPECT_TRUE(grid.getCell(3,3));
    grid.setCellUR(4,3);
    EXPECT_TRUE(grid.getCell(5,2));
    grid.setCellDR(4,3);
    EXPECT_TRUE(grid.getCell(5,2));
    grid.setCellUL(4,3);
    EXPECT_TRUE(grid.getCell(3,2));
    grid.setCellDL(4,3);
    EXPECT_TRUE(grid.getCell(3,2));

    grid.printGrid();
}

TEST(GridTests, setNeighboursNearCorners)
{
    Grid grid(5,5);

    grid.setCell(1,1);
    EXPECT_TRUE(grid.getCell(1,1));
    grid.setCellUL(1,1);
    EXPECT_TRUE(grid.getCell(5,5));


    grid.setCell(5,1);
    EXPECT_TRUE(grid.getCell(5,1));
    grid.setCellUR(5,1);
    EXPECT_TRUE(grid.getCell(1,5));
    grid.printGrid();
}

TEST(GridTests, setNeighboursNearWalls)
{
    Grid grid(4,4);

    grid.setCell(2,1);
    grid.setCell(4,2);
    grid.setCell(3,4);
    grid.setCell(1,3);
    grid.printGrid();
    grid.clearGrid();

    grid.setCellU(2,1);
    EXPECT_TRUE(grid.getCell(2,4));
    grid.setCellR(4,2);
    EXPECT_TRUE(grid.getCell(1,2));
    grid.setCellD(3,4);
    EXPECT_TRUE(grid.getCell(2,4));
    grid.setCellL(1,3);
    EXPECT_TRUE(grid.getCell(4,3));
    grid.printGrid();
}

TEST(GridTests, setNeighboursLeftWall)
{
    Grid grid(5,5);
    grid.setCellL(1,1);
    grid.setCellL(1,2);
    grid.setCellL(1,3);
    grid.setCellL(1,4);
    grid.setCellL(1,5);
    grid.printGrid();
}

TEST(GridTests, countStateOfNeighbours)
{
    Grid grid(9,9);

    EXPECT_EQ(grid.countNeighboursOfCell(false, 5, 5), 8);

    grid.setCell(4,4);
    grid.setCell(4,5);
    grid.setCell(4,6);
    grid.setCell(5,4);
    grid.setCell(5,6);
    grid.setCell(6,4);
    grid.setCell(6,5);
    grid.setCell(6,6);

    EXPECT_EQ(grid.countNeighboursOfCell(true, 5, 5), 8);

    grid.printGrid();
}


TEST(GridTests, creatingGridSetingCell)
{
    Grid grid(5,4);
    EXPECT_FALSE(grid.getCell(2,1));
    grid.setCell(2,1);
    EXPECT_TRUE(grid.getCell(2,1));
}
