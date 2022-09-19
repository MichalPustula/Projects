#include "gtest/gtest.h"
#include "../include/Solution.hpp"

TEST(adapter_tests, processingAndCuttingMultiElementVector)
{
    std::vector<int> original = {7,6,5,4,3,2};
    std::vector<int> temp1 = {7,6,5};
    std::vector<int> temp2 = {4,3,2};

    std::vector<std::vector<int>> output_vec;
    output_vec.push_back(temp1);
    output_vec.push_back(temp2);

    Solution solution;
    EXPECT_EQ(solution.construct2DArray(original, 2, 3), output_vec);
};


TEST(adapter_tests, processingMultiElementVector)
{
    std::vector<int> original = {7,6,5,4,3,2};
    std::vector<int> temp1 = {7,6};
    std::vector<int> temp2 = {5,4};
    std::vector<int> temp3 = {3,2};

    std::vector<std::vector<int>> output_vec;
    output_vec.push_back(temp1);
    output_vec.push_back(temp2);
    output_vec.push_back(temp3);

    Solution solution;
    EXPECT_EQ(solution.construct2DArray(original, 3, 2), output_vec);
};

TEST(adapter_tests, processingSingleElementVectorToSingleElementVectorOfVectors)
{
    std::vector<int> original = {3};
    std::vector<int> temp = {3};
    std::vector<std::vector<int>> output_vec;
    output_vec.push_back(temp);
    
    Solution solution;
    EXPECT_EQ(solution.construct2DArray(original, 1, 1), output_vec);
};
    
TEST(adapter_tests, processingSingleElementVector)
{
    std::vector<int> original = {3};
    std::vector<int> temp = {3};
    std::vector<std::vector<int>> output_vec;
    output_vec.push_back(temp);
    
    Solution solution;
    EXPECT_EQ(solution.construct2DArray(original, 1, 1), output_vec);
};


TEST(adapter_tests, processingEmptyVector)
{
    std::vector<int> input_vec;
    std::vector<std::vector<int>> output_vec;

    Solution solution;
    EXPECT_EQ(solution.construct2DArray(input_vec, 0, 0), output_vec);
};