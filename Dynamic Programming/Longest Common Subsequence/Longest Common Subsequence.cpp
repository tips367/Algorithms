/* Given two sequences, find the length of longest subsequence present in both of them.
A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous.
For example, “abc”, “abg”, “bdf”, “aeg”, ‘”acefg”, ..etc are subsequences of “abcdefg”.

Examples :

LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3.
LCS for input Sequences “AGGTAB” and “GXTXAYB” is “GTAB” of length 4.
*/

#include <iostream>
#include <algorithm>
#include <vector>

// Method 1. Recursion... Time complexity : O(2^n)  Space : 0(1) No external space used apart from internal stack space
// Returns length of LCS for X[0..m-1], Y[0..n-1]
/*
int lcs(char X[], char Y[], int m, int n)
{
    if (m == 0 || n == 0)
        return 0;
    if (X[m - 1] == Y[n - 1])
        return 1 + lcs(X, Y, m - 1, n - 1);
    else
        return std::max(lcs(X, Y, m, n - 1), lcs(X, Y, m - 1, n));

}*/

// Method 2. Dynamic programming....Time complexity : O(mn)  Space : 0(mn) 

void printLcs(std::vector<std::vector<int>> const& L, char X[], char Y[], int m, int n)
{
    int index = L[m][n];
    char* lcs = new char[index + 1];
    lcs[index] = '\0';
    // Start from the right-most-bottom-most corner and one by one store characters in lcs[] 
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        // If current character in X[] and Y are same, then 
        // current character is part of LCS 
        if (X[i - 1] == Y[j - 1])
        {
            lcs[index - 1] = X[i - 1]; // Put current character in result 
            i--; j--; index--;      
        }

        // If not same, then find the larger of two and go in the direction of larger value 
        else if (L[i - 1][j] > L[i][j - 1])
            i--;
        else
            j--;
    }
    // Print the lcs 
    std::cout << "LCS of " << X << " and " << Y << " is " << lcs;
}

int lcs(char X[], char Y[], int m, int n)
{
    std::vector<std::vector<int>> L(m+1, std::vector<int>(n+1)); // similar to L[m+1][n+1];
    // Following steps build L[m+1][n+1] in bottom up fashion. 
    // Note that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] 
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                L[i][j] = 0;
            }
            else if (X[i - 1] == Y[j - 1])
            {
                L[i][j] = 1 + L[i - 1][j - 1];
            }
            else
            {
                L[i][j] = std::max(L[i - 1][j], L[i][j - 1]);
            }
        }
    }
    printLcs(L, X, Y, m, n);
    return L[m][n];
}

/* Driver code */
int main()
{
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";

    int m = strlen(X);
    int n = strlen(Y);

    std::cout << "\nLength of LCS is " << lcs(X, Y, m, n);

    return 0;
}


