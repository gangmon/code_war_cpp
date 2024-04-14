//
// Created by kemi on 2024/4/13.
//

//https://www.codewars.com/kata/525c7c5ab6aecef16e0001a5/train/cpp


#pragma once
#include <string>

long parse_int(std::string number);

std::vector<std::string> splitStringBySpace(std::string str) {
    std::vector<std::string> res;
    std::string temp;
    for (auto &c : str) {
        if ((c == ' ') || (c == '-')) {
            res.push_back(temp);
            temp.clear();
        } else {
            temp.push_back(c);
        }
    }
    res.push_back(temp);
    return res;
}

long parse_int(std::string number) {
    auto nums = splitStringBySpace(number);
    long res = 0;
    long former = 0;
    for (auto &num : nums) {
        if (num == "zero") {
            res += 0;
        } else if (num == "one") {
            res += 1;
            former = 1;
        } else if (num == "two") {
            res += 2;
            former = 2;
        } else if (num == "three") {
            res += 3;
            former = 3;
        } else if (num == "four") {
            res += 4;
            former = 4;
        } else if (num == "five") {
            res += 5;
            former = 5;
        } else if (num == "six") {
            res += 6;
            former = 6;
        } else if (num == "seven") {
            res += 7;
            former = 7;
        } else if (num == "eight") {
            res += 8;
            former = 8;
        } else if (num == "nine") {
            res += 9;
            former = 9;
        } else if (num == "ten") {
            res += 10;
            former = 10;
        } else if (num == "eleven") {
            res += 11;
        } else if (num == "twelve") {
            res += 12;
        } else if (num == "thirteen") {
            res += 13;
        } else if (num == "fourteen") {
            res += 14;
        } else if (num == "fifteen") {
            res += 15;
        } else if (num == "sixteen") {
            res += 16;
        } else if (num == "seventeen") {
            res += 17;
        } else if (num == "eighteen") {
            res += 18;
        } else if (num == "nineteen") {
            res += 19;
        } else if (num == "twenty") {
            res += 20;
        } else if (num == "thirty") {
            res += 30;
        } else if (num == "forty") {
            res += 40;
        } else if (num == "fifty") {
            res += 50;
        } else if (num == "sixty") {
            res += 60;
        } else if (num == "seventy") {
            res += 70;
        } else if (num == "eighty") {
            res += 80;
        } else if (num == "ninety") {
            res += 90;
        } else if (num == "hundred") {
            res = res + former*100 - former;
        } else if (num == "thousand") {
            res *= 1000;
        } else if (num == "million") {
            res *= 1000000;
        }

    }
    return res;
}

