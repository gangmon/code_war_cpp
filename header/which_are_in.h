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

std::vector<std::string> sort_arr(std::vector<std::string> &arr)
{
    for (size_t i = 0; i < arr.size(); i++)
    {
        for (size_t j = i; j < arr.size(); j++)
        {
            if (arr[i] > arr[j])
            {
                std::string temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return arr;
}

std::vector<std::string> WhichAreIn::inArray(std::vector<std::string> &array1, std::vector<std::string> &array2)
{
    std::vector<std::string> res{};

    for (const auto  &s : array1)
    {
        for (const auto  &s2: array2)
        {
            bool flag = false;
            int pos = 0;
            int start1 = 0;
            int start2 = 0;
            for (; start1 < s.length() && start2 < s2.length();)
            {
                if (s[start1] == s2[start2]){
                    flag = true;
                    start2 ++;
                    start1 ++;
                    pos ++;
                } else {
                    flag = false;
                    start2 ++;
                    pos = 0;
                }
            }

            if (flag && pos == s.length()){
                res.push_back(s);
                break;
            }
        }
    }


    sort_arr(res);
    return res;
}



