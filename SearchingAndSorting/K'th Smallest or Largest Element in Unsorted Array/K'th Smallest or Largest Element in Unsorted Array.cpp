/* Given an array and a number k where k is smaller than size of array, we need to find the k’th smallest element in the given array. 
It is given that all array elements are distinct.

Input: arr[] = {7, 10, 4, 3, 20, 15}
k = 3
Output: 7
*/

#include <iostream>
#include <algorithm>
#include <queue>

// Method 1. Simple solution (Using sorting), Time Complexity : O(N log N)
/*
int kthSmallest(int arr[], int n, int k)
{
    std::sort(arr, arr + n);
    return arr[k - 1];
} */

// Method 2. Using Min-heap, Time Complexity : O(n + kLogn)
/*
int kthSmallest(int arr[], int n, int k)
{
    // Build a heap of n elements: O(n) time
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq(arr, arr + n);
    // Do extract min (k-1) times
    for (int i = 0; i < k - 1; i++)
    {
        pq.pop();
    }
    return pq.top();
}*/

// Method 3. Using Max-heap, Time Complexity : O(k + (n-k)*Logk)
/*
int kthSmallest(int arr[], int n, int k)
{
    // Build a heap of first k elements: O(k) time
    std::priority_queue<int> pq(arr, arr + k);
    // Process remaining n-k elements.  If current element is smaller than root, replace root with current element
    for (int i = k; i < n; i++)
    {
        if (arr[i] < pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
} */

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Method 4. Using QuickSelect, Time Complexity : Worst O(n^2) , Average O(n)
/*
int partition(int arr[], int l, int r)
{
    int pivot = arr[r];
    int i = l;
    for (int j = l; j <= r - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[r]);
    return i;
}

int kthSmallest(int arr[], int l,int r, int k)
{
    // If k is smaller than number of elements in array
    if (k > 0 && k <= r - l + 1)
    {
        int pos = partition(arr, l, r);
        // If position is same as k 
        if (pos - l == k - 1)
            return arr[pos];
        // If position is more, recur for left subarray
        if (pos - l > k - 1)
            return kthSmallest(arr,l,pos-1,k);
        // Else recur for right subarray 
        return kthSmallest(arr, pos + 1, r,k-pos+l-1 );
    }
    // If k is more than number of elements in array 
    return INT_MAX;
}*/

// Method 5. Randomized QuickSelect, Time Complexity : Worst O(n^2) , Expected O(n)

int partition(int arr[], int l, int r)
{
    int pivot = arr[r];
    int i = l;
    for (int j = l; j <= r - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[r]);
    return i;
}

// Picks a random pivot element between l and r and partitions 
// arr[l..r] around the randomly picked element using partition() 
int randomPartition(int arr[], int l, int r)
{
    int n = r - l + 1;
    int pivot = rand() % n;
    swap(&arr[l + pivot], &arr[r]);
    return partition(arr, l, r);
}

int kthSmallest(int arr[], int l, int r, int k)
{
    // If k is smaller than number of elements in array
    if (k > 0 && k <= r - l + 1)
    {
        int pos = randomPartition(arr, l, r);
        // If position is same as k 
        if (pos - l == k - 1)
            return arr[pos];
        // If position is more, recur for left subarray
        if (pos - l > k - 1)
            return kthSmallest(arr, l, pos - 1, k);
        // Else recur for right subarray 
        return kthSmallest(arr, pos + 1, r, k - pos + l - 1);
    }
    // If k is more than number of elements in array 
    return INT_MAX;
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

// Driver program to test above methods 
int main()
{
    int arr[] = { 12, 3, 5, 7, 19 };
    int n = sizeof(arr) / sizeof(arr[0]), k = 3;
    std::cout << "Given array is :" << std::endl;
    printArray(arr, n);
    // std::cout << "K'th smallest element is " << kthSmallest(arr, n, k);
    std::cout << "K'th smallest element is " << kthSmallest(arr,0,n-1, k);
    return 0;
}