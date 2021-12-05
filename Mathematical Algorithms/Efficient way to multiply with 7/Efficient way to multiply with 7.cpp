// Efficient way to multiply with 7

#include <iostream>

long multiplyBySeven(long n)
{
    return ((n << 3) - n);
}

int main()
{
    long n = 4;

    std::cout << multiplyBySeven(n);

    return 0;
}

