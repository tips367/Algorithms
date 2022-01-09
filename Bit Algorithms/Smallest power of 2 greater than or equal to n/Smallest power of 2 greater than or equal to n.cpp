/* Write a function that, for a given no n, finds a number p which is greater than or equal to n and is a smallest power of 2. 

Examples :
Input : n = 5
Output: 8

Input  : n = 17
Output : 32

Input  : n = 32
Output : 32
*/

#include <iostream>

// Method 1. Using log of the number
/*
unsigned int nextPowerOf2(unsigned int n)
{
    int pos = ceil(log2(n));
    return pow(2, pos);
} */

// Method 2.
/*
unsigned int nextPowerOf2(unsigned int n)
{
    unsigned count = 0;
    if (n && !(n & (n - 1)))
        return n;

    while (n != 0)
    {
        n >>= 1;
        count += 1;
    }

    return 1 << count;
} */

// Method 3.
/*
unsigned int nextPowerOf2(unsigned int n)
{
    unsigned int p = 1;
    if (n && !(n & (n - 1)))
        return n;

    while (p < n)
        p <<= 1;

    return p;
} */

// Method 4.
unsigned int nextPowerOf2(unsigned int n)
{
    n--;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    n++;
    return n;
}

int main()
{
    unsigned int n = 17;
    std::cout << nextPowerOf2(n);
    return 0;
}

