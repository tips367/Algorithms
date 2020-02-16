// RadixSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int getMax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

void countingSort(int arr[], int n, int placeValue)
{
    int count[10] = { 0 };
    int* output = new int[n];
 
    for (int i = 0; i < n; i++)
    {
        count[(arr[i]/placeValue)%10]++;
    }
    for (int i = 1; i < 10 ; i++)
    {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / placeValue) % 10] - 1] = arr[i];
        count[(arr[i] / placeValue) % 10]--;
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int n)
{
    int max = getMax(arr, n); //For number of digits
    for (int placeValue = 1; max / placeValue > 0; placeValue *= 10)
        countingSort(arr, n, placeValue);
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
    int arr[] = { 4, 2, 2,56789, 8, 3, 3, 1000 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Given array is \n");
    printArray(arr, n);

    radixSort(arr, n);

    cout << "\nArray after radix sort is: \n";
    printArray(arr, n);
    return 0;
}