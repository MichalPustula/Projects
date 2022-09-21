#pragma once

#include <iostream>
#include <string>

void fizzBuzz()
{
    int var3 = 0;
    int var5 = 0;
    std::string temp {""};
    std::string fizzbuzz{""};

    for (int i = 1; i < 31; i ++)
    {
        var3++;
        var5++;

        temp = std::to_string(i);

        if (var3 == 3)
        {
            fizzbuzz = fizzbuzz + "Fizz";
            var3 = 0;
            temp = "";
        }

        if (var5 == 5)
        {
            fizzbuzz = fizzbuzz + "Buzz";
            var5 = 0;
            temp = "";
        }

        std::cout << temp << fizzbuzz << std::endl;
        fizzbuzz = {""};
    }
}


