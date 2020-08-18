/* The longest palindromic subsequence is the longest sequence of characters in a string that spells the same forwards and backward.

A subsequence differs from a substring since characters in a subsequence are not required to be at consecutive positions in the original string.

Example :
Take string "ABBCDABBC", for example. Then the longest palindromic subsequence in this string is "BBABB".
*/

#include <iostream>
#include <algorithm>
#include <vector>

// Method 1: Recursion....Time complexity : Exponential O(2^n)
/*
int lps(char seq[], int i, int j)
{
	// if there is only one character
	if (i == j)
		return 1;
	// if there are two characters and both are same
	if (i + 1 == j && seq[i] == seq[j])
		return 2;
	// If the first and last characters match
	if (seq[i] == seq[j])
	    // include first and last characters in palindrome
		// and recur for the remaining substring seq[i+1, j-1]
		return 2 + lps(seq, i + 1, j - 1);

	// If the first and last characters do not match
	// 1. Remove last character & recur for the remaining substring seq[i, j-1]
	// 2. Remove first character & recur for the remaining substring seq[i+1, j]
	// return maximum of the two values
	return std::max(lps(seq, i+1, j), lps(seq,i,j-1));
} 

// Driver program to test above function
int main()
{
	char seq[] = "ABBCDABBC";
	int n = strlen(seq);
	std::cout << "The length of the LPS is "
		<< lps(seq, 0, n - 1);
	return 0;
}
*/

// Method 2. Dynamic programming....Time complexity : O(n^2)  Space : O(n^2)
int lps(char seq[])
{
	int n = strlen(seq);
	std::vector<std::vector<int>> L(n, std::vector<int>(n)); // similar to L[n][n];
	for (int i = 0; i < n; i++)
	{
		L[i][i] = 1;
	}
	for (int sublen = 2; sublen <= n; ++sublen)
	{
		for (int i = 0; i < n-sublen+1; ++i)
		{
			int j = i + sublen - 1;
			if (seq[i] == seq[j] && sublen == 2)
				L[i][j] = 2;
			else if (seq[i] == seq[j])
				L[i][j] = L[i + 1][j - 1] + 2;
			else
				L[i][j] = std::max(L[i][j - 1], L[i + 1][j]);
		}
	}
	return L[0][n - 1];
} 

// Driver program to test above functions
int main()
{
	char seq[] = "ABBCDABBC";
	std::cout << "The length of the LPS is "
		<< lps(seq);
	return 0;
}