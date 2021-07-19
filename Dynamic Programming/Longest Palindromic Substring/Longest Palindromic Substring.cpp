/* Given a string, find the longest substring which is palindrome. 

Example 1:

Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Example 2:

Input: s = "cbbd"
Output: "bb"
*/

#include <iostream>
#include <vector>

// Utility function to print substring
void printSubStr(std::string& str, int low, int high)
{
    for (int i = low; i <= high; ++i)
        std::cout << str[i];
}

// Method 1. Brute force......Time complexity : O(n^3)....Space : (1)
/*
bool isPalindrome(std::string& str, int low, int high)
{
    while (high > low)
    {
        if (str[low++] != str[high--])
        {
            return false;
        }
    }
    return true;
}

int longestPalindromicSubstring(std::string& str)
{
    int n = str.length();

    // All substrings of length 1 are palindromes
    int maxLength = 1, palindromeBeginsAt = 0;

    for (int i = 0; i < n; i++) 
    {
        for (int j = i; j < n; j++) 
        {
            if (isPalindrome(str, i, j) && (j - i + 1) > maxLength) 
            {
                palindromeBeginsAt = i;
                maxLength = j - i + 1;
            }
        }
    }

    std::cout << "Longest palindrome substring is: ";
    printSubStr(str, palindromeBeginsAt, palindromeBeginsAt + maxLength - 1);

    return maxLength;
} */

// Method 2. Using dynamic programming......Time complexity : O(n^2)....Space : (n^2)
int longestPalindromicSubstring(std::string& str)
{
    int n = str.size();

    int maxLength = 1, palindromeBeginsAt = 0;

    // palindrome[i][j] will be false if substring str[i..j] is not palindrome.
    // Else palindrome[i][j] will be true
    std::vector<std::vector<bool>> palindrome(n, std::vector<bool>(n));

    // All substrings of length 1 are palindromes
    for (int i = 0; i < n; i++)
        palindrome[i][i] = true;

    // check for sub-string of length 2.
    for (int i = 0; i < n - 1; i++) 
    {
        if (str[i] == str[i + 1]) 
        {
            palindrome[i][i + 1] = true;
            palindromeBeginsAt = i;
            maxLength = 2;
        }
    }

    // Check for lengths greater than 2.
    for (int currLen = 3; currLen <= n; currLen++)
    {
        // Fix the starting index
        for (int i = 0; i < n - currLen + 1; i++)
        {
            // Get the ending index of substring from starting index i and length currLen
            int j = i + currLen - 1;

            // 1. The first and last characters should match
            // 2. Rest of the substring should be a palindrome
            if (str[i] == str[j] && palindrome[i + 1][j - 1])
            {
                palindrome[i][j] = true;

                if (currLen > maxLength) 
                {
                    palindromeBeginsAt = i;
                    maxLength = currLen;
                }
            }
        }
    }

    std::cout << "Longest palindrome substring is: ";
    printSubStr(str, palindromeBeginsAt, palindromeBeginsAt + maxLength - 1);

    return maxLength;
}

int main()
{
    std::string str = "babad";
    std::cout << "\nLength is: " << longestPalindromicSubstring(str);
    return 0;
}