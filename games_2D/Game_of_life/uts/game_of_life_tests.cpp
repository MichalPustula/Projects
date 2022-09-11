#include "gtest/gtest.h"
#include "../include/Grid.hpp"

class GridTest : public ::testing::Test
{
    protected:
    GridTest() {};
    ~GridTest() override {};

    void SetUp() override {};
    void TearDown() override {};
};


TEST_F(GridTest, countingAliveNeighboursOfCell)
{

}


TEST(GridTests, creatingGridSetingCell)
{
    Grid grid(5,4);
    EXPECT_EQ(grid.getCell(2,1), false);
    grid.setCell(2,1);
    EXPECT_EQ(grid.getCell(2,1), true);
}
