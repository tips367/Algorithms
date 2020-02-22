/* Given an unsorted array arr[0..n - 1] of size n, find the minimum length subarray arr[start..end],
such that sorting this subarray makes the whole array sorted.

Examples:
1) If the input array is [10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60], program should be able to find 
that the subarray lies between the indexes 3 and 8.

2) If the input array is[0, 1, 15, 25, 6, 7, 30, 40, 50], program should be able to find that the 
subarray lies between the indexes 2 and 5.

*/

#include <iostream>

void printUnsortedSubarrayIndexes(int arr[], int n)
{
	int start = 0, end = n - 1, max, min;

	// 1) Find the candidate unsorted subarray

	// 1(a) Scan from left to right and find the first element which is greater than the next element. 
	// Let start be the index of such an element. In the above example 1, start is 3 (index of 30).
	for (start = 0; start < n - 1; start++)
	{
		if (arr[start] > arr[start + 1])
			break;
	}
	if (start == (n - 1))
	{
		std::cout << "The complete array is sorted." << std::endl;
		return;
	}

	// 1(b) Scan from right to left and find the first element(first in right to left order) which is smaller 
	// than the next element(next in right to left order).Let end be the index of such an element.
	// In the above example 1, end is 7 (index of 31).
	for (end = n - 1; end > 0; end--)
	{
		if (arr[end] < arr[end - 1])
			break;
	}

	// 2) Check whether sorting the candidate unsorted subarray makes the complete array sorted or not. 
	// If not, then include more elements in the subarray.

	// 2(a) Find the minimum and maximum values in arr[start..end]. Let minimum and maximum values be min and max. 
	// min and max for [30, 25, 40, 32, 31] are 25 and 40 respectively.
	max = arr[start];
	min = arr[start];
	for (int i = start + 1; i <= end; i++)
	{
		if (arr[i] > max)
			max = arr[i];
		if (arr[i] < min)
			min = arr[i];
	}
	
	// 2(b) Find the first element (if there is any) in arr[0..start-1] which is greater than min, 
	// change start to index of this element. There is no such element in above example 1.
	for (int i = 0; i < start; i++)
	{
		if (arr[i] > min)
		{
			start = i;
			break;
		}

	}

	// 2(c) Find the last element (if there is any) in arr[end+1..n-1] which is smaller than max, 
	// change end to index of this element. In the above example 1, end is changed to 8 (index of 35)
	for (int i = n - 1; i >= end + 1; i--)
	{
		if (arr[i] < max)
		{
			end = i;
			break;
		}
	}

	// 3) Print start and end
	std::cout << "The minimum length unsorted subarray sorting " << 
		"which makes complete array sorted lies between indexes " << start << " and " << end;
	return;
}

// Driver code
int main()
{
	//int arr[] = { 10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60 };
	int arr[] = { 0, 1, 15, 25, 6, 7, 30, 40, 50 };
	int arr_size = sizeof(arr) / sizeof(arr[0]);
	printUnsortedSubarrayIndexes(arr, arr_size);
	return 0;
}