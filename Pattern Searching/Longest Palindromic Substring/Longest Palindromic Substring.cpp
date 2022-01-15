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
#include <string.h>

// Time complexity : O(n^2), Space : O(1)
int expandAroundCenter(std::string& s, int left, int right)
{
    int n = s.length();
    while (left >= 0 && right < n && s[left] == s[right])
    {
        left--;
        right++;
    }
    return right - left - 1;
}

std::string longestPalindrome(std::string& s) 
{
    int n = s.length();
    int maxLength = 1;
    int palindromeStartAt = 0;
    for (int i = 0; i < n; i++)
    {
        int  oddLen = expandAroundCenter(s, i, i);
        int  evenLen = expandAroundCenter(s, i, i + 1);
        int len = std::max(oddLen, evenLen);
        if (maxLength < len)
        {
            maxLength = len;
            palindromeStartAt = i - (len - 1) / 2;
        }
    }

    return s.substr(palindromeStartAt, maxLength);
}

int main()
{
    std::string s = "babad";
    std::cout << longestPalindrome(s);
    return 0;
}

