/* Given two strings str1 and str2, the task is to find the length of the shortest string that has both 
str1 and str2 as subsequences.

Examples : 

Input:   str1 = "geek",  str2 = "eke"
Output: 5
Explanation: 
String "geeke" has both string "geek" 
and "eke" as subsequences.

Input:   str1 = "AGGTAB",  str2 = "GXTXAYB"
Output:  9
Explanation: 
String "AGXGTXAYB" has both string 
"AGGTAB" and "GXTXAYB" as subsequences.
*/

#include <iostream>
#include <string>
#include <vector>

// Method 1: Using LCS
/*
std::string getLongestCommonSubsequence(std::string str1, std::string str2)
{
    int len1 = str1.size();
    int len2 = str2.size();

    std::vector<std::vector<std::string>> dp(len1 + 1, std::vector<std::string>(len2 + 1));

    for (int i = 0; i <= len1; ++i)
    {
        for (int j = 0; j <= len2; ++j)
        {
            if (i == 0 || j == 0)
                dp[i][j] = "";
            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + str1[i - 1];
            else
                dp[i][j] = dp[i][j - 1].size() > dp[i - 1][j].size() ? dp[i][j - 1] : dp[i - 1][j];
        }
    }
    return dp[len1][len2];
}

std::string shortestCommonSupersequence(std::string str1, std::string str2)
{
    std::string result = "";
    std::string lcs = getLongestCommonSubsequence(str1, str2);

    int p1 = 0, p2 = 0;
    for (char c : lcs)
    {
        //Add all non-LCS chars from str1
        while (str1[p1] != c)
            result += str1[p1++];
        //Add all non-LCS chars from str2
        while (str2[p2] != c)
            result += str2[p2++];

        //Add LCS-char and increment both ptrs
        result += c;
        p1++;
        p2++;
    }

    // add leftover characters from str1 and str2
    result += str1.substr(p1) + str2.substr(p2);
    return result;
} */

// Method 2: Using edit distance concept
std::string shortestCommonSupersequence(std::string str1, std::string str2)
{
    int len1 = str1.size();
    int len2 = str2.size();

    std::vector<std::vector<int>> dp(len1 + 1, std::vector<int>(len2 + 1));

    for (int i = 0; i <= len1; i++)
    {
        for (int j = 0; j <= len2; j++)
        {
            if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;
            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + std::min(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // Now build the shortest Common Supersequence
    int index = dp[len1][len2];

    // Create a string of size index+1 to store the result
    std::string result(index + 1, '\0');

    // Start from the right-most-bottom-most corner and one by one add characters in result
    int i = len1, j = len2;
    while (i > 0 && j > 0)
    {
        // If current character in str1 and str2 are same, then current character is part of SCS
        if (str1[i - 1] == str2[j - 1])
        {
            // Put current character in result
            result[index - 1] = str1[i - 1];

            // reduce values of i, j and indexs
            i--; j--; index--;
        }
        // If not same, then find the smaller of two and go in the direction of smaller value
        else if (dp[i - 1][j] < dp[i][j - 1])
        {
            result[index - 1] = str1[i - 1];   i--;  index--;
        }
        else
        {
            result[index - 1] = str2[j - 1];  j--; index--;
        }
    }

    // Copy remaining characters of string str1
    while (i > 0)
    {
        result[index - 1] = str1[i - 1];   i--;  index--;
    }

    // Copy remaining characters of string str2
    while (j > 0)
    {
        result[index - 1] = str2[j - 1];  j--; index--;
    }

    return result;
}

int main()
{
    std::string str1 = "AGGTAB";
    std::string str2 = "GXTXAYB";

    std::cout << "Shortest common supersequence is " << shortestCommonSupersequence(str1, str2) << std::endl;

    return 0;
}

