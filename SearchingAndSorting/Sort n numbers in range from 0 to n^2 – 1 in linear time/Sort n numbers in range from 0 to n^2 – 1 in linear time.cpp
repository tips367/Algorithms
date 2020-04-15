/* Given an array of numbers of size n. It is also given that the array elements are in range from 0 to n^2 – 1. Sort the given array in linear time.

Examples:
Since there are 5 elements, the elements can be from 0 to 24.
Input: arr[] = {0, 23, 14, 12, 9}
Output: arr[] = {0, 9, 12, 14, 23}
*/

#include <iostream>

void countSort(int arr[], int n, int exp)
{
    int* output = new int[n];
    int* count = new int[n];
    for (int i = 0; i < n; i++)
    {
        count[i] = 0;
    }
    // Store count of occurrences in count[]
    for (int i = 0; i < n; i++)
    {
        count[(arr[i] / exp) % n]++;
    }
    // Change count[i] so that count[i] now contains actual position of this digit in output[]
    for (int i = 1; i < n; i++)
        count[i] += count[i - 1];
    // Build the output array 
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % n] - 1] = arr[i];
        count[(arr[i] / exp) % n]--;
    }
    // Copy the output array to arr[], so that arr[] now 
    // contains sorted numbers according to current digit 
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void sort(int arr[], int n)
{
    // Do counting sort for first digit in base n. Note that 
    // instead of passing digit number, exp (n^0 = 1) is passed. 
    countSort(arr, n, 1);

    // Do counting sort for second digit in base n. Note that 
    // instead of passing digit number, exp (n^1 = n) is passed. 
    countSort(arr, n, n);
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int main()
{
    // Since array size is 7, elements should be from 0 to 48 
    int arr[] = { 40, 12, 45, 32, 33, 1, 22 };
    int n = sizeof(arr) / sizeof(arr[0]);
    std::cout << "Given array is :\n";
    printArray(arr, n);

    sort(arr, n);

    std::cout << "Sorted array is :\n";
    printArray(arr, n);
    return 0;
}
