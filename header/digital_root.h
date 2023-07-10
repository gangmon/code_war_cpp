#pragma once


int digital_root(int n);

int digital_root(int n)
{
    if (n < 10)
        return n;

    int res = 0;
    while(n >= 10) {
        auto reminder = n % 10;
        res += reminder;
        n = n / 10;
    }
    return digital_root(res+n);
}