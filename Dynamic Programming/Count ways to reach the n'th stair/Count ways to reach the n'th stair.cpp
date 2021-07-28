/* There are n stairs, a person standing at the bottom wants to reach the top. 
Count number of ways to reach n'th stair when a person can climb 1, 2, ..m stairs at a time.

Examples:

Input: n = 1, m = 2
Output: 1
There is only one way to climb 1 stair

Input: n = 4, m = 2
Output: 5
(1, 1, 1, 1), (1, 1, 2), (2, 1, 1), (1, 2, 1), (2, 2)
*/

#include <iostream>

// Method 1: Recursive...Time complexity : Exponential
/*
int totalWays(int n, int m)
{
    // base case: invalid input
    if (n < 0) 
    {
        return 0;
    }

    // base case: 1 way (with no steps)
    if (n == 0) 
    {
        return 1;
    }

    int count = 0;
    for (int i = 1; i <= m; i++) {
        count += totalWays(n - i, m);
    }

    return count;
} */

// Method 2: Using dynamic programming...Time complexity : O(m*n), Space : O(n)
/*
int totalWays(int n, int m)
{
    if (m <= 1)
        return m;

    int* dp = new int[n+1];

    // base case: 1 way (with no steps)
    dp[0] = 1;

    // 1 way to reach the 1st stair
    dp[1] = 1;

    // 2 ways to reach the 2nd stair
    dp[2] = 2;

    // fill the dp table in a bottom-up manner
    for (int i = 3; i <= n; i++)
    {
        dp[i] = 0;
        for (int j = 1; j <= m && (i - j) >= 0; j++) 
        {
            dp[i] += dp[i - j];
        }
    }

    return dp[n];
} */

// Method 3: Using dynamic programming and sliding window...Time complexity : O(n), Space : O(n)
int totalWays(int n, int m)
{
    int* dp = new int[n + 1];
    int temp = 0;
    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        int start = i - m - 1;
        int end = i - 1;
        if (start >= 0)
        {
            temp -= dp[start];
        }
        temp += dp[end];
        dp[i] = temp;
    }
    return dp[n];
}

int main()
{
    int n = 5, m = 3;

    std::cout << "Total ways to reach the "<< n << "'th stair with at most " << m << " steps are " << totalWays(n, m);

    return 0;
}


