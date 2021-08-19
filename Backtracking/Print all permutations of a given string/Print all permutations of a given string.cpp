/* A permutation, also called an “arrangement number” or “order,” is a rearrangement of the elements of an 
ordered list S into a one-to-one correspondence with S itself. A string of length n has n! permutation. 

Below are the permutations of string ABC.
ABC ACB BAC BCA CBA CAB
*/

#include <iostream>
#include <string>

void permutations(std::string str, int i, int n)
{
    // base condition
    if (i == n - 1)
    {
        std::cout << str << std::endl;
        return;
    }

    // process each character of the remaining string
    for (int j = i; j < n; j++)
    {
        // swap character at index i with the current character
        std::swap(str[i], str[j]);
        // recur for substring str[i+1, n-1]
        permutations(str, i + 1, n);
        // backtrack (restore the string to its original state)
        std::swap(str[i], str[j]);
    }
}

int main()
{
    std::string str = "ABC";

    permutations(str, 0, str.length());

    return 0;
}


