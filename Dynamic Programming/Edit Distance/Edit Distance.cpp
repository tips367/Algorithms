/* Given two strings str1 and str2 and below operations that can performed on str1.
Find minimum number of edits(operations) required to convert ‘str1’ into ‘str2’.

1. Insert
2. Remove
3. Replace
All of the above operations are of equal cost.

Examples :

Input:   str1 = "geek", str2 = "gesek"
Output:  1
We can convert str1 into str2 by inserting a 's'

Input:   str1 = "sunday", str2 = "saturday"
Output:  3
Last three and first characters are same.  We basically need to convert "un" to "atur".
This can be done using below three operations.
Replace 'n' with 'r', insert t, insert a
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

// Method 1: Recursion....Time complexity : O(3^m)
/*
int editDistance(std::string const& str1, std::string const& str2, int m, int n)
{
    // If first string is empty, the only option is to insert all characters of second string into first 
    if (m == 0)
        return n;

    // If second string is empty, the only option is to remove all characters of first string 
    if (n == 0)
        return m;

    // If last characters of two strings are same, nothing much to do. Ignore last characters and get count for 
    // remaining strings. 
    if (str1[m - 1] == str2[n - 1])
        return editDistance(str1, str2, m - 1, n - 1);

    // If last characters are not same, consider all three operations on last character of first string, recursively 
    // compute minimum cost for all three operations and take minimum of three values. 
    return 1 + std::min(editDistance(str1, str2, m, n - 1), // Insert 
        std::min(editDistance(str1, str2, m - 1, n), // Remove 
        editDistance(str1, str2, m - 1, n - 1)) // Replace 
    );
} */

// Method 2: Dyanmic programming....Time complexity : O(mn)  Space : 0(mn)
/*
int editDistance(std::string const& str1, std::string const& str2, int m, int n)
{
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1)); // similar to dp[m+1][n+1];
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            // If first string is empty, the only option is to insert all characters of second string into first
            if (i == 0)
                dp[i][j] = j;
            // If second string is empty, the only option is to remove all characters of first string
            else if (j == 0)
                dp[i][j] = i;
            // If last characters of two strings are same, nothing much to do. Ignore last characters and get count for 
            // remaining strings.
            else if (str1[i-1] == str2[j-1])
                dp[i][j] = dp[i - 1][j - 1];
            // If the last character is different, consider all possibilities and find the minimum
            else
                dp[i][j] = 1 + std::min(std::min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]); // Insert, Remove, Replace
        }
    }
    return dp[m][n];
} */

// Method 3: Space optimized DP...Time complexity : O(mn)  Space : 0(m)
int editDistance(std::string const& str1, std::string const& str2, int m, int n)
{
    std::vector<std::vector<int>> dp(2, std::vector<int>(m + 1)); // similar to dp[2][m+1];

    // Base condition when str1 is empty then we must add all remaining str2 characters
    for (int i = 0; i <= m; i++)
        dp[0][i] = i;
    // This loop run for every character in second string 
    for (int i = 1; i <= n; i++)
    {
        // This loop compares the char from second string with first string characters
        for (int j = 0; j <= m; j++)
        {
            // if first string is empty then we have to perform add character operation to get second string 
            if (j == 0)
                dp[i % 2][j] = i;
            // If last characters of two strings are same, nothing much to do. Ignore last characters and get count for 
            // remaining strings.
            else if (str1[j - 1] == str2[i - 1])
                dp[i % 2][j] = dp[(i - 1) % 2][j - 1];
            // If the last character is different, consider all possibilities and find the minimum
            else
                dp[i % 2][j] = 1 + std::min(std::min(dp[i % 2][j - 1], dp[(i - 1) % 2][j]), dp[(i - 1) % 2][j - 1]); // Insert, Remove, Replace
        }
    }
    return dp[n % 2][m];
}

// Driver program 
int main()
{
    // your code goes here 
    std::string str1 = "sunday";
    std::string str2 = "saturday";

    std::cout << editDistance(str1, str2, str1.length(), str2.length());

    return 0;
}

