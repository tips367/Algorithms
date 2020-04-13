// IterativeQuickSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int l, int h)
{
    int pivot = arr[h];
    int i = l - 1;
    for (int j = l; j <= h - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[h]);
    return i + 1;
}

void quickSortIterative(int arr[], int l, int h)
{
    // Create an auxiliary stack 
    int* stack = new int[h - l + 1];
    int top = -1;
    // push initial values of l and h to stack 
    stack[++top] = l;
    stack[++top] = h;
    // Keep popping from stack while is not empty 
    while (top >= 0)
    {
        // Pop h and l 
        h = stack[top--];
        l = stack[top--];
        int p = partition(arr, l, h);
        // If there are elements on left side of pivot, 
        // then push left side to stack 
        if (p - 1 > l)
        {
            stack[++top] = l;
            stack[++top] = p - 1;
        }
        // If there are elements on right side of pivot, 
        // then push right side to stack 
        if (p + 1 < h)
        {
            stack[++top] = p + 1;
            stack[++top] = h;
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

// Driver code 
int main()
{
    int arr[] = { 4, 3, 5, 2, 1, 3, 2, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);
    std::cout << "Given array is : " << std::endl;
    printArray(arr, n);

    quickSortIterative(arr, 0, n - 1);

    std::cout << "Array after quick sort is: \n";
    printArray(arr, n);
    return 0;
}

