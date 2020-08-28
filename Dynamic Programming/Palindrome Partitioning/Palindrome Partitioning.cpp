/* Given a string, a partitioning of the string is a palindrome partitioning if every substring of the partition is a palindrome. 
For example, “aba|b|bbabb|a|b|aba” is a palindrome partitioning of “ababbbabbababa”. Determine the fewest cuts needed for a 
palindrome partitioning of a given string. For example, minimum of 3 cuts are needed for “ababbbabbababa”. The three cuts are 
“a|babbbab|b|ababa”. If a string is a palindrome, then minimum 0 cuts are needed. If a string of length n containing all different 
characters, then minimum n-1 cuts are needed.

Examples:

Input : str = “ababbbabbababa”
Output : 3

Input : str = “aaaa”
Output : 0
The string is already a palindrome.

Input : str = “abcde”
Output : 4
*/

#include <iostream>
#include <algorithm>
#include <vector>

// Method 1: Recursion....Time complexity : Exponential
/*
// Function to check if string str[i..j] is a palindrome or not
bool isPalindrome(std::string const& str, int i, int j)
{
	while (i <= j)
	{
		if (str[i++] != str[j--])
			return false;
	}
	return true;
}

int minPalindromePartition(std::string const& str, int i, int j)
{
	// base case: if starting index i and ending index j are equal or str[i..j] is already a palindrome.
	if (i == j || isPalindrome(str, i, j))
	{
		return 0;
	}

	int min = INT_MAX;
	// take the minimum over each possible position at which the string can be cut
	for (int k = i; k <= j-1; k++)
	{
		// recur to get minimum cuts required in str[i..k] and str[k+1..j]
		int count = 1 + minPalindromePartition(str, i, k) + minPalindromePartition(str, k + 1, j);
		min = std::min(min, count);
	}
	return min;
} 

// Driver Code
int main()
{
	std::string str = "ababbbabbababa";		// a|babbbab|b|ababa
	int n = str.length();
	std::cout << "The minimum cuts required such that each partition is a palindrome are " 
	    << minPalindromePartition(str, 0, n - 1);
	return 0;
} */

// Method 2. Dynamic programming....Time complexity : O(n^3)  Space : O(n^2)
/*
int minPalindromePartition(std::string const& str)
{
	int len = str.length();
	// cuts[i][j] = Minimum number of cuts needed for palindrome partitioning of substring str[i..j]
	// isPalindrome[i][j] = true if substring str[i..j] is palindrome, else false
	// Note that cuts[i][j] is 0 if isPalindrome[i][j] is true
	std::vector<std::vector<int>> cuts(len, std::vector<int>(len)); // similar to cuts[len][len]
	std::vector<std::vector<bool>> isPalindrome(len, std::vector<bool>(len)); //// similar to isPalindrome[len][len]

	// Every substring of length 1 is a palindrome 
	for (int i = 0; i < len; i++) {
		isPalindrome[i][i] = true;
		cuts[i][i] = 0;
	}
	// L is substring length
	for (int L = 2; L <= len; L++)
	{
		// For substring of length L, set different possible starting indexes
		for (int i = 0; i < len - L + 1; i++)
		{
			// Set ending index 
			int j = i + L - 1;
			// If L is 2, then we just need to compare two characters. 
			// Else need to check two corner characters and value of isPalindrome[i+1][j-1] 
			if (L == 2)
				isPalindrome[i][j] = (str[i] == str[j]);
			else
				isPalindrome[i][j] = (str[i] == str[j]) && isPalindrome[i + 1][j - 1];

			// If str[i..j] is palindrome, then cuts[i][j] is 0
			if (isPalindrome[i][j] == true)
			{
				cuts[i][j] = 0;
			}
			else
			{
				cuts[i][j] = INT_MAX;
				// Make a cut at every possible location starting from i to j and get the minimum cost cut
				for (int k = i; k <= j - 1; k++)
				{
					cuts[i][j] = std::min(cuts[i][j], cuts[i][k]+cuts[k+1][j]+1);
				}
			}
		}
	}
	return cuts[0][len - 1];
} */

// Method 3. Optimization to above approach....Time complexity : O(n^2)  Space : O(n^2)
int minPalindromePartition(std::string const& str)
{
	int len = str.length();
	// cuts[i] = Minimum number of cuts needed for palindrome partitioning of substring str[0..i]
	// isPalindrome[i][j] = true if substring str[i..j] is palindrome, else false
	// Note that cuts[i] is 0 if isPalindrome[0][i] is true
	std::vector<int> cuts(len); // similar to cuts[len]
	std::vector<std::vector<bool>> isPalindrome(len, std::vector<bool>(len)); //// similar to isPalindrome[len][len]

	// Every substring of length 1 is a palindrome 
	for (int i = 0; i < len; i++) {
		isPalindrome[i][i] = true;
	}
	// L is substring length
	for (int L = 2; L <= len; L++)
	{
		// For substring of length L, set different possible starting indexes
		for (int i = 0; i < len - L + 1; i++)
		{
			// Set ending index 
			int j = i + L - 1;
			// If L is 2, then we just need to compare two characters. 
			// Else need to check two corner characters and value of isPalindrome[i+1][j-1] 
			if (L == 2)
				isPalindrome[i][j] = (str[i] == str[j]);
			else
				isPalindrome[i][j] = (str[i] == str[j]) && isPalindrome[i + 1][j - 1];
		}
	}
	for (int i = 0; i < len; i++)
	{
		if (isPalindrome[0][i] == true)
		{
			cuts[i] = 0;
		}
		else
		{
			cuts[i] = INT_MAX;
			for (int j = 0; j < i; j++)
			{
				if (isPalindrome[j + 1][i] == true && 1 + cuts[j] < cuts[i])
					cuts[i] = 1 + cuts[j];
			}
		}
	}
	return cuts[len - 1];
}

// Driver Code
int main()
{
	std::string str = "BANANA";		// B|ANANA
	std::cout << "The minimum cuts required such that each partition is a palindrome are " 
		<< minPalindromePartition(str);
	return 0;
}