/* Given a string s, return the longest palindromic substring in s.

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

Example 2:

Input: s = "cbbd"
Output: "bb"
*/

#include <iostream>
#include <string>
#include <vector>

// Time complexity : O(n), Space : O(n)
std::string longestPalindrome(std::string& s)
{
    int n = 2 * size(s) + 3;
    char* newstr = new char[n];
    newstr[0] = '@';
    newstr[n - 1] = '$';
    int index = 1;
    for (char c : s)
    {
        newstr[index++] = '#';
        newstr[index++] = c;
    }

    newstr[index] = '#';
    int maxLen = 0;
    int palindromeStartAt = 0;
    int maxRight = 0;
    int center = 0;
    std::vector<int> p(n, 0);
    for (int i = 1; i < n - 1; ++i)
    {
        if (i < maxRight)
            p[i] = std::min(p[2 * center - i], maxRight - i);

        // expand center
        while (newstr[i + p[i] + 1] == newstr[i - p[i] - 1])
            p[i]++;

        // update center and its bound
        if (i + p[i] > maxRight)
        {
            center = i;
            maxRight = i + p[i];
        }

        if (p[i] > maxLen)
        {
            maxLen = p[i];
            palindromeStartAt = (i - p[i] - 1) / 2;
        }
    }

    return s.substr(palindromeStartAt, maxLen);
}

int main()
{
    std::string s = "babad";
    std::cout << longestPalindrome(s);
    return 0;
}

