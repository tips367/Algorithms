/* You are given n pairs of numbers. In every pair, the first number is always smaller than the second number. 
A pair (c, d) can follow another pair (a, b) if b < c. Chain of pairs can be formed in this fashion. 
Find the longest chain which can be formed from a given set of pairs.

Example :

For example, if the given pairs are {{5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90} }, 
then the longest chain that can be formed is of length 3, and the chain is {{5, 24}, {27, 40}, {50, 90}}
*/

#include <iostream>
#include <algorithm>

class Pair
{
public:
    int a;
    int b;
};

bool sortByFirst( Pair const& x, Pair const& y)
{
    return (x.a < y.a);
}

// Method: Dynamic programming....Time complexity : O(n^2)
int maxChainLength(Pair arr[], int n)
{
    // Sorting given pairs in increasing order of first (or smaller) element
    std::sort(arr, arr + n, sortByFirst);
    int* mcl = new int[n];
    mcl[0] = 1;
    for (int i = 1; i < n; i++)
    {
        mcl[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[j].b < arr[i].a && mcl[i] < mcl[j] + 1)
                mcl[i] = mcl[j] + 1;
        }
    }
    return *std::max_element(mcl, mcl + n);
}

// Driver code
int main()
{
    Pair arr[] = { {50, 60}, {5, 24}, {15, 25}, {27, 40} };
    int n = sizeof(arr) / sizeof(arr[0]);
    std::cout << "Length of maximum size chain is " << maxChainLength(arr, n);
    return 0;
}