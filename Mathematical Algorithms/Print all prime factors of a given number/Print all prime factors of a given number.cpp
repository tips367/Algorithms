/* Given a number n, write an efficient function to print all prime factors of n. For example, if the input number is 12, then the 
output should be “2 2 3”. And if the input number is 315, then the output should be “3 3 5 7”.
*/

#include <iostream>

void primeFactors(int n)
{
    // Print the number of 2s that divide n
    while (n % 2 == 0)
    {
        std::cout << 2 << " ";
        n = n / 2;
    }

    // n must be odd at this point. So we can skip one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        // While i divides n, print i and divide n
        while (n % i == 0)
        {
            std::cout << i << " ";
            n = n / i;
        }
    }

    // This condition is to handle the case when n is a prime number greater than 2
    if (n > 2)
        std::cout << n << " ";
}

int main()
{
    int n = 315;
    primeFactors(n);
    return 0;
}
