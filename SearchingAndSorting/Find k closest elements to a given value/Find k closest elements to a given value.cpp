/* Given a sorted array arr[] and a value X, find the k closest elements to X in arr[].

Examples:
Input: K = 4, X = 35
       arr[] = {12, 16, 22, 30, 35, 39, 42,
               45, 48, 50, 53, 55, 56}
Output: 30 39 42 45
*/

#include <iostream>

/* Function to find the cross over point (the point before which elements are smaller than or equal to x and after
   which greater than x)*/
int findCrossOver(int arr[], int low, int high, int x)
{
    // x is greater than all
    if (x >= arr[high])
        return high;
    // x is smaller than all 
    if (x < arr[low])
        return low;
    int mid = (low + high) / 2;
    if (arr[mid] <= x && arr[mid + 1] > x)
    {
        return mid;
    }
    if (arr[mid] < x)
        return findCrossOver(arr, mid + 1, high, x);
    return findCrossOver(arr, low, mid - 1, x);
}

void printKClosest(int arr[], int x, int k, int n)
{
    int l = findCrossOver(arr, 0, n - 1, x);
    // Right index to search
    int r = l + 1;
    int count = 0;
    // If x is present in arr[], then reduce left index 
    // Assumption: all elements in arr[] are distinct
    if (arr[l] == x)
    {
        l--;
    }
    // Compare elements on left and right of crossover point to find the k closest elements 
    while (l >= 0 && r < n && count < k)
    {
        if (x - arr[l] < arr[r] - x)
            printf("%d ", arr[l--]);
        else
            printf("%d ", arr[r++]);
        count++;
    }
    // If there are no more elements on right side, then print left elements 
    while (count < k && l >= 0)
    {
        printf("%d ", arr[l--]);
        count++;
    }
    // If there are no more elements on left side, then print right elements 
    while (count < k && r < n)
    {
        printf("%d ", arr[r++]);
        count++;
    }
}

/* Driver program to check above functions */
int main()
{
    int arr[] = { 12, 16, 22, 30, 35, 39, 42,
                45, 48, 50, 53, 55, 56 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 35, k = 4;
    printKClosest(arr, x, k, n);
    return 0;
}


