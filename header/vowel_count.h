//https://www.codewars.com/kata/54ff3102c1bad923760001f3/train/cpp
#pragma once

#include <string>

using namespace std;

int getCount(const string& inputStr){
    int num_vowels = 0;

    for (size_t i = 0; i < inputStr.size(); i ++) {
        if (inputStr[i] == 'a' || inputStr[i] == 'e' || inputStr[i] == 'i' || inputStr[i] == 'u' || inputStr[i] == 'o') {
            num_vowels ++;
        }
    }

    return num_vowels;
}