/* Given two signed integers, write a function that returns true if the signs of given integers are different, otherwise false. 
For example, the function should return true -1 and +100, and should return false for -100 and -200. 
The function should not use any of the arithmetic operators. 
*/

#include <iostream>

// Method 1 : Using two comparison operators
/*
bool oppositeSigns(int x, int y)
{
    return (x < 0) ? (y >= 0) : (y < 0);
} */

/*
bool oppositeSigns(int x, int y)
{
    return ((x ^ y) < 0);
} */

bool oppositeSigns(int x, int y)
{
    return ((x ^ y) >> 31);
}

int main()
{
    int x = 100, y = -100;
    if (oppositeSigns(x, y))
        std::cout << "Signs are opposite";
    else
        std::cout << "Signs are not opposite";
    return 0;
}


