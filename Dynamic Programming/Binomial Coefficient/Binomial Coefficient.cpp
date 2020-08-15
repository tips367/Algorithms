/* Write a function that takes two parameters n and k and returns the value of Binomial Coefficient C(n, k).

Following are common definition of Binomial Coefficients.
1. A binomial coefficient C(n, k) can be defined as the coefficient of X^k in the expansion of (1 + X)^n.
2. A binomial coefficient C(n, k) also gives the number of ways, disregarding order, that k objects can be chosen from among n objects; 
more formally, the number of k-element subsets (or k-combinations) of an n-element set.

The value of C(n, k) can be recursively calculated using following standard formula for Binomial Coefficients.

   C(n, k) = C(n-1, k-1) + C(n-1, k)
   C(n, 0) = C(n, n) = 1

Example :

Function should return 6 for n = 4 and k = 2, and it should return 10 for n = 5 and k = 2.
*/

#include <iostream>
#include <vector>
#include <algorithm>

// Method 1: Recursion....Time complexity : Exponential
/*
int binomialCoefficient(int n, int k)
{
    // Base Cases  
    if (k == 0 || k == n)
        return 1;

    return binomialCoefficient(n - 1, k - 1) + binomialCoefficient(n - 1, k);
} */

// Method 2. Dynamic programming....Time complexity : O(n*k)  Space : O(n*k)
/*
int binomialCoefficient(int n, int k)
{
    std::vector<std::vector<int>> C(n+1, std::vector<int>(k+1)); // similar to C[n+1][k+1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= std::min(i,k); j++)
        {
            if (j == 0 || j == i)
                C[i][j] = 1;
            else
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];

        }
    }
    return C[n][k];
}*/

// Method 3: Space optimized...Time complexity : O(n*k)  Space : 0(k)
int binomialCoefficient(int n, int k)
{
    std::vector<int> C(k + 1, 0);
    // nC0 is 1 
    C[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        // Compute next row of pascal triangle using the previous row 
        for (int j = std::min(i, k); j > 0; j--)
        {
            C[j] = C[j] + C[j - 1];
        }
    }
    return C[k];
}

/* Driver code*/
int main()
{
    int n = 5, k = 2;
    std::cout << "Value of C(" << n << ", " << k << ") is " << binomialCoefficient(n, k);
    return 0;
}