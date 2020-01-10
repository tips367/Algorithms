// RadixSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

void countingSort(int arr[], int n)
{
    int* count = (int*)malloc((max + 1) * sizeof(int));
    int* output = (int*)malloc(n * sizeof(int));
    for (int i = 0; i <= max; i++)
    {
        count[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }
    for (int i = 1; i <= max; i++)
    {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}
/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Driver Code 
int main()
{
    //int arr[] = { 10, 7, 8, 9, 1, 5, 8 };
    //int arr[] = { 4,3,1,5,2 };
    int arr[] = { 4, 2, 2, 8, 3, 3, 10000000 };

    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Given array is \n");
    printArray(arr, n);

    radixSort(arr, n);

    cout << "\nArray after radix sort is: \n";
    printArray(arr, n);
    return 0;
}