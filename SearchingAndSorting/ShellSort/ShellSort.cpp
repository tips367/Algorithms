// ShellSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void shellSort(int arr[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int j = gap; j < n; j++)
        {
            for (int i = j - gap; i >= 0; i = i - gap)
            {
                if (arr[i + gap] > arr[i])
                    break;
                else
                    swap(&arr[i + gap], &arr[i]);
            }
        }
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

// Driver Code 
int main()
{
    int arr[] = { 23, 29, 15, 19, 31, 7, 9, 5, 2 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Given array is \n");
    printArray(arr, n);

    shellSort(arr, n);

    std::cout << "\nArray after shell sort is: \n";
    printArray(arr, n);
    return 0;
}