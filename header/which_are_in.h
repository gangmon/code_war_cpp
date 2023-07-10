//
// Created by kemi on 2023/7/9.
//
// https://www.codewars.com/kata/550554fd08b86f84fe000a58/train/cpp
# pragma once

#include <iostream>
#include <vector>

class WhichAreIn
{

public:
    static std::vector<std::string> inArray(std::vector<std::string> &array1, std::vector<std::string> &array2);

};

std::vector<std::string> WhichAreIn::inArray(std::vector<std::string> &array1, std::vector<std::string> &array2)
{

    for (const auto  &s : array1)
    {
        for (const auto  &s2: array2)
        {
            for (const auto  &sink :s)
            {
                bool flag = false;
                for (const auto  &sink2 : s2)
                {
                    if (sink == sink2){
                        flag = true;
                        break;
                    } else {
                        flag = false;
                    }
                }
                if (!flag)
                {

                }
            }
        }
    }

    std::cout << std::endl;
    return array1;
}

