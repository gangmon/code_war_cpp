// Convert string to camel case
// https://www.codewars.com/kata/517abf86da9663f1d2000003/train/cpp
//

#pragma once


#include <string>

std::string to_camel_case(std::string text) {
    std::string res;

    for (size_t i = 0; i < text.size(); i ++)
    {
        std::string s;
        if (text[i] == '_')
        {
            i ++;
            if (text[i] >= 'a') {
                s.push_back(text[i] - 32);
            } else {
                s.push_back(text[i]);
            }
        }
        else if (text[i] == '-')
        {
            i ++;
            if (text[i] >= 'a') {
                s.push_back(text[i] - 32);
            } else {
                s.push_back(text[i]);
            }
        }
        else
        {
            s.push_back(text[i]);
        }
        res = res + s;

    }
    return res;
}