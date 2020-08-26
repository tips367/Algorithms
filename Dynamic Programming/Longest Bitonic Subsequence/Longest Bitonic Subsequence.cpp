/* Given an array arr[0 … n-1] containing n positive integers, a subsequence of arr[] is called Bitonic if it is first increasing, then decreasing. 
Write a function that takes an array as argument and returns the length of the longest bitonic subsequence.

Examples :

Input arr[] = {1, 11, 2, 10, 4, 5, 2, 1};
Output: 6 (A Longest Bitonic Subsequence of length 6 is 1, 2, 10, 4, 2, 1)

Input arr[] = {12, 11, 40, 5, 3, 1}
Output: 5 (A Longest Bitonic Subsequence of length 5 is 12, 11, 5, 3, 1)

Input arr[] = {80, 60, 30, 40, 20, 10}
Output: 5 (A Longest Bitonic Subsequence of length 5 is 80, 60, 30, 20, 10)
*/

#include <iostream>

// Method: Dynamic programming....Time complexity : O(n^2)  Space : 0(n) 
int longestBitonicSubsequence(int arr[], int n)
{
	// lis[i] ==> Longest Increasing subsequence ending with arr[i]
	int* lis = new int[n];
	// lds[i] ==> Longest decreasing subsequence starting with arr[i]
	int* lds = new int[n];
	for (int i = 0; i < n; i++)
	{
		lis[i] = 1;
		lds[i] = 1;
	}
	// Compute LIS values from left to right
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
				lis[i] = lis[j] + 1;
		}
	}
	// Compute LDS values from right to left
	for (int i = n - 2; i >= 0; i--)
	{
		for (int j = n - 1; j > i; j--)
		{
			if (arr[i] > arr[j] && lds[i] < lds[j] + 1)
				lds[i] = lds[j] + 1;
		}
	}
	int lbs = lis[0] + lds[0] - 1;
	for (int i = 1; i < n; i++)
	{
		if ((lis[i] + lds[i] - 1) > lbs)
			lbs = lis[i] + lds[i] - 1;
	}
	return lbs;	
}

/* Driver program to test above function */
int main()
{
	int arr[] = { 0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15 };
	int n = sizeof(arr) / sizeof(arr[0]);
	std::cout << "Length of Longest Bitonic Subsequence is " << longestBitonicSubsequence(arr, n);
	return 0;
}