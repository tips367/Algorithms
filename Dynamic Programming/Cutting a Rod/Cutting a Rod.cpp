/* Given a rod of length n inches and an array of prices that contains prices of all pieces of size smaller than n.
Determine the maximum value obtainable by cutting up the rod and selling the pieces.

Example :

If length of the rod is 8 and the values of different pieces are given as following :

length   | 1   2   3   4   5   6   7   8
--------------------------------------------
price    | 1   5   8   9  10  17  17  20

The maximum obtainable value is 22 (by cutting in two pieces of lengths 2 and 6)

And if the prices are as following:

length   | 1   2   3   4   5   6   7   8
--------------------------------------------
price    | 3   5   8   9  10  17  17  20

Then the maximum obtainable value is 24 (by cutting in eight pieces of length 1)
*/

#include <iostream>
#include <algorithm>

// Method 1: Recursion....Time complexity : Exponential O(n^n)
/*
int cutRod(int price[], int lengthOfRod)
{
    if (lengthOfRod <= 0)
        return 0;
    int maxValue = INT_MIN;
    for (int i = 0; i < lengthOfRod; i++)
    {
        maxValue = std::max(maxValue, price[i]+cutRod(price, lengthOfRod-i-1));
    }
    return maxValue;
} */

// Method 2. Dynamic programming....Time complexity : O(n^2)  Space : O(n)
int cutRod(int price[], int lengthOfRod)
{
    int* dp = new int[lengthOfRod + 1];
    dp[0] = 0;
    for (int i = 1; i <= lengthOfRod; ++i)
    {
        int maxValue = INT_MIN;
        for (int j = 0; j < i; ++j)
        {
            // divide the rod of length i into two rods of length j and i-j each and take maximum
            maxValue = std::max(maxValue, price[j] + dp[i-j-1]);
        }
        dp[i] = maxValue;
    }
    return dp[lengthOfRod];
}

/* Driver program to test above function */
int main()
{
    int arr[] = { 1, 5, 8, 9, 10, 17, 17, 20 };
    int size = sizeof(arr) / sizeof(arr[0]);
    std::cout << "Maximum Obtainable Value is " << cutRod(arr, size);
    return 0;
}