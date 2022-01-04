/* Write a program to find the smallest of three integers, without using any of the comparison operators. */

#include <iostream>
#define CHAR_BIT 8

// Method 1: Using repeated subtraction
/*
int smallest(int x, int y, int z)
{
    int c = 0;
    while (x && y && z) 
    {
        x--;
        y--;
        z--;
        c++;
    }
    return c;
} */

// Method 2: Using bit operations
int min(int x, int y)
{
    return y + ((x - y) & ((x - y) >> (sizeof(int) * CHAR_BIT - 1)));
}

int smallest(int x, int y, int z)
{
    return min(x, min(y, z));
}

int main()
{
    int x = 12, y = 15, z = 5;
    std::cout << "Minimum of 3 numbers is " << smallest(x, y, z);
    return 0;
}

