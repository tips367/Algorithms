/* Given a sorted array and a number x, find a pair in array whose sum is closest to x.

Examples:
Input: arr[] = {10, 22, 28, 29, 30, 40}, x = 54
Output: 22 and 30

Input: arr[] = {1, 3, 4, 7, 10}, x = 15
Output: 4 and 10
*/


#include <iostream>

void printClosest(int arr[], int n, int x)
{
    // To store indexes of result pair
    int res_l = 0, res_r = n-1;
    int l = 0, r = n - 1, diff = INT_MAX;
    while (r > l)
    {
        // Check if this pair is closer than the closest pair so far 
        if (abs(arr[l] + arr[r] - x) < diff)
        {
            diff = abs(arr[l] + arr[r] - x);
            res_l = l;
            res_r = r;
        }
        // If this pair has more sum, move to smaller values. 
        if (arr[l] + arr[r] > x)
            r--;
        // Move to larger values 
        else
            l++;
    }
    std::cout << "Pair in array whose sum is closest to " << x << " is : " << arr[res_l] << " " << arr[res_r];
}

// Driver program to test above functions 
int main()
{
    int arr[] = { 10, 22, 28, 29, 30, 40 }, x = 54;
    int n = sizeof(arr) / sizeof(arr[0]);
    printClosest(arr, n, x);
    return 0;
}

