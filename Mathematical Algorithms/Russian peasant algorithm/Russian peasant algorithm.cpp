/* Given two integers, write a function to multiply them without using multiplication operator.
There are many other ways to multiply two numbers. One interesting method is the Russian peasant algorithm. 
The idea is to double the first number and halve the second number repeatedly till the second number doesn’t become 1. 
In the process, whenever the second number become odd, we add the first number to result (result is initialized as 0) 
*/

#include <iostream>

unsigned int russianPeasant(unsigned int a, unsigned int b)
{
    int res = 0; 

    // While second number doesn't become 1
    while (b > 0)
    {
        // If second number becomes odd, add the first number to result
        if (b & 1)
            res = res + a;

        // Double the first number and halve the second number
        a = a << 1;
        b = b >> 1;
    }
    return res;
}

int main()
{
    std::cout << russianPeasant(18, 1) << std::endl;
    std::cout << russianPeasant(20, 12) << std::endl;
    return 0;
}