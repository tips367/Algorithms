/* Given N number of elements, find the minimum number of swaps required so that the maximum element is at the beginning 
and the minimum element is at last with the condition that only swapping of adjacent elements is allowed.

Examples:

Input: a[] = {3, 1, 5, 3, 5, 5, 2}
Output: 6
*/

#include <iostream>

void solve(int a[], int n)
{
    int max = a[0], min = a[0], l = 0, r = 0;
    for (int i = 1; i < n; i++) {

        // Index of leftmost largest element 
        if (a[i] > max) {
            max = a[i];
            l = i;
        }

        // Index of rightmost smallest element 
        if (a[i] <= min) {
            min = a[i];
            r = i;
        }
    }
    // One swap has already been performed while swapping the larger element to the front
    if (r < l)
        std::cout << l + (n - r - 2);
    else
        std::cout << l + (n - r - 1);
}

// Driver Code 
int main()
{
    int a[] = { 3, 1, 5, 3, 5, 5, 2 };
    int n = sizeof(a) / sizeof(a[0]);
    solve(a, n);
    return 0;
}


