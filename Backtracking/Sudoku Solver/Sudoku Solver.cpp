/* Given a partially filled 9×9 2D array ‘grid[9][9]’, the goal is to assign digits (from 1 to 9) to the empty cells 
so that every row, column, and subgrid of size 3×3 contains exactly one instance of the digits from 1 to 9.

Example:

Input:
grid = { {3, 0, 6, 5, 0, 8, 4, 0, 0},
         {5, 2, 0, 0, 0, 0, 0, 0, 0},
         {0, 8, 7, 0, 0, 0, 0, 3, 1},
         {0, 0, 3, 0, 1, 0, 0, 8, 0},
         {9, 0, 0, 8, 6, 3, 0, 0, 5},
         {0, 5, 0, 0, 9, 0, 6, 0, 0},
         {1, 3, 0, 0, 0, 0, 2, 5, 0},
         {0, 0, 0, 0, 0, 0, 0, 7, 4},
         {0, 0, 5, 2, 0, 6, 3, 0, 0} }
Output:
          3 1 6 5 7 8 4 9 2
          5 2 9 1 3 4 7 6 8
          4 8 7 6 2 9 5 3 1
          2 6 3 4 1 5 9 8 7
          9 7 4 8 6 3 1 2 5
          8 5 1 7 9 2 6 4 3
          1 3 8 9 4 7 2 5 6
          6 9 2 3 5 1 8 7 4
          7 4 5 2 8 6 3 1 9
*/

#include <iostream>
#include <vector>

// Method 1
/*
bool isSafe(std::vector<std::vector<int>>& board, int i, int j, int num)
{
    // Check if 'num' is not already placed in current row, current column and current 3x3 box
    int subMat_i = i / 3 * 3;
    int subMat_j = j / 3 * 3;
    for (int k = 0; k < 9; k++)
    {
        if (board[i][k] == num || board[k][j] == num ||
            board[subMat_i + k / 3][subMat_j + k % 3] == num)
            return false;
    }
    return true;
}

bool solveSudoku(std::vector<std::vector<int>>& board, int i, int j)
{
    if (i == board.size())
        return true;

    int next_i = i, next_j = j;
    if (j == board[0].size() - 1)
    {
        next_i = i + 1;
        next_j = 0;
    }
    else
    {
        next_j = j + 1;
    }

    if (board[i][j] == 0)
    {
        for (int digit = 1; digit <= 9; ++digit)
        {
            if (isSafe(board, i, j, digit))
            {
                board[i][j] = digit;
                if (solveSudoku(board, next_i, next_j))
                    return true;
                board[i][j] = 0;
            }
        }
        return false;
    }
    else
    {
        if (solveSudoku(board, next_i, next_j))
            return true;
    }
    return false;
} */

// Method 2: More efficient

int rows[9];
int cols[9];
int box[9];

bool isSafe(std::vector<std::vector<int>>& board, int i, int j, int num)
{
    // Check if 'num' is not already placed in current row, current column and current 3x3 box
    int bitPosition = 1 << (num - 1);
    int boxIndex = (i / 3) * 3 + j / 3;
    if (rows[i] & bitPosition || cols[j] & bitPosition ||
        box[boxIndex] & bitPosition)
        return false;
    return true;
}

bool solve(std::vector<std::vector<int>>& board, int i, int j)
{
    if (i == board.size())
        return true;

    int next_i = i, next_j = j;
    if (j == board[0].size() - 1)
    {
        next_i = i + 1;
        next_j = 0;
    }
    else
    {
        next_j = j + 1;
    }

    if (board[i][j] == 0)
    {
        for (int digit = 1; digit <= 9; ++digit)
        {
            if (isSafe(board, i, j, digit))
            {
                board[i][j] = digit;

                int bitPosition = 1 << (digit - 1);
                int boxIndex = (i / 3) * 3 + j / 3;
                rows[i] |= bitPosition;
                cols[j] |= bitPosition;
                box[boxIndex] |= bitPosition;

                if (solve(board, next_i, next_j))
                    return true;

                board[i][j] = 0;

                rows[i] &= ~bitPosition;
                cols[j] &= ~bitPosition;
                box[boxIndex] &= ~bitPosition;
            }
        }
        return false;
    }
    else
    {
        if (solve(board, next_i, next_j))
            return true;
    }
    return false;
}

bool solveSudoku(std::vector<std::vector<int>>& board, int x, int y)
{
	memset(rows, 0, sizeof(rows));
	memset(cols, 0, sizeof(cols));
	memset(box, 0, sizeof(box));

	for (int i = 0; i < board.size(); ++i)
	{
		for (int j = 0; j < board[0].size(); ++j)
		{
			if (board[i][j] != 0)
			{
                int num = board[i][j];
				int bitPosition = 1 << (num - 1);
				int boxIndex = (i / 3) * 3 + j / 3;

				rows[i] |= bitPosition;
				cols[j] |= bitPosition;
				box[boxIndex] |= bitPosition;
			}
		}
	}

	return solve(board, x, y);
}

void printBoard(std::vector<std::vector<int>>& board)
{
    for (int row = 0; row < board.size(); row++)
    {
        for (int col = 0; col < board[0].size(); col++)
            std::cout << board[row][col] << " ";
        std::cout << std::endl;
    }
}

int main()
{
    // 0 means unassigned cells
    std::vector<std::vector<int>> board = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                                            { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                                            { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                                            { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
                                            { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
                                            { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
                                            { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                                            { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                                            { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };
    if (solveSudoku(board, 0, 0))
        printBoard(board);
    else
        std::cout << "No solution exists";

    return 0;
}

