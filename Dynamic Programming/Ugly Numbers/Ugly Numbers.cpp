/* Ugly numbers are numbers whose only prime factors are 2, 3 or 5. 
The sequence 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, … shows the first 11 ugly numbers. By convention, 1 is included. 
Given a number n, the task is to find n’th Ugly number.

Examples:  

Input  : n = 7
Output : 8

Input  : n = 10
Output : 12

Input  : n = 15
Output : 24
*/

#include <iostream>
#include <algorithm>

// Method 1: Brute force.....Time complexity : O(nlogn), Space: O(1)
/*
int maxDivide(int x, int y)
{
    while (x % y == 0)
        x /= y;
    return x;
}

bool isUglyNumber(int num)
{
    num = maxDivide(num, 2);
    num = maxDivide(num, 3);
    num = maxDivide(num, 5);

    return (num == 1) ? true : false;
}

int getNthUglyNumber(int n)
{
    int i = 1;
    int count = 1;  // ugly no. count

    while (count < n)
    {
        i++;
        if (isUglyNumber(i))
            count++;
    }
    return i;
} */

// Method 2: Dynamic programming.....Time complexity : O(n), Space: O(n)
int getNthUglyNumber(int n)
{
    int i2 = 0, i3 = 0, i5 = 0;
    int nextMultipleOf2 = 2;
    int nextMultipleOf3 = 3;
    int nextMultipleOf5 = 5;

    int* ugly = new int[n];
    ugly[0] = 1;
    int nextUglyNumber = 1;

    for (int i = 1; i < n; i++)
    {
        nextUglyNumber = std::min(std::min(nextMultipleOf2, nextMultipleOf3), nextMultipleOf5);
        ugly[i] = nextUglyNumber;
        if (nextUglyNumber == nextMultipleOf2)
        {
            i2 = i2 + 1;
            nextMultipleOf2 = ugly[i2] * 2;
        }
        if (nextUglyNumber == nextMultipleOf3) 
        {
            i3 = i3 + 1;
            nextMultipleOf3 = ugly[i3] * 3;
        }
        if (nextUglyNumber == nextMultipleOf5) 
        {
            i5 = i5 + 1;
            nextMultipleOf5 = ugly[i5] * 5;
        }
    }
    return ugly[n-1];
}

int main()
{
    int  num = getNthUglyNumber(150);
    std::cout << "150th ugly no. is " << num;
    return 0;
}


