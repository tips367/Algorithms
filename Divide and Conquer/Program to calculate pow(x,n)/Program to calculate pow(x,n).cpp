/* Given two integers x and n, write a function to compute x^n. We may assume that x and n are small and overflow doesn’t happen.

Examples :

Input : x = 2, n = 3
Output : 8

Input : x = 7, n = 2
Output : 49
*/

#include <iostream>

// Method 1: Recursive...Time complexity : O(log |n|)
/*
double myPow(double x, int n) 
{
    if (n == 0)
        return 1;

    double temp = myPow(x, n / 2);
    if (n & 1)
    {
        if (n > 0)
            return x * temp * temp;
        else
            return (temp * temp) / x;
    }
    else
        return temp * temp;
} */

// Method 2. Iterative...Time complexity : O(log |n|), Space : O(1)
double myPow(double x, int n)
{
    double res = 1;
    while (n) 
    {
        if (n % 2) 
            res = n > 0 ? res * x : res / x;
        x = x * x;
        n /= 2;
    }
    return res;
}


// Driver Code
int main()
{
	double x = 2;
	int n = -3;
	std::cout << myPow(x, n);
	return 0;
}
