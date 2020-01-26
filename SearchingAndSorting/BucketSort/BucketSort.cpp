// BucketSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <vector>

void bucketSort(float arr[], int n)
{
    // 1. Create n empty buckets
    std::vector<float> *bucket = new std::vector<float>[n];

    // 2. put array elements in different buckets.
    for (int i = 0; i < n; i++)
    {
        int bucketIndex = n * arr[i];
        bucket[bucketIndex].push_back(arr[i]);
    }

    // 3. Sort each buckets
    for (int i = 0; i < n; i++)
    {
        std::sort(bucket[i].begin(), bucket[i].end());
    }

    // 4. Concatenate all buckets
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < bucket[i].size(); j++)
        {
            arr[index++] = bucket[i][j];
        }
    }
}

/* Function to print an array */
void printArray(float arr[], int size)
{
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

// Driver Code 
int main()
{
    float arr[] = { 0.78,0.17,0.39,0.26,0.72,0.94,0.21,0.12,0.23,0.68 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Given array is \n");
    printArray(arr, n);

    bucketSort(arr,n);

    printf ("\nArray after bucket sort is: \n");
    printArray(arr, n);
    return 0;
}

