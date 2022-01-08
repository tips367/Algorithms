/* Given an integer x, write a function that multiplies x with 3.5 and returns the integer result. You are not allowed to use %, /, *. 

Examples :
Input: 2
Output: 7

Input: 5
Output: 17 (Ignore the digits after decimal point)
*/

#include <iostream>

// Method 1
/*
int multiplyWith3Point5(int x)
{
    return (x << 1) + x + (x >> 1);
} */

// Method 2
int multiplyWith3Point5(int x)
{
    return ((x << 3) - x) >> 1;
}

int main()
{
    int x = 4;
    std::cout << multiplyWith3Point5(x);
    return 0;
}

