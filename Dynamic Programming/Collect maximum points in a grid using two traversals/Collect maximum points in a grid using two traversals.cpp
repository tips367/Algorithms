/* Given a matrix where every cell represents points. How to collect maximum points using two traversals under following 
conditions:

Let the dimensions of given grid be R x C.
1) The first traversal starts from top left corner, i.e., (0, 0) and should reach left bottom corner, 
i.e., (R-1, 0). The second traversal starts from top right corner, i.e., (0, C-1) and should reach bottom 
right corner, i.e., (R-1, C-1)
2) From a point (i, j), we can move to (i+1, j+1) or (i+1, j-1) or (i+1, j)
3) A traversal gets all points of a particular cell through which it passes. If one traversal has already collected 
points of a cell, then the other traversal gets no points if goes through that cell again.

Example:

Input :
    int arr[R][C] = {{3, 6,  8,  2},
                     {5, 2,  4,  3},
                     {1, 1, 20, 10},
                     {1, 1, 20, 10},
                     {1, 1, 20, 10},
                    };

     Output: 73

Explanation :

First traversal collects total points of value 3 + 2 + 20 + 1 + 1 = 27

Second traversal collects total points of value 2 + 4 + 10 + 20 + 10 = 46.
Total Points collected = 27 + 46 = 73.
*/

#include <iostream>
#include <vector>

#define R 5
#define C 4

bool isValid(int x, int y1, int y2)
{
    return (x >= 0 && x < R && y1 >= 0 && y1 < C && y2 >= 0 && y2 < C);
}

int getMaxUtil(int arr[R][C], int mem[R][C][C], int x, int y1, int y2)
{
    // if invalid cell
    if (!isValid(x, y1, y2))
        return INT_MIN;

    // if both traversals reach their destinations
    if (x == R - 1 && y1 == 0 && y2 == C - 1)
        return (y1 == y2) ? arr[x][y1] : arr[x][y1] + arr[x][y2];

    // If both traversals are at last row but not at their destinations
    if (x == R - 1)
        return INT_MIN;

    // if subproblem already solved
    if (mem[x][y1][y2] != -1) 
        return mem[x][y1][y2];

    // Initialize answer for this subproblem
    int result = INT_MIN;

    int currentCellGains = (y1 == y2) ? arr[x][y1] : arr[x][y1] + arr[x][y2];

    // Recur for all possible cases, then store and return the one with max value 
    result = std::max(result, currentCellGains + getMaxUtil(arr, mem, x + 1, y1, y2));
    result = std::max(result, currentCellGains + getMaxUtil(arr, mem, x + 1, y1, y2 - 1));
    result = std::max(result, currentCellGains + getMaxUtil(arr, mem, x + 1, y1, y2 + 1));

    result = std::max(result, currentCellGains + getMaxUtil(arr, mem, x + 1, y1 - 1, y2));
    result = std::max(result, currentCellGains + getMaxUtil(arr, mem, x + 1, y1 - 1, y2 - 1));
    result = std::max(result, currentCellGains + getMaxUtil(arr, mem, x + 1, y1 - 1, y2 + 1));

    result = std::max(result, currentCellGains + getMaxUtil(arr, mem, x + 1, y1 + 1, y2));
    result = std::max(result, currentCellGains + getMaxUtil(arr, mem, x + 1, y1 + 1, y2 - 1));
    result = std::max(result, currentCellGains + getMaxUtil(arr, mem, x + 1, y1 + 1, y2 + 1));

    return (mem[x][y1][y2] = result);
}

int geMaxCollection(int arr[R][C])
{
    // Create a memoization table and initialize all entries as -1
    int mem[R][C][C];
    memset(mem, -1, sizeof(mem));

    return getMaxUtil(arr, mem, 0, 0, C - 1);
}

int main()
{
    int arr[R][C] = {{3, 6,  8,  2},
                     {5, 2,  4,  3},
                     {1, 1, 20, 10},
                     {1, 1, 20, 10},
                     {1, 1, 20, 10},
    };

    std::cout << "Maximum collection is " << geMaxCollection(arr);
    return 0;
}

