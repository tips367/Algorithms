/* Write a program to add one to a given number.The use of operators like ‘ + ’, ‘ - ‘, ‘* ’, ‘ / ’, ‘++’, ‘–‘ …etc are not allowed.
Examples:


Input:  12
Output : 13

Input : 6
Output : 7
*/

#include <iostream>

// Method 1. Time complexity: O(log n)
/*
int addOne(int x)
{
    int m = 1;

    // Flip all the set bits until we find a 0
    while (x & m)
    {
        x = x ^ m;
        m <<= 1;
    }

    // flip the rightmost 0 bit
    x = x ^ m;
    return x;
} */

// Method 2: Time complexity: O(1)
int addOne(int x)
{
    return (-(~x));
}

int main()
{
    std::cout << addOne(15);
    return 0;
}

