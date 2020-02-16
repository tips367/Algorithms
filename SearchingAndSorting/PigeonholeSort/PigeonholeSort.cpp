// PigeonholeSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

void pigeonholeSort(int arr[], int n)
{
    int min = arr[0], max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (min > arr[i])
            min = arr[i];
        if (max < arr[i])
            max = arr[i];
    }
    int range = max - min + 1;
    // Create an array of vectors. Size of array range. Each vector represents a hole that 
    // is going to contain matching elements.
    std::vector<int> *holes = new std::vector<int>[range];
    // Traverse through input array and put every 
    // element in its respective hole 
    for (int i = 0; i < n; i++)
        holes[arr[i] - min].push_back(arr[i]);
    int index = 0;
    // Traverse through all holes one by one. For every hole, take its elements and put in array. 
    for (int i = 0; i < range; i++)
    {
        std::vector<int>::iterator it;
        for (it = holes[i].begin(); it != holes[i].end(); ++it)
            arr[index++] = *it;
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
    int arr[] = { 8, 3, 2, 7, 4, 6, 8 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Given array is \n");
    printArray(arr, n);

    pigeonholeSort(arr, n);

    std::cout << "\nArray after pigeonhole sort is: \n";
    printArray(arr, n);
    return 0;
}
