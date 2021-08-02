/* Given a grid with each cell consisting of positive, negative or no points i.e, zero points. 
We can move across a cell only if we have positive points ( > 0 ). Whenever we pass through a cell, 
points in that cell are added to our overall points. We need to find minimum initial points to reach 
cell (m-1, n-1) from (0, 0).

Constraints :

1. From a cell (i, j) we can move to (i+1, j) or (i, j+1).
2. We cannot move from (i, j) if your overall points at (i, j) is <= 0.
3. We have to reach at (n-1, m-1) with minimum positive points i.e., > 0.

Example:

Input: points[m][n] = { {-2, -3,   3},
                        {-5, -10,  1},
                        {10,  30, -5}
                      };
Output: 7

Explanation:
7 is the minimum value to reach destination with positive throughout the path. Below is the path.

(0,0) -> (0,1) -> (0,2) -> (1, 2) -> (2, 2)

We start from (0, 0) with 7, we reach(0, 1) with 5, (0, 2) with 2, (1, 2) with 5, (2, 2)
with and finally we have 1 point (we needed greater than 0 points at the end).
*/

#include <iostream>
#include <vector>

int minimumInitialPoints(std::vector<std::vector<int>>& points)
{
    int row = points.size();
    int column = points[0].size();

    std::vector<std::vector<int>> dp(row, std::vector<int>(column));

    dp[row - 1][column - 1] = points[row - 1][column - 1] > 0 ? 1 : abs(points[row - 1][column - 1]) + 1;

    for (int i = row - 2; i >= 0; i--)
        dp[i][column - 1] = std::max(dp[i + 1][column - 1] - points[i][column - 1], 1);
    for (int j = column - 2; j >= 0; j--)
        dp[row - 1][j] = std::max(dp[row - 1][j + 1] - points[row - 1][j], 1);

    for (int i = row - 2; i >= 0; i--)
    {
        for (int j = column - 2; j >= 0; j--)
        {
            int minPointsReq = std::min(dp[i + 1][j], dp[i][j + 1]);
            dp[i][j] = std::max(minPointsReq - points[i][j], 1);
        }
    }
    return dp[0][0];
}

int main()
{

    std::vector<std::vector<int>> points = { {-2,-3,3},
                                            {-5,-10,1},
                                            {10,30,-5} };

    std::cout << "Minimum Initial Points Required: " << minimumInitialPoints(points);
    return 0;
}


