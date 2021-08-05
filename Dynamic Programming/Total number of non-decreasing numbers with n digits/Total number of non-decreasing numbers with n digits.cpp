/* A number is non-decreasing if every digit (except the first one) is greater than or equal to previous digit. 
For example, 223, 4455567, 899, are non-decreasing numbers.
So, given the number of digits n, you are required to find the count of total non-decreasing numbers with n digits.

Examples: 

Input:  n = 1
Output: count  = 10

Input:  n = 2
Output: count  = 55

Input:  n = 3
Output: count  = 220
*/

#include <iostream>
#include <vector>

long long int countNonDecreasing(int n)
{
    std::vector<std::vector<long long int>> dp(10, std::vector<long long int>(n+1));

    // Fill table for non decreasing numbers of length 1
    // Base cases 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
    for (int i = 0; i < 10; i++)
        dp[i][1] = 1;

    for (int digit = 0; digit <= 9; digit++)
    {
        for (int len = 2; len <= n; len++)
        {
            // sum of all numbers of length of len-1 in which last digit x is <= 'digit'
            for (int x = 0; x <= digit; x++)
                dp[digit][len] += dp[x][len - 1];
        }
    }

    long long int count = 0;

    // The total non-decreasing numbers of length n will be dp[0][n] +  dp[1][n] ..+ dp[9][n]
    for (int i = 0; i < 10; i++)
        count += dp[i][n];

    return count;
}

// Driver program
int main()
{
    int n = 3;
    std::cout << countNonDecreasing(n);
    return 0;
}