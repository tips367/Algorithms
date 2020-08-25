/* Given an array of n positive integers. Write a program to find the sum of maximum sum subsequence of the given array 
such that the integers in the subsequence are sorted in increasing order. 

Example :

Input  : {1, 101, 2, 3, 100, 4, 5}
Output : 106 (1 + 2 + 3 + 100)

Input  : {10, 5, 4, 3}
Output : 10
*/

#include <iostream>
#include <algorithm>

// Method 1. Dynamic programming....Time complexity : O(n^2)  Space : 0(n) 
int maxSumIncreasingSubseq(int arr[], int n)
{
    int* dp = new int[n];
    // Initialize max sum increasing subsequence values for all indexes 
    for (int i = 0; i < n; i++)
        dp[i] = arr[i];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && dp[i] < dp[j] + arr[i])
                dp[i] = dp[j] + arr[i];
        }
    }
    return *std::max_element(dp, dp + n);
}

// Driver Code  
int main()
{
    int arr[] = { 1, 101, 2, 3, 100, 4, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    std::cout << "Sum of maximum sum increasing subsequence is " << maxSumIncreasingSubseq(arr, n) << std::endl;
    return 0;
}