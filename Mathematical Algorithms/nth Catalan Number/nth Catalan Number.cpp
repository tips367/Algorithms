// nth Catalan Number

#include <iostream>
#include <vector>

// Method 1: Recursive...Time complexity: Exponential
/*
long int catalan(int n)
{
    // Base case
    if (n <= 1)
        return 1;

    // catalan(n) is sum of catalan(i)*catalan(n-i-1)
    long int res = 0;
    for (int i = 0; i < n; i++)
        res += catalan(i) * catalan(n - i - 1);

    return res;
} */

// Method 2: Dynamic programming...Time complexity: O(n^2)
/*
long int catalan(int n)
{
    if (n == 0)
        return 1;

    std::vector<long int> dp(n + 1, 0);

    dp[0] = dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            dp[i] += dp[j] * dp[i - j - 1];
        }
    }

    return dp[n];
} */

// Method 3: Using Binomial coefficient...Time complexity: O(n)

// Returns value of Binomial Coefficient C(n, k)
long int binomialCoeff(int n, int k)
{
    long int res = 1;

    // Since C(n, k) = C(n, n-k)
    if (k > n - k)
        k = n - k;

    // Calculate value of [n*(n-1)*---*(n-k+1)] / [k*(k-1)*---*1]
    for (int i = 0; i < k; ++i) 
    {
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}

long int catalan(int n)
{
    // Calculate value of 2nCn
    long int c = binomialCoeff(2 * n, n);

    // return 2nCn/(n+1)
    return c / (n + 1);
}

int main()
{
    for (int i = 0; i < 10; i++)
        std::cout << catalan(i) << " ";
    return 0;
}

