/* Given two sorted arrays and a number x, find the pair whose sum is closest to x and the pair has an element from each array.

Input:  ar1[] = {1, 4, 5, 7};
        ar2[] = {10, 20, 30, 40};
        x = 32
Output:  1 and 30
*/

#include <iostream>

void printClosest(int ar1[], int ar2[], int m, int n, int x)
{
    // res_l and res_r are result indexes from ar1[] and ar2[] respectively 
    int res_l = 0, res_r = n - 1;
    int l = 0, r = n - 1, diff = INT_MAX;
    while (l<m && r>=0)
    {
        // Check if this pair is closer than the closest pair so far 
        if (abs(ar1[l] + ar2[r] - x) < diff)
        {
            diff = abs(ar1[l] + ar2[r] - x);
            res_l = l;
            res_r = r;
        }
        // If this pair has more sum, move to smaller side. 
        if (ar1[l] + ar2[r] > x)
            r--;
        // Move to larger values 
        else
            l++;
    }
    std::cout << "The closest pair is [" << ar1[res_l] << ", " << ar2[res_r] << "] \n";
}

// Driver program to test above functions 
int main()
{
    int ar1[] = { 1, 4, 5, 7 };
    int ar2[] = { 10, 20, 30, 40 };
    int m = sizeof(ar1) / sizeof(ar1[0]);
    int n = sizeof(ar2) / sizeof(ar2[0]);
    int x = 38;
    printClosest(ar1, ar2, m, n, x);
    return 0;
}

