/* Given a number n, print all primes smaller than or equal to n. It is also given that n is a small number. 

Example:
Input : n =10
Output : 2 3 5 7
*/

#include <iostream>
#include <vector>

void SieveOfEratosthenes(int n)
{
    
    std::vector<bool> prime(n + 1, true);

    for (int p = 2; p * p <= n; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    // Print all prime numbers
    for (int p = 2; p <= n; p++)
        if (prime[p])
            std::cout << p << " ";
}

// Driver Code
int main()
{
    int n = 30;
    std::cout << "Following are the prime numbers smaller "
        << " than or equal to " << n << std::endl;
    SieveOfEratosthenes(n);
    return 0;
}

