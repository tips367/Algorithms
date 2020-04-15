/* Given an unsorted array of integers, sort the array into a wave like array. 
An array ‘arr[0..n-1]’ is sorted in wave form if arr[0] >= arr[1] <= arr[2] >= arr[3] <= arr[4] >= …..

Examples:
Input:  arr[] = {10, 5, 6, 3, 2, 20, 100, 80}
Output: arr[] = {10, 5, 6, 2, 20, 3, 100, 80} OR
                {20, 5, 10, 2, 80, 6, 100, 3} OR
                any other array that is in wave form
*/

#include <iostream>
#include <algorithm>

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 1. Simple solution (Sort the array and swap adjacent elements), Time complexity : O(nlogn)
/*
void sortInWave(int arr[], int n)
{
    std::sort(arr, arr + n);
    for (int i = 0; i < n-1; i+=2)
    {
        swap(&arr[i], &arr[i + 1]);
    }
}*/

// 2. Better solution, Time complexity : O(n)

void sortInWave(int arr[], int n)
{
    // Traverse all even elements
    for (int i = 0; i < n ; i += 2)
    {
        // If current even element is smaller than previous 
        if(i>0 && arr[i]<arr[i-1])
            swap(&arr[i], &arr[i - 1]);
        // If current even element is smaller than next
        if (i < n - 1 && arr[i] < arr[i + 1])
            swap(&arr[i], &arr[i + 1]);
    }
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

// Driver program to test above function 
int main()
{
    int arr[] = { 10, 90, 49, 2, 1, 5, 23 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Given array is :\n");
    printArray(arr, n);

    sortInWave(arr, n);

    printf("Array in wave form :\n");
    printArray(arr, n);
    return 0;
}
