/* Partition problem is to determine whether a given set can be partitioned into two subsets such that the sum 
of elements in both subsets is same.

Examples:

arr[] = {1, 5, 11, 5}
Output: true
The array can be partitioned as {1, 5, 5} and {11}

arr[] = {1, 5, 3}
Output: false
The array cannot be partitioned into equal sum sets.
*/

#include <iostream>
#include <vector>

// Method 1: Recursion....Time complexity : O(2^n)
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
}

bool isPartitionPossible(int set[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += set[i];

    // If sum is odd, there cannot be two subsets with equal sum  
    if (sum % 2 != 0)
        return false;

    // Find if there is subset with sum equal to half of total sum  
    return isSubsetSum(set, n, sum / 2);
} 

// Driver program 
int main()
{
    int arr[] = { 3, 1, 5, 9, 12 };
    int n = sizeof(arr) / sizeof(arr[0]);
    if (isPartitionPossible(arr, n) == true)
        std::cout << "Given set can be partitioned into two subsets of equal sum";
    else
        std::cout << "Given set cannot be partitioned into two subsets of equal sum";
    return 0;
}