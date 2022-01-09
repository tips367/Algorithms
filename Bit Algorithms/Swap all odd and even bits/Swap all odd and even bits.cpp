/* Given an unsigned integer, swap all odd bits with even bits. For example, if the given number is 23 (00010111), it should be converted 
to 43 (00101011). Every even position bit is swapped with adjacent bit on right side and every odd position bit is swapped with adjacent on 
left side.*/

#include <iostream>
/*
unsigned int swapBits(unsigned int x)
{
    for (int i = 0; i < 32; i += 2) 
    {
        int i_bit = (x >> i) & 1; // find i th bit
        int i_1_bit = (x >> (i + 1)) & 1;  // find i+1 th bit

        x = x - (i_bit << i) // remove i_bit
            - (i_1_bit << (i + 1)) // remove i+1 th bit
            + (i_bit << (i + 1)) // put i_bit at i+1 location
            + (i_1_bit << i);  // put i+1 bit at i location
    }
    return x;
} */

unsigned int swapBits(unsigned int x)
{
    // Get all even bits of x 
    unsigned int even_bits = x & 0xAAAAAAAA;

    // Get all odd bits of x 
    unsigned int odd_bits = x & 0x55555555;

    even_bits >>= 1; // Right shift even bits 
    odd_bits <<= 1; // Left shift odd bits 

    return (even_bits | odd_bits); // Combine even and odd bits 
}

int main()
{
    unsigned int x = 23; 
    std::cout << swapBits(x);

    return 0;
}
