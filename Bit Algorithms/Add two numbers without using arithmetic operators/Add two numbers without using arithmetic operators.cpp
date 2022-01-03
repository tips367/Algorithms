/* Write a function Add() that returns sum of two integers. The function should not use any of the arithmetic operators (+, ++, –, -, .. etc).*/

#include <iostream>

int Add(int x, int y)
{
    // Iterate till there is no carry
    while (y != 0)
    {
        // carry should be unsigned to deal with -ve numbers
        // carry now contains common set bits of x and y
        unsigned carry = x & y;
        x = x ^ y;
        // Carry is shifted by one so that adding it to x gives the required sum
        y = carry << 1;
    }
    return x;
}

int main()
{
    std::cout << Add(15, 32);
    return 0;
}

