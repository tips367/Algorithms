/* Given a value V, if we want to make change for V cents, and we have infinite supply of each of 
C = { C1, C2, .. , Cm} valued coins, what is the minimum number of coins to make the change? 
If it’s not possible to make change, print -1.

Input: coins[] = {25, 10, 5}, V = 30
Output: Minimum 2 coins required
We can use one coin of 25 cents and one of 5 cents

Input: coins[] = {9, 6, 5, 1}, V = 11
Output: Minimum 2 coins required
We can use one coin of 6 cents and 1 coin of 5 cents
*/

#include <iostream>
#include <vector>

// Method 1: Recursive...Time complexity: Exponential
/*
int minCoins(std::vector<int>& coins, int value)
{
    if (value == 0) 
    {
        return 0;
    }

    int result = INT_MAX;

    // Try every coin that has smaller value than value
    for (int i = 0; i < coins.size(); i++)
    {
        if (coins[i] <= value)
        {
            int temp = minCoins(coins, value - coins[i]);
            if(temp != INT_MAX)
                result = std::min(result, 1 + temp);
        }
    }
    return result;
} */

// Method 2: Using Dynamic programming...Time complexity: O(n*value)
int minCoins(std::vector<int>& coins, int value)
{
    int* dp = new int[value + 1];
    int n = coins.size();

    dp[0] = 0;

    for (int i = 1; i <= value; i++)
    {
        dp[i] = INT_MAX;

        // Go through all coins smaller than i
        for (int j = 0; j < n; j++)
        {
            if (coins[j] <= i)
            {
                int temp = dp[i - coins[j]];
                if(temp != INT_MAX)
                    dp[i] = std::min(dp[i], 1 + temp);
            }
        }
    }

    if (dp[value] == INT_MAX)
        return -1;

    return dp[value];
}

int main()
{
    std::vector<int> coins  = { 9, 6, 5, 1 };
    int value = 11;
    std::cout << "Minimum coins required is " << minCoins(coins, value);
    return 0;
}


