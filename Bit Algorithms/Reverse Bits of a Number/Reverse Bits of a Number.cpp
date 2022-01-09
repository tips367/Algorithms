/* Given an unsigned integer, reverse all bits of it and return the number with reversed bits.

Input : n = 1
Output : 2147483648

Input : n = 2147483648
Output : 1
*/

#include <iostream>

// Method 1
/*
uint32_t reverseBits(uint32_t n)
{
    uint32_t res = 0;
    for (int i = 0; i < 32; ++i)
        res = (res << 1) | (n >> i & 1);
    return res;
} */

// Method 2
uint32_t reverseBits(uint32_t n)
{
    n = ((n & 0xffff0000) >> 16) | ((n & 0x0000ffff) << 16);
    n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
    n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
    n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
    n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
    return n;
}

int main()
{
    uint32_t n = 1;
    std::cout << reverseBits(n);
}

