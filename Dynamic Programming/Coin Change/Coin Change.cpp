/* Given a value N, if we want to make change for N cents, and we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins,
how many ways can we make the change? The order of coins doesn’t matter.

Example :

For example, for N = 4 and S = {1,2,3}, there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. So output should be 4.
For N = 10 and S = {2, 5, 3, 6}, there are five solutions: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}. So the output should be 5.
*/

#include <iostream>
#include <vector>

// Method 1: Recursion....Time complexity : Exponential
/*
int change(int S[], int m, int n)
{
	// If n is 0 then there is 1 solution i.e do not include any coin.
	if (n == 0)
		return 1;
	// If n is less than 0 then no solution exists
	if (n < 0)
		return 0;
	// If there are no coins and n is greater than 0, then no solution exist
	if (m <= 0 && n > 0)
		return 0;
	// count is sum of solutions (i) excluding S[m-1]  (ii) including S[m-1]
	return change(S, m - 1, n) + change(S, m, n - S[m - 1]);
}

// Driver program to test above function
int main()
{
	int i, j;
	int arr[] = { 1, 2, 3 };
	int m = sizeof(arr) / sizeof(arr[0]);
	std::cout << change(arr, m, 4);
	return 0;
} */

// Method 2. Dynamic programming....Time complexity : O(n * amount)  Space : 0(n * amount)
/*
int change(std::vector<int>& coins, int amount)
{
	int n = coins.size();
	std::vector<std::vector<int>> dp(n + 1, std::vector<int>(amount + 1)); // similar to dp[n+1][amount+1];

	// Fill 1st col by 1 (assuming amount 0 can always be formed by not choosing any coin)
	for (int i = 0; i <= n; i++)
	{
		dp[i][0] = 1;
	}
	// Fill 1st row with 0 because no amount (except 0) can be formed without any coin
	for (int i = 1; i <= amount; i++)
	{
		dp[0][i] = 0;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= amount; j++)
		{
			if (j >= coins[i - 1])
				dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
			else
				dp[i][j] = dp[i - 1][j];

		}
	}
	return dp[n][amount];
}*/

// Method 3: Space optimized...Time complexity : O(n * amount)  Space : 0(amount)
int change(std::vector<int>& coins, int amount)
{
	int n = coins.size();
	if (n == 0) {
		if (amount == 0)
			return 1;
		else
			return 0;
	}
	// create and initialize vector to 0
	std::vector<int> dp(amount + 1, 0);
	dp[0] = 1;
	// Pick all coins one by one and update the dp[] values after the index greater than or equal to the value of the picked coin 
	for (int i = 0; i < n; i++) {
		for (int j = coins[i]; j <= amount; j++)
			dp[j] += dp[j - coins[i]];
	}
	return dp[amount];
}

// Driver program to test above function 
int main()
{
	std::vector<int> coins = { 1,2,3 };
	const int amount = 4;
	std::cout << change(coins, amount);
	return 0;
}
