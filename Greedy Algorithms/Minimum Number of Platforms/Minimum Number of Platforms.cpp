/* Given the arrival and departure times of all trains that reach a railway station, the task is to find the minimum number of platforms 
required for the railway station so that no train waits. 
We are given two arrays that represent the arrival and departure times of trains that stop.

Examples:

Input: arr[] = {9:00, 9:40, 9:50, 11:00, 15:00, 18:00}
dep[] = {9:10, 12:00, 11:20, 11:30, 19:00, 20:00}
Output: 3
Explanation: There are at-most three trains at a time (time between 9:40 to 12:00)

Input: arr[] = {9:00, 9:40}
dep[] = {9:10, 12:00}
Output: 1
Explanation: Only one platform is needed.
*/

#include <iostream>
#include <algorithm>

// Method 1: Naive...Time complexity: O(n^2)
/*
int findPlatform(int arr[], int dep[], int n)
{
    int platformNeeded = 1, result = 1;
    int i = 1, j = 0;

    // run a nested  loop to find overlap
    for (int i = 0; i < n; i++) 
    {
        // minimum platform
        platformNeeded = 1;
        for (int j = i + 1; j < n; j++) 
        {
            // check for overlap
            if ((arr[i] >= arr[j] && arr[i] <= dep[j]) ||
                (arr[j] >= arr[i] && arr[j] <= dep[i]))
                platformNeeded++;
        }

        result = std::max(result, platformNeeded);
    }

    return result;
} */

// Method 2: Efficient...Time complexity : O(n log n)
int findPlatform(int arr[], int dep[], int n)
{
    // Sort arrival and departure arrays
    std::sort(arr, arr + n);
    std::sort(dep, dep + n);

    int platformNeeded = 1, result = 1;
    int i = 1, j = 0;

    // Similar to merge in merge sort to process all events in sorted order
    while (i < n && j < n) 
    {
        // If next event in sorted order is arrival, increment count of platforms needed
        if (arr[i] <= dep[j]) 
        {
            platformNeeded++;
            i++;
        }
        // Else decrement count of platforms needed
        else if (arr[i] > dep[j]) 
        {
            platformNeeded--;
            j++;
        }

        result = std::max(platformNeeded, result);
    }

    return result;
}

int main()
{
    int arr[] = { 900, 940, 950, 1100, 1500, 1800 };
    int dep[] = { 910, 1200, 1120, 1130, 1900, 2000 };
    int n = sizeof(arr) / sizeof(arr[0]);
    std::cout << "Minimum Number of Platforms Required = " << findPlatform(arr, dep, n);
    return 0;
}
