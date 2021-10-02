/* Given a boolean 2D matrix, find the number of islands. A group of connected 1s forms an island. 
For example, the below matrix contains 5 islands
Example: 
 

Input : mat[][] = {{1, 1, 0, 0, 0},
                   {0, 1, 0, 0, 1},
                   {1, 0, 0, 1, 1},
                   {0, 0, 0, 0, 0},
                   {1, 0, 1, 0, 1}}
Output : 5
*/

#include <iostream>
#include <vector>

using namespace std;

// Time complexity : O(ROW x COL)

void DFS(vector<vector<int>>& grid, int i, int j)
{
    if (i < 0 || i >= size(grid) || j < 0 || j >= size(grid[0]) || grid[i][j] != 1)
        return;

    grid[i][j] = 0;
    DFS(grid, i + 1, j);
    DFS(grid, i, j - 1);
    DFS(grid, i, j + 1);
    DFS(grid, i - 1, j);
    DFS(grid, i + 1, j + 1);
    DFS(grid, i - 1, j - 1);
    DFS(grid, i + 1, j - 1);
    DFS(grid, i - 1, j + 1);
}

int numIslands(vector<vector<int>>& grid) 
{
    int m = size(grid);
    int n = size(grid[0]);

    int numIslands = 0;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (grid[i][j] == 1)
            {
                DFS(grid, i, j);
                ++numIslands;
            }
        }
    }
    return numIslands;
}

int main()
{
    vector<vector<int>> M = {{1, 1, 0, 0, 0},
                             {0, 1, 0, 0, 1},
                             {1, 0, 0, 1, 1},
                             {0, 0, 0, 0, 0},
                             {1, 0, 1, 0, 1} };

    cout << "Number of islands is: " << numIslands(M);
    return 0;
}
