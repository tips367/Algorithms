/* A Maze is given as N*N binary matrix of blocks where source block is the upper left most block i.e., maze[0][0] 
and destination block is lower rightmost block i.e., maze[N-1][N-1]. A rat starts from source and has to reach the 
destination. The rat can move only in two directions: forward and down. 

In the maze matrix, 0 means the block is a dead end and 1 means the block can be used in the path from source to 
destination
*/

#include <iostream>

#define N 4

bool isSafe(int maze[][N], int x, int y)
{
    if (x >= 0 && y >= 0 && x < N && y < N && maze[x][y] == 1)
        return true;
    return false;
}

bool ratInMaze(int maze[][N], int x, int y, int soln[][N])
{
    if (x == N - 1 && y == N - 1 && maze[x][y] == 1)
    {
        soln[x][y] = 1;
        return true;
    }

    // Check if maze[x][y] is valid
    if (isSafe(maze, x, y) && soln[x][y] == 0)
    {
        // mark x, y as part of solution path
        soln[x][y] = 1;

        // Move forward in x direction
        if (ratInMaze(maze, x + 1, y, soln))
            return true;

        // If moving in x direction doesn't give solution then Move down in y direction
        if (ratInMaze(maze, x, y + 1, soln))
            return true;

        // Backtrack
        soln[x][y] = 0;
        return false;
    }
    return false;
}

void printMatrix(int matrix[][N])
{
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++)
            std::cout << matrix[i][j] << " ";
        std::cout << "\n";
    }
    std::cout << "\n";
}

int main()
{
    int maze[N][N] ={ { 1, 0, 0, 0 },
                      { 1, 1, 0, 1 },
                      { 0, 1, 0, 0 },
                      { 1, 1, 1, 1 } };

    std::cout << "Original Maze\n\n";
    printMatrix(maze);

    int soln[N][N] = { { 0, 0, 0, 0 },
                       { 0, 0, 0, 0 },
                       { 0, 0, 0, 0 },
                       { 0, 0, 0, 0 } };

    if (ratInMaze(maze, 0, 0, soln))
    {
        std::cout << "Solution Path\n\n";
        printMatrix(soln);
    }
    else
        std::cout << "Solution doesn't exist";
}


