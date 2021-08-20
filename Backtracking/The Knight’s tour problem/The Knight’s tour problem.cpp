/* Given a N*N board with the Knight placed on the first block of an empty board. Moving according to the rules 
of chess knight must visit each square exactly once. Print the order of each the cell in which they are visited.

Example:

Input : 
N = 8

Output:
0  59  38  33  30  17   8  63
37  34  31  60   9  62  29  16
58   1  36  39  32  27  18   7
35  48  41  26  61  10  15  28
42  57   2  49  40  23   6  19
47  50  45  54  25  20  11  14
56  43  52   3  22  13  24   5
51  46  55  44  53   4  21  12

*/

#include <iostream>

// `N × N` chessboard
#define N 8

// Below arrays detail all eight possible movements for a knight.
// It is important to avoid changing the sequence of the below arrays
int row[] = { 2, 1, -1, -2, -2, -1, 1, 2};
int col[] = { 1, 2, 2, 1, -1, -2, -2, -1};

bool isValid(int x, int y)
{
    if (x < 0 || y < 0 || x >= N || y >= N)
        return false;
    return true;
}

void printSolution(int visited[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++) 
        {
            std::cout << visited[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

bool knightTour(int visited[N][N], int i, int j, int position)
{
    // mark the current square as visited
    visited[i][j] = position;

    // if all squares are visited, print the solution
    if (position == N * N)
        return true;

    // check for all eight possible movements for a knight and recur for each valid movement
    for (int k = 0; k < 8; k++)
    {
        // get the new position of the knight from the current position on the chessboard
        int newX = i + row[k];
        int newY = j + col[k];

        // if the new position is valid and not visited yet
        if (isValid(newX, newY) && visited[newX][newY] == -1) 
        {
            if (knightTour(visited, newX, newY, position + 1))
                return true;
        }
    }

    // backtrack from the current square and remove it from the current path
    visited[i][j] = -1;
    return false;
}

int main()
{
    // `visited[][]` serves two purposes:
    // 1. It keeps track of squares involved in the knight's tour.
    // 2. It stores the order in which the squares are visited.
    int visited[N][N];

    // initialize `visited[][]` by 0 (unvisited)
    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++)
            visited[x][y] = -1;

    int pos = 0;

    // start knight tour from corner square `(0, 0)`
    if (knightTour(visited, 0, 0, pos))
        printSolution(visited);

    return 0;
}

