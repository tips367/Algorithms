/* A number can always be represented as a sum of squares of other numbers. Note that 1 is a square and we can 
always break a number as (1*1 + 1*1 + 1*1 + …). Given a number n, find the minimum number of squares that sum to X.

Examples :

Input:  n = 100
Output: 1
Explanation:
100 can be written as 102. Note that 100 can also be written as 52 + 52 + 52 + 52, 
but this representation requires 4 squares.

Input:  n = 6
Output: 3
*/

#include <iostream>

// Method 1: Recursive...Time complexity: Exponential
/*
int getMinSquares(int n)
{
	if (n <= 3)
		return n;

	// if n is perfect square then Minimum squares required is 1
	int a = sqrt(n);
	if (a * a == n)
		return 1;

	// Maximum squares required is n (1*1 + 1*1 + ..)
	int minSquare = n;
	for (int i = 1; i * i <= n; i++)
	{
		minSquare = std::min(minSquare, 1 + getMinSquares(n-i*i));
	}
	return minSquare;
} */

// Method 2: Dynamic programming...Time complexity: O(n*sqrt(n))
int getMinSquares(int n)
{
	if (n <= 3)
		return n;

	int* dp = new int[n + 1];

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3

	for (int i = 4; i <= n; i++)
	{
		dp[i] = i;
		for (int j = 1; j * j <= i; j++)
		{
			dp[i] = std::min(dp[i], 1 + dp[i - j * j]);
		}
	}
	return dp[n];
}

int main()
{
	std::cout << getMinSquares(5) << std::endl;
	std::cout << getMinSquares(6) << std::endl;
	std::cout << getMinSquares(100) << std::endl;
	return 0;
}


