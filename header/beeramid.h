//
// Created by kemi on 2024/5/7.
//https://www.codewars.com/kata/51e04f6b544cf3f6550000c1/train/cpp
//

#ifndef CODEWAR_BEERAMID_H
#define CODEWAR_BEERAMID_H

#endif //CODEWAR_BEERAMID_H

#include <iostream>
#include <cmath>

// Returns number of complete beeramid levels
int beeramid(int bonus, double price)
{

    int bottom = bonus/price;
//   std::cout << bonus << ","<< price << "," << bottom;
    int sum = 0;
    for (int i = 1; sum <= bottom; i ++)
    {
        if (sum + i*i > bottom) {
            return i-1;
        } else if (sum + i*i > bottom) {
            return i;
        }
        sum += i * i;
    }

    return -1;
}