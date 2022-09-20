# pragma once

#include <stdint.h>

struct Result
{
    uint32_t steps{0};
    uint32_t max{1};
};


uint32_t calculate_next_even(uint32_t arg)
{
    return arg/2;
}

uint32_t calculate_next_odd(uint32_t arg)
{
    return (3*arg) + 1;
}

Result calculate(const uint32_t arg)
{
    uint32_t current_val = arg;
    Result result;

    for (uint32_t i = 0; i < 1000; i++)
    {
        if (current_val == 1) { return result;}

        result.steps++;
        if (current_val > result.max) {result.max = current_val;}

        if (current_val % 2 == 0)
        {
            current_val = calculate_next_even(current_val);
        }
        else
        {
            current_val = calculate_next_odd(current_val);
        }
    }
    return result;
}


