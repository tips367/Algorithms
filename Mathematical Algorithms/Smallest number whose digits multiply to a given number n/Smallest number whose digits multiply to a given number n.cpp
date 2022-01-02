/* Given a number ‘n’, find the smallest number ‘p’ such that if we multiply all digits of ‘p’, we get ‘n’. 
The result ‘p’ should have minimum two digits.

Examples: 
 
Input:  n = 36
Output: p = 49 
// 4*9 = 36 and 49 is the smallest such number

Input:  n = 100
Output: p = 455
//  4*5*5 = 100 and 455 is the smallest such number

Input: n = 1
Output:p = 11
//  1*1 = 1

Input: n = 13
Output: Not Possible
*/

#include <iostream>
#include <vector>

#define MAX 50

void findSmallest(int n)
{
    std::vector<int> res(MAX);

    // Case 1: If number is smaller than 10
    if (n < 10)
    {
        std::cout << n + 10 << std::endl;
        return;
    }

    int j = 0;
    // Case 2: Start with 9 and try every possible digit
    for (int i = 9; i > 1; i--)
    {
        // If current digit divides n, then store all
        // occurrences of current digit in res
        while (n % i == 0)
        {
            n = n / i;
            res[j] = i;
            j++;
        }
    }

    // If n could not be broken in form of digits (prime factors of n are greater than 9)
    if (n > 10)
    {
        std::cout << "Not possible\n";
        return;
    }

    // Print the result array in reverse order
    for (int i = j - 1; i >= 0; i--)
        std::cout << res[i];
    std::cout << "\n";
}

// Driver Code
int main()
{
    findSmallest(7);
    findSmallest(36);
    findSmallest(13);
    findSmallest(100);
    return 0;
}
