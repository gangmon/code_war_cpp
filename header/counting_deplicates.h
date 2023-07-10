//
// Created by kemi on 2023/7/7.
//

# pragma once
#include <map>
#include <iostream>
#include <string>


size_t duplicateCount(const std::string& in);

size_t duplicateCount(const char* in)
{
    std::string out;
    while(*in)
    {
        out += std::toupper(*in);
        ++in;
    }
    std::map<char, int> m{};
    for (const char p: out)
    {
        std::cout << p ;
        m[p] ++;
    }
    std::cout << std::endl;
    size_t res = 0;
    for (const auto& pair:m)
    {
        if (pair.second > 1)
        {
            res ++ ;
        }
    }
    return res;

}
