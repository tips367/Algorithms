// CombSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int getNextGap(int gap)
{
    // shrink gap by shrink factor
    gap = (gap * 10) / 13;
    if (gap < 1)
        return 1;
    return gap;
}

void combSort(int arr[], int n)
{
    // Initialize gap
    int gap = n;

    // Initialize swapped as true to make sure that loop runs 
    bool swapped = true;
    // Keep running while gap is more than 1 and last iteration caused a swap 
    while (gap != 1 || swapped == true)
    {
        // find next gap
        gap = getNextGap(gap);
        swapped = false;
        for (int i = 0; i < n - gap; i++)
        {
            if (arr[i] > arr[i + gap])
            {
                swap(&arr[i], &arr[i + gap]);
                swapped = true;
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
    int arr[] = { 8, 4, 1, 56, 3, -44, 23, -6, 28, 0 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Given array is \n");
    printArray(arr, n);

    combSort(arr, n);

    std::cout << "\nArray after comb sort is: \n";
    printArray(arr, n);
    return 0;
}
