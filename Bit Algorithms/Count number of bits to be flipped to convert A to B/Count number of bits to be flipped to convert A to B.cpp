/* Given two numbers ‘a’ and b’. Write a program to count number of bits needed to be flipped to convert ‘a’ to ‘b’. 
Example : 
 
Input : a = 10, b = 20
Output : 4
Binary representation of a is 00001010
Binary representation of b is 00010100
We need to flip highlighted four bits in a to make it b.
*/

#include <iostream>

// Method 1
/*
int countFlips(int a, int b)
{
    int flips = 0;

    while (a > 0 || b > 0) {

        int t1 = (a & 1);
        int t2 = (b & 1);

        if (t1 != t2)
            flips++;

        a >>= 1;
        b >>= 1;
    }

    return flips;
} */

// Method 2
int countSetBits(int n)
{
    int count = 0;
    while (n > 0)
    {
        count++;
        n &= (n - 1);
    }
    return count;
}

int countFlips(int a, int b)
{
    return countSetBits(a ^ b);
}

int main() 
{
    int a = 10;
    int b = 20;
    std::cout << countFlips(a, b);
}
