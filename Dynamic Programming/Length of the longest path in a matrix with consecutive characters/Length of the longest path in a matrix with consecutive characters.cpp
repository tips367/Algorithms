/* Given a matrix of characters. Find length of the longest path from a given character, such that all characters 
in the path are consecutive to each other, i.e., every character in path is next to previous in alphabetical order. 
It is allowed to move in all 8 directions from a cell.

For ex.

 [ D, E, H, X, B ]
 [ A, O, G, P, E ]
 [ D, D, C, F, D ]
 [ E, B, E, A, S ]
 [ C, D, Y, E, N ]

 If starting point is 'C', then longest path with consecutive characters is 6.
 Longest path is C(2, 2) —> D(2, 1) —> E(3, 2) —> F(2, 3) —> G(1, 2) —> H(0, 2)
*/

#include <iostream>
#include <vector>

// Below arrays detail all eight possible movements
int row[] = {-1, -1, 0, 1, 1, 1, 0,-1 };
int col[] = { 0, -1,-1,-1, 0, 1, 1, 1};

// check whether cell (i, j) is valid or not
bool isValid(int i, int j, int M, int N) 
{
    return (i >= 0 && i < M && j >= 0 && j < N);
}

int findMaxLengthRecur(std::vector<std::vector<char>>& mat, std::vector<std::vector<int>>& dp, int i, int j, char prev)
{
    // base case: return length 0 if the current cell (i, j) is invalid or
    // the current character is not consecutive to the previous character
    if (!isValid(i, j, mat.size(), mat[0].size()) || prev + 1 != mat[i][j]) 
    {
        return 0;
    }

    if (dp[i][j] != -1)
        return dp[i][j];

    // stores length of the longest path
    int maxLength = 0;

    // recur for all eight adjacent cells from the current cell
    for (int k = 0; k < 8; k++)
    {
        // visit position `(i + row[k], j + col[k])` and find the maximum length from that path
        int len = findMaxLengthRecur(mat, dp, i + row[k], j + col[k], mat[i][j]);

        // update the length of the longest path if required
        maxLength = std::max(maxLength, 1 + len);
    }
    // save the answer and return
    return dp[i][j] = maxLength;
}

int findMaxLength(std::vector<std::vector<char>>& mat, char ch)
{
    int M = mat.size();
    int N = mat[0].size();

    // stores length of the longest path
    int maxLength = 0;

    std::vector<std::vector<int>> dp(M, std::vector<int>(N, -1));

    // traverse the matrix
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            // start from the current cell if its value matches with the given character
            if (mat[i][j] == ch)
            {
                // recur for all eight adjacent cells from the current cell
                for (int k = 0; k < 8; k++)
                {
                    // visit position `(i + row[k], j + col[k])` and find the maximum length from that path
                    int len = findMaxLengthRecur(mat, dp, i + row[k], j + col[k], ch);

                    // update the length of the longest path if required
                    maxLength = std::max(maxLength, 1 + len);
                }
            }
        }
    }
    return maxLength;
}

int main()
{
    // input matrix
    std::vector<std::vector<char>> mat =
    {
        { 'D', 'E', 'H', 'X', 'B' },
        { 'A', 'O', 'G', 'P', 'E' },
        { 'D', 'D', 'C', 'F', 'D' },
        { 'E', 'B', 'E', 'A', 'S' },
        { 'C', 'D', 'Y', 'E', 'N' }
    };

    // starting character
    char ch = 'C';

    std::cout << "The length of the longest path with consecutive characters starting from character " << ch << " is "
              << findMaxLength(mat, ch) << std::endl;

    return 0;
}

