/* Parity of a number refers to whether it contains an odd or even number of 1-bits. The number has “odd parity”, if it contains odd number 
of 1-bits and is “even parity” if it contains even number of 1-bits. */

#include <iostream>

bool getParity(unsigned int n)
{
    bool parity = 0;
    while (n)
    {
        parity = !parity;
        n = n & (n - 1);
    }
    return parity;
}

int main()
{
    unsigned int n = 7;
    std::cout << "Parity of no " << n << " = " << (getParity(n) ? "odd" : "even");

    return 0;
}