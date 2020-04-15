/* Given an array which is sorted, but after sorting some elements are moved to either of the adjacent positions, 
i.e., arr[i] may be present at arr[i+1] or arr[i-1]. Write an efficient function to search an element in this array. 
Basically the element arr[i] can only be swapped with either arr[i+1] or arr[i-1].

Examples:
For example consider the array {2, 3, 10, 4, 40}, 4 is moved to next position and 10 is moved to previous position.

Input: arr[] =  {10, 3, 40, 20, 50, 80, 70}, key = 40
Output: 2
Output is index of 40 in given array
*/

#include <iostream>

int binarySearch(int arr[], int l, int r, int x)
{
    if (l <= r)
    {
        int mid = l + (r - l) / 2;
        // If the element is present at one of the middle 3 positions 
        if (arr[mid] == x)
            return mid;
        if (l < mid && arr[mid - 1] == x)
            return mid-1;
        if (mid < r && arr[mid + 1] == x)
            return mid + 1;

        if (arr[mid] > x)
        {
            return binarySearch(arr, l, mid - 2, x);
        }
        return binarySearch(arr, mid + 2, r, x);
    }
    return -1;
}

// Driver Code 
int main(void)
{
    int arr[] = { 3, 2, 10, 4, 40 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 4;
    int result = binarySearch(arr, 0, n - 1, x);
    (result == -1) ? printf("Element is not present in array")
        : printf("Element is present at index %d",
            result);
    return 0;
}