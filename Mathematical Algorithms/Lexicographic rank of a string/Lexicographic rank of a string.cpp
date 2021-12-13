/* Given a string, find its rank among all its permutations sorted lexicographically. For example, rank of “abc” is 1, 
rank of “acb” is 2, and rank of “cba” is 6. 

Examples: 

Input : str[] = "acb"
Output : Rank = 2

Input : str[] = "string"
Output : Rank = 598

Input : str[] = "cba"
Output : Rank = 6
*/

#include <iostream>
#include <algorithm>

#define MAX_CHAR 256

// Method 1: Using STL
/*
int findRank(std::string str)
{
    // store original string
    std::string orgStr = str;

    // Sort the string in lexicographically ascending order
    std::sort(str.begin(), str.end());

    long int i = 1;
    do 
    {
        // check for nth iteration
        if (str == orgStr)
            break;

        i++;
    } while (next_permutation(str.begin(), str.end()));

    return i;
} */

// Method 2: Time complexity : O(n^2)
/*
int fact(int n)
{
    return (n <= 1) ? 1 : n * fact(n - 1);
}

int countSmallerInRight(std::string& str, int low, int high)
{
    int countRight = 0;

    for (int i = low + 1; i <= high; ++i)
        if (str[i] < str[low])
            ++countRight;
    return countRight;
}

int findRank(std::string str)
{
    int len = size(str);
    int mult = fact(len);
    int rank = 1;

    for (int i = 0; i < len; i++)
    {
        mult /= (len - i);
        
        // count number of chars smaller than str[i] from str[i+1] to str[len-1]
        int countRight = countSmallerInRight(str, i, len - 1);
        rank += (countRight * mult);
    }
    return rank;
} */

// Method 3: Time complexity : O(n)
int fact(int n)
{
    return (n <= 1) ? 1 : n * fact(n - 1);
}

// Construct a count array where value at every index
// contains count of smaller characters in whole string
void populateAndIncreaseCount(int count[], std::string& str)
{
    int n = size(str);
    for (int i = 0; i<n; ++i)
        ++count[str[i]];

    for (int i = 1; i < MAX_CHAR; ++i)
        count[i] += count[i - 1];
}

// Removes a character ch from count[] array constructed by populateAndIncreaseCount()
void updatecount(int count[], char ch)
{
    for (int i = ch; i < MAX_CHAR; ++i)
        --count[i];
}

int findRank(std::string str)
{
    int len = size(str);
    int mult = fact(len);
    int rank = 1;

    int count[MAX_CHAR] = { 0 };

    // Populate the count array such that count[i] contains count of characters which are present in str and are smaller than i
    populateAndIncreaseCount(count, str);

    for (int i = 0; i < len; i++)
    {
        mult /= (len - i);

        rank += (count[str[i] - 1] * mult);

        // Reduce count of characters greater than str[i]
        updatecount(count, str[i]);
    }
    return rank;
}

int main()
{
    std::string str = "string";
    std::cout << findRank(str);
    return 0;
}

