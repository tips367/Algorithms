/* Given two integers ‘n’ and ‘sum’, find count of all n digit numbers with sum of digits as ‘sum’. 
Leading 0’s are not counted as digits. 

1 <= n <= 100 and 
1 <= sum <= 500

Example: 

Input:  n = 2, sum = 2
Output: 2
Explanation: Numbers are 11 and 20

Input:  n = 2, sum = 5
Output: 5
Explanation: Numbers are 14, 23, 32, 41 and 50

Input:  n = 3, sum = 6
Output: 21

*/

#include <iostream>
#include <vector>

// Method 1: Recursive
/*
int countRecursive(int n, int sum)
{
    if (n == 0)
        return sum == 0;

    if (sum == 0)
        return 1;

    long int result = 0;
    for (int i = 0; i <= 9; i++)
    {
        if (sum - i >= 0)
            result += countRecursive(n - 1, sum - i);
    }
    return result;
}

int count(int n, int sum)
{
    long int result = 0;

    // Traverse through every digit from 1 to 9 and count numbers beginning with it
    for (int i = 1; i <= 9; i++)
    {
        if (sum - i >= 0)
            result += countRecursive(n - 1, sum - i);
    }
    return result;
} */

// Method 2: Using dynamic programming
int count(int n, int sum)
{
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(sum + 1));

    for (int i = 0; i <= n; i++) 
    {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= sum; i++)
    {
        dp[0][i] = 0;
    }

    for (int i = 1; i <= n; i++) 
    {
        for (int j = 1; j <= sum; j++) 
        {
            dp[i][j] = 0;
            for (int k = 0; k <= 9; k++) 
            {
                if (j - k >= 0) 
                {
                    dp[i][j] += dp[i - 1][j - k];
                }
            }
        }
    }

    // Excluding leading 0's
    return dp[n][sum] - dp[n - 1][sum];
}

int main()
{
    int n = 3, sum = 5;
    std::cout << count(n, sum);
    return 0;
}

