/* Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. 
In other words, given two integer arrays val[0..n-1] and wt[0..n-1] which represent values and weights associated with n items respectively. 
Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights 
of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item or don’t pick it (0-1 property).

Example :

Input: 
val[] = { 60, 100, 120 }
wt[]  = { 10, 20, 30 }
W = 50

Output: 220

Weight = 10; Value = 60;
Weight = 20; Value = 100;
Weight = 30; Value = 120;
Weight = (20+10); Value = (100+60);
Weight = (30+10); Value = (120+60);
Weight = (20+30); Value = (100+120);
Weight = (10+20+30) > 50
*/

#include <iostream>
#include <algorithm>
#include <vector>

// Method 1: Recursion....Time complexity : Exponential (2^n)
/*
int knapSack(int W, int wt[], int val[], int n)
{
    // base case : negative capacity
    if (W < 0)
        return INT_MIN;
    // base case : no items left or capacity becomes 0
    if (n <= 0 || W == 0)
        return 0;
    // If weight of the nth item is more than Knapsack capacity W, then this item cannot be included 
    // in the optimal solution 
    if (W < wt[n - 1])
        return knapSack(W, wt, val, n - 1);
    // Return the maximum of two cases: 
    // (1) nth item included 
    // (2) not included 
	else
        return std::max(knapSack(W - wt[n - 1], wt, val, n - 1) + val[n - 1], knapSack(W, wt, val, n - 1));
} */

// Method 2. Dynamic programming....Time complexity : O(n*W)  Space : O(n*W)
int knapSack(int W, int wt[], int val[], int n)
{
    std::vector<std::vector<int>> K(n+1, std::vector<int>(W+1)); // similar to K[n+1][W+1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
                K[i][j] = 0;
            // If weight of the nth item is more than Knapsack capacity W, then this item cannot be included 
            // in the optimal solution 
            else if (j < wt[i - 1])
                K[i][j] = K[i - 1][j];
            // find max value by including or excluding the ith item
            else
                K[i][j] = std::max(val[i - 1] + K[i - 1][j - wt[i - 1]], K[i - 1][j]);
        }
    }
    return K[n][W];
}

// Driver code 
int main()
{
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    std::cout << knapSack(W, wt, val, n);
    return 0;
}