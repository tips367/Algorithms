/* Given an integer n, find whether it is a power of 4 or not.

Example : 

Input : 16
Output : 16 is a power of 4

Input : 20
Output : 20 is not a power of 4
*/

#include <iostream>

// Method 1.
/*
bool isPowerOfFour(int n)
{
    if (n < 1)
        return false;
    while (n % 4 == 0)
        n /= 4;
    return n == 1;
} */

// Method 2.
/*
bool isPowerOfFour(unsigned int n)
{
    int count = 0;

    // Check if there is only one bit set in n
    if (n && !(n & (n - 1)))
    {
        // count 0 bits before set bit 
        while (n > 1)
        {
            n >>= 1;
            count += 1;
        }

        // If count is even then return true else false
        return (count % 2 == 0) ? 1 : 0;
    }
    return 0;
} */

// Method 3.
/*
float logn(int n, int r)
{
    return log(n) / log(r);
}

bool isPowerOfFour(int n)
{
    if (n == 0)
        return false;
    return floor(logn(n, 4)) == ceil(logn(n, 4));
} */

// Method 4.
/*
bool isPerfectSqaure(int n)
{
    int x = sqrt(n);
    return (x * x == n);
}

bool isPowerOfFour(int n)
{
    if (n <= 0)
        return false;

    // Check whether 'n' is a perfect square or not
    if (!isPerfectSqaure(n))
        return false;

    // If 'n' is the perfect square
    // Check for the second condition i.e. 'n' must be power of two
    return !(n & (n - 1));
} */

// Method 5.
bool isPowerOfFour(int n)
{
    if (n < 1)
        return false;
    return ((n & (n - 1)) == 0) && (n & 0x55555555) != 0;

}

int main()
{
    int num = 64;
    if (isPowerOfFour(num))
        std::cout << num << " is a power of 4";
    else
        std::cout << num << "is not a power of 4";
}
