/* Given a cost matrix cost[][] and a position (m, n) in cost[][], write a function that returns cost of minimum cost path 
to reach (m, n) from (0, 0). Each cell of the matrix represents a cost to traverse through that cell. Total cost of a path to 
reach (m, n) is sum of all the costs on that path (including both source and destination). You can only traverse down, right 
and diagonally lower cells from a given cell.

Example :

Input:   1	2	3
		 4	8	2
		 1	5	3

Find min cost path to (2,2)

Output: The min cost path is (0, 0) –> (0, 1) –> (1, 2) –> (2, 2). The cost of the path is 8 (1 + 2 + 2 + 3).
*/

#include <iostream>
#include <algorithm>
#include <vector>

// Method 1: Recursion....Time complexity : Exponential
/*
int minCost(std::vector<std::vector<int>> const& cost, int m, int n)
{
    if (m < 0 || n < 0)
        return INT_MAX;
    else if (m == 0 && n == 0)
        return cost[m][n];
    else
        return cost[m][n] + std::min(std::min(minCost(cost, m - 1, n - 1), minCost(cost, m - 1, n)), minCost(cost,m, n - 1));
} */

// Method 2. Dyanmic programming....Time complexity : O(mn)  Space : 0(mn)
/*
int minCost(std::vector<std::vector<int>> const& cost, int m, int n)
{
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1)); // similar to dp[m+1][n+1];
    dp[0][0] = cost[0][0];

    // Initialize first column of dp array
    for (int i = 1; i <= m; i++)
    {
        dp[i][0] = dp[i - 1][0] + cost[i][0];
    }
    // Initialize first row of dp array 
    for (int j = 1; j <= n; j++)
    {
        dp[0][j] = dp[0][j-1] + cost[0][j];
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = cost[i][j] + std::min(std::min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
        }
    }
    return dp[m][n];
} */

// Method 3: Space optimized...Time complexity : O(mn)  Space : 0(1)
int minCost(std::vector<std::vector<int>>& cost, int m, int n)
{
    // for 1st column 
    for (int i = 1; i <=m ; i++) 
    {
        cost[i][0] += cost[i - 1][0];
    }

    // for 1st row 
    for (int j = 1; j <= n; j++) 
    {
        cost[0][j] += cost[0][j - 1];
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cost[i][j] = cost[i][j] + std::min(std::min(cost[i - 1][j], cost[i][j - 1]), cost[i - 1][j - 1]);
        }
    }
    return cost[m][n];
}

/* Driver program to test above functions */
int main()
{
    std::vector<std::vector<int>> cost = { {1, 2, 3},
                                           {4, 8, 2},
                                           {1, 5, 3}};
    printf("%d ", minCost(cost, 2, 2));
    return 0;
}