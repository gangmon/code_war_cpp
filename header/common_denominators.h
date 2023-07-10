//
// Created by kemi on 2023/6/17.
//https://www.codewars.com/kata/54d7660d2daf68c619000d95/train/cpp
#pragma once
#include <iostream>
#include <vector>

using namespace std;
class Fracts
{

public:
    static std::string convertFrac(std::vector<std::vector<unsigned long long>> &lst);
};

unsigned long long find_num(unsigned long long num1, unsigned long long num2);
unsigned long long gcd(unsigned long long num1, unsigned long long num2);

std::string Fracts::convertFrac(std::vector<std::vector<unsigned long long>> &lst)
{

    unsigned long long num = 0;
    for (auto &item : lst) {
        for (auto &i: item) {
            cout << i << ",";
        }
        auto a = item.rbegin();
        if (num == 0) {
            num = *a;
        } else {
//            cout << "a:" << *a << endl;
            num = find_num(num, *a);
        }
    }

    std::string res;

    for (auto &item :lst) {
        res.push_back('(');

        auto fact = num / *item.rbegin() * *item.begin();
        res = res + to_string(fact) + "," + to_string(num);

        res.push_back(')');
    }

    cout << "num:" << num << endl;
    cout << res << endl;
    return res;
}

unsigned long long find_num(unsigned long long num1, unsigned long long num2)
{
    auto f = gcd(num1, num2);

    return num1 * num2 / f;
}



unsigned long long gcd(unsigned long long num1, unsigned long long num2)
{
    unsigned long long c;
    for (;num2 != 0;) {
        c = num1;
        num1 = num2;
        num2 = c % num2;
    }
    return num1;
}

