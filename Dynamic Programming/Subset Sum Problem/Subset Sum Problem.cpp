/* Given a set of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum.

Examples:

Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 9
Output: True
There is a subset (4, 5) with sum 9.

Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 30
Output: False
There is no subset that add up to 30.
*/

#include <iostream>
#include <vector>

// Method 1: Recursion....Time complexity : Exponential
/*
bool isSubsetSum(int set[], int n, int sum)
{
    // Base Cases
	if (sum == 0)
		return true;
	if (n == 0)
		return false;
    // If last element is greater than sum, then ignore it 
	if (set[n - 1] > sum)
		return isSubsetSum(set, n - 1, sum);
    // else, check if sum can be obtained by any of the following:
    // (a) including the last element
    // (b) excluding the last element   
	return isSubsetSum(set, n - 1, sum) || isSubsetSum(set, n - 1, sum - set[n - 1]);
} */

// Method 2: Dynamic programming....Time complexity : O(n * sum)  Space : O(n * sum) 
/*
bool isSubsetSum(int set[], int n, int sum)
{
    // The value of subset[i][j] will be true if there is a subset of set[0..j-1] with sum equal to i 
    std::vector<std::vector<bool>> subset(n+1, std::vector<bool>(sum+1)); // similar to subset[n+1][sum+1];
    // If sum is 0, then answer is true i.e. we can have empty set whose sum is 0
    for (int i = 0; i < n; i++)
        subset[i][0] = true;
    // If sum is not 0 and set is empty, then answer is false 
    for (int i = 1; i <= sum; i++)
        subset[0][i] = false;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (j < set[i-1])
                subset[i][j] = subset[i - 1][j];
            else
                subset[i][j] = subset[i - 1][j] || subset[i - 1][j - set[i-1]];
        }
    }
    return subset[n][sum];
} */

// Method 3: Space optimized DP...Time complexity : O(n * sum)  Space : O(sum)
bool isSubsetSum(int set[], int n, int sum)
{
	std::vector<std::vector<bool>> subset(2, std::vector<bool>(sum + 1)); // similar to subset[2][sum+1];
	for (int i = 0; i <= n; i++) 
    {
		for (int j = 0; j <= sum; j++) 
        {
		    // A subset with sum 0 is always possible  
			if (j == 0)
				subset[i % 2][j] = true;
			// If there exists no element no sum is possible  
			else if (i == 0)
				subset[i % 2][j] = false;
			else if (set[i - 1] <= j)
				subset[i % 2][j] = subset[(i + 1) % 2][j - set[i - 1]] || subset[(i + 1) % 2][j];
			else
				subset[i % 2][j] = subset[(i + 1) % 2][j];
		}
	}
	return subset[n % 2][sum];
}

// Driver program 
int main()
{
    int set[] = { 3, 34, 4, 12, 5, 2 };
    int sum = 9;
    int n = sizeof(set) / sizeof(set[0]);
    if (isSubsetSum(set, n, sum) == true)
        std::cout << "Found a subset with given sum";
    else
        std::cout << "No subset found with given sum";
    return 0;
}