//
// Created by kemi on 2023/6/22.
//

#pragma once
#include <iostream>

using namespace std;

int affect_region()
{
    unsigned long long count = 0;
    for (int i = 0; i < 10; i ++)
    {
        count += i;
        cout << count << endl;
    }
    cout << "print out of circle:" << count << endl;
}


