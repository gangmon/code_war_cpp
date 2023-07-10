//
// Created by kemi on 2023/6/17.
//
// https://www.codewars.com/kata/550f22f4d758534c1100025a/train/cpp
#pragma once
#include <vector>
#include <iostream>
#include <map>

class DirReduction
{
public:

    static std::vector<std::string> dirReduc(std::vector<std::string> &arr);

};

std::vector<std::string>  DirReduction::dirReduc(std::vector<std::string> &arr)
{
    for (auto const &str: arr){
        std::cout << str << ",";
    }
    std::map<std::string, std::string> pair{{"NORTH", "SOUTH"},
                                            {"SOUTH", "NORTH"},
                                            {"EAST", "WEST"},
                                            {"WEST", "EAST"}};

    std::vector<int> pos(arr.size(), -1);
    std::vector<std::string> res;
    bool repeat = true;
    while(repeat){
        for (size_t i = 0; i < arr.size()-1 && arr.size() > 1;) {
            if (pair[arr[i]] == arr[i+1]){
                arr.erase(arr.begin()+i);
                arr.erase(arr.begin()+i);
            } else {
                i ++;
            }
        }
        if (arr.size() == 1)
            return arr;
        auto flag = true;
        for(size_t i = 0; i < arr.size() - 1 && arr.size() > 1; i++) {
            if (pair[arr[i]] == arr[i+1]){
                flag = false;
            }
        }
        if (flag) {
            repeat = false;
        }
    }
    return arr;
}