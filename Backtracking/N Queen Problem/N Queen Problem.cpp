/* The N Queen is the problem of placing N chess queens on an N×N chessboard so that no two queens attack each other. 

The expected output is a binary matrix which has 1s for the blocks where queens are placed. 
For example, following is the output matrix for 4 queen solution.

              { 0,  1,  0,  0}
              { 0,  0,  0,  1}
              { 1,  0,  0,  0}
              { 0,  0,  1,  0}
*/

#include <iostream>
#include <vector>

#define N 4

// Method 1: Brute
/*
bool isSafe(int board[][N], int r, int c)
{
    // Check this row on left side
    for (int i = 0; i < c; i++)
    {
        if (board[r][i])
            return false;
    }

    // Check upper diagonal on left side
    for (int i = r, j = c; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j])
            return false;
    }

    // Check lower diagonal on left side
    for (int i = r, j = c; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;
}

bool nQueen(int board[][N], int col)
{
    // If all queens are placed then return true
    if (col == N)
        return true;

    // try placing queen in all rows one by one for current column
    for (int i = 0; i < N; i++) 
    {
        // if no two queens threaten each other
        if (isSafe(board, i, col)) 
        {
            // Place this queen in board[i][col]
            board[i][col] = 1;

            // recur for next column
            if (nQueen(board, col + 1))
                return true;

            // backtrack and remove the queen from the current square
            board[i][col] = 0; 
        }
    }

    // If the queen cannot be placed in any row in this column then return false
    return false;
}

void printSolution(int board[][N])
{
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++)
            std::cout << board[i][j] << " ";
        std::cout << "\n";
    }
}

int main()
{
    int board[N][N] = { { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 } };

    if (nQueen(board, 0))
        printSolution(board);
    else
        std::cout << "Solution does not exist";   
} */

// Method 2: Efficient
bool nQueen(int board[][N], int col, 
    std::vector<int>& leftRow, std::vector<int>& upperDiagonal, std::vector<int>& lowerDiagonal)
{
	// If all queens are placed then return true
    if (col == N)
        return true;

    // try placing queen in all rows one by one for current column
    for (int i = 0; i < N; i++)
    {
        // if no two queens threaten each other
        if (leftRow[i] == 0 && lowerDiagonal[i + col] == 0
            && upperDiagonal[N - 1 + col - i] == 0)
        {
            // Place this queen in board[i][col]
            board[i][col] = 1;
            leftRow[i] = 1;
            lowerDiagonal[i + col] = 1;
            upperDiagonal[N - 1 + col - i] = 1;

            // recur for next column
            if (nQueen(board, col + 1, leftRow, upperDiagonal, lowerDiagonal))
                return true;

            // backtrack and remove the queen from the current square
            board[i][col] = 0;
            leftRow[i] = 0;
            lowerDiagonal[i + col] = 0;
            upperDiagonal[N - 1 + col - i] = 0;
        }
    }

    // If the queen cannot be placed in any row in this column then return false
    return false;
}

void printSolution(int board[][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            std::cout << board[i][j] << " ";
        std::cout << "\n";
    }
}

int main()
{
    int board[N][N] = { { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 } };

    std::vector<int> leftRow(N, 0), upperDiagonal(2 * N - 1, 0), lowerDiagonal(2 * N - 1, 0);

    if (nQueen(board, 0, leftRow, upperDiagonal, lowerDiagonal))
        printSolution(board);
    else
        std::cout << "Solution does not exist";
}