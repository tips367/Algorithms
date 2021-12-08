/* Given two numbers M and N. The task is to print the number which has the maximum number of distinct prime factors of numbers in range M and N. If there exist multiple numbers, print the smallest one.

Examples: 

Input: a=4, b=10
Output: 6
Number of distinct Prime Factors of 4 is 1
Number of distinct Prime Factors of 5 is 1
Number of distinct Prime Factors of 6 is 2
Number of distinct Prime Factors of 7 is 1
Number of distinct Prime Factors of 8 is 1
Number of distinct Prime Factors of 9 is 1
Number of distinct Prime Factors of 10 is 2

Input: a=100, b=150
Output: 102
*/

#include <iostream>
#include <vector>

int maximumNumberDistinctPrimeRange(int m, int n)
{
    // array to store the number of distinct primes
    std::vector<int> factorCount(n + 1, 0);

    std::vector<bool> prime(n + 1, true);

    for (int i = 2; i <= n; i++) 
    {
        if (prime[i] == true) {

            // Number is prime
            factorCount[i] = 1;

            for (int j = i * 2; j <= n; j += i) {

                // incrementing factorCount of all the factors of i
                factorCount[j]++;
                prime[j] = false;
            }
        }
    }

    int max = factorCount[m];
    int num = m;

    for (int i = m; i <= n; i++) 
    {
        if (factorCount[i] > max) 
        {
            max = factorCount[i];
            num = i;
        }
    }
    return num;
}

int main()
{
    int m = 100, n = 150;
    std::cout << maximumNumberDistinctPrimeRange(m, n);
    return 0;
}
