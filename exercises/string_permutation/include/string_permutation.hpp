#pragma once

#include <string>
#include <iostream>

bool isPermutation(const std::string input_, const std::string permutation_)
{
    if (input_.size() != permutation_.size()) { return false; }

    std::string input(input_);
    std::string permutation(permutation_);
    
    for (size_t i = 0; i < input.size(); i++)
    {
        for (size_t j = 0; j < input.size(); j++)
        {
            if (input.at(i) == permutation.at(j))
            {
                permutation.at(j) = '^';
                break;
            }
        }
    }

    for(size_t k = 0; k < permutation.size(); k++)
    {
        if (permutation.at(k) != '^') {return false;}
    }

    return true;
}



