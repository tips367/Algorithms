/* The Longest Increasing Subsequence (LIS) problem is to find the length of the longest subsequence of a given sequence 
such that all elements of the subsequence are sorted in increasing order.

Examples :

Input  : arr[] = {3, 10, 2, 1, 20}
Output : Length of LIS = 3
The longest increasing subsequence is 3, 10, 20

Input : arr[] = {50, 3, 10, 7, 40, 80}
Output : Length of LIS = 4
The longest increasing subsequence is {3, 7, 40, 80}
*/

#include <iostream>
#include <algorithm>

// Method 1. Recursion... Time complexity : Exponential  Space : 0(1) No external space used apart from internal stack space
/*
int lis_recursive(int arr[], int n, int& max_ref)
{
    // Base case
    if (n == 1)
        return 1;

    // 'max_ending_here' is length of LIS  
    // ending with arr[n-1] 
    int res, max_ending_here = 1;

    // Recursively get all LIS ending with arr[0], arr[1] ... arr[n-2]. If arr[i-1] is smaller
    // than arr[n-1], and max ending with arr[n-1] needs to be updated, then update it 
    for (int i = 1; i < n; i++)
    {
        res = lis_recursive(arr, i, max_ref);
        if (arr[i - 1] < arr[n - 1] && res + 1 > max_ending_here)
            max_ending_here = res + 1;
    }

    // Compare max_ending_here with the overall  
    // max. And update the overall max if needed 
    if (max_ref < max_ending_here)
        max_ref = max_ending_here;

    // Return length of LIS ending with arr[n-1] 
    return max_ending_here;
}

int longestIncSubsequence(int arr[], int n)
{
    int max = 1;
    lis_recursive(arr, n, max);
    return max;
} */

// Method 2. Dyanmic programming....Time complexity : O(n^2)  Space : 0(n) 

int longestIncSubsequence(int arr[], int n)
{
    int* lis = new int[n];
    lis[0] = 1;
    for (int i = 1; i < n; i++)
    {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
        }
    }
    return *std::max_element(lis, lis + n);
}

/* Driver program to test above function */
int main()
{
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Length of longest increasing subsequence is %d\n",
        longestIncSubsequence(arr, n));
    return 0;
}
