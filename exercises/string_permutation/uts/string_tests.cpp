#include "gtest/gtest.h"

#include "../include/string_permutation.hpp"


TEST(string_tests, notPermutationRepeatingChar)
{
    std::string input{"aaabbbcccddd"};
    std::string permutation{"abcddddddddd"};

    EXPECT_FALSE(isPermutation(input, permutation));
}

TEST(string_tests, notPermutationDifferentChar)
{
    std::string input{"abcde"};
    std::string permutation{"efghj"};

    EXPECT_FALSE(isPermutation(input, permutation));
}

TEST(string_tests, permutationWithRepeatingCharacters)
{
    std::string input{"ccccabbdd"};
    std::string permutation{"ddbccccba"};

    EXPECT_TRUE(isPermutation(input, permutation));
}

TEST(string_tests, notPermuttion)
{
    std::string input{"abc"};
    std::string permutation{"edcba"};

    EXPECT_FALSE(isPermutation(input, permutation));
}

TEST(string_tests, simplePermutation)
{
    std::string input{"abcde"};
    std::string permutation{"edcba"};

    EXPECT_TRUE(isPermutation(input, permutation));
}