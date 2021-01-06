/* The Fibonacci numbers are the numbers in the following integer sequence.
0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ……..

In mathematical terms, the sequence Fn of Fibonacci numbers is defined by the recurrence relation

Fn = Fn - 1 + Fn - 2
with seed values

F0 = 0 and F1 = 1.

Given a number n, print n-th Fibonacci Number.

Examples :
Input  : n = 2
Output : 1

Input  : n = 9
Output : 34
*/

#include <iostream>

// Method 1. Recursion... Time complexity : Exponential  Space : O(n) if we consider the function call stack size, otherwise O(1).
/*
int fib(int n)
{
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
} */

// Method 2. Dynamic programming....Time complexity : O(n)  Space : 0(n) 
/*
int fib(int n)
{
    int* f = new int[n + 2];
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        f[i] = f[i - 1] + f[i - 2];
    }
    return f[n];
} */

// Method 3: Space optimized method 2...Time complexity : O(n)  Space : O(1)
/*
int fib(int n)
{
    int a = 0, b = 1, c;
    if (n == 0)
        return a;
    for (int i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
} */

// Method 4: Using power of the matrix {{1,1},{1,0}}.....Time complexity : O(n)  Space : O(1)
/* if we n times multiply the matrix M = {{1,1},{1,0}} to itself (in other words calculate power(M, n )), 
then we get the (n+1)th Fibonacci number as the element at row and column (0, 0) in the resultant matrix.*/
/*
void multiply(int F[2][2], int M[2][2])
{
    int x = F[0][0] * M[0][0] + F[0][1] * M[1][0];
    int y = F[0][0] * M[0][1] + F[0][1] * M[1][1];
    int z = F[1][0] * M[0][0] + F[1][1] * M[1][0];
    int w = F[1][0] * M[0][1] + F[1][1] * M[1][1];

    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}

void power(int F[2][2], int n)
{
    int M[2][2] = { { 1, 1 }, { 1, 0 } };
    for (int i = 2; i <= n; i++)
        multiply(F, M);
}

int fib(int n)
{
    int F[2][2] = { { 1, 1 }, { 1, 0 } };
    if (n == 0)
        return 0;
    power(F, n - 1);
    return F[0][0];
} */

// Method 5 : (O(Log n) Time) 
/*
Below is one more interesting recurrence formula that can be used to find n’th Fibonacci Number in O(Log n) time.

If n is even then k = n / 2:
F(n) = [2 * F(k - 1) + F(k)] * F(k)

If n is odd then k = (n + 1) / 2
F(n) = F(k) * F(k) + F(k - 1) * F(k - 1)
*/

const int MAX = 1000;
int f[MAX] = { 0 }; // Array for memoization

int fib(int n)
{
    // Base cases 
    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return (f[n] = 1);

    // If fib(n) is already computed 
    if (f[n])
        return f[n];
    
    int k;
    if (n & 1)
    {
        k = (n + 1) / 2;
        f[n] = fib(k) * fib(k) + fib(k - 1) * fib(k - 1);
    }
    else
    {
        k = n / 2;
        f[n] = (2 * fib(k - 1) + fib(k)) * fib(k);
    }
    return f[n];
}

int main()
{
    int n;
    std::cout << "Enter a number : ";
    std::cin >> n;
    std::cout << fib(n);
    return 0;
}

