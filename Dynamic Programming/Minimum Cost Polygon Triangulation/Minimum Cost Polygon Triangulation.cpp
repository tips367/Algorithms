/* A triangulation of a convex polygon is formed by drawing diagonals between non-adjacent vertices (corners) such 
that the diagonals never intersect. The problem is to find the cost of triangulation with the minimum cost. 
The cost of a triangulation is sum of the weights of its component triangles. Weight of each triangle is its 
perimeter (sum of lengths of all sides)
*/

#include <iostream>
#include <vector>

struct Point
{
    int x, y;
};

double min(double x, double y)
{
    return (x <= y) ? x : y;
}

double distance(Point p1, Point p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

// A utility function to find cost of a triangle. The cost is considered
// as perimeter (sum of lengths of all edges) of the triangle
double cost(Point points[], int i, int j, int k)
{
    Point p1 = points[i], p2 = points[j], p3 = points[k];
    return distance(p1, p2) + distance(p2, p3) + distance(p3, p1);
}

// Method 1: Recursive
/*
double minimumCost(Point points[], int i, int j)
{
    // There must be at least three points between i and j (including i and j)
    if (j < i + 2)
        return 0;

    double res = INT_MAX;

    // Find minimum triangulation by considering all
    for (int k = i + 1; k < j; k++)
        res = min(res, (minimumCost(points, i, k) + minimumCost(points, k, j) + cost(points, i, k, j)));
    return  res;
} */

// Method 2: Dynamic programming...Time complexity : O(n^3)
double minimumCost(Point points[], int n)
{
    // There must be at least 3 points to form a triangle
    if (n < 3)
        return 0;
 
    // dp[i][j] stores cost of triangulation of points from i to j.
    std::vector<std::vector<double>> dp(n, std::vector<double>(n));

    for (int i = 0; i < n; i++)
        dp[i][i] = 0.0;

    for (int i = 0; i < n - 1; i++)
    {
        dp[i][i + 1] = 0.0;
    }

    for (int L = 3; L <= n; L++)
    {
        for (int i = 0; i < n - L + 1; i++)
        {
            int j = i + L - 1;
            dp[i][j] = INT_MAX;
            for (int k = i + 1; k < j; k++)
            {
                double val = dp[i][k] + dp[k][j] + cost(points, i, j, k);
                if (dp[i][j] > val)
                    dp[i][j] = val;
            }
        }
    }
    return  dp[0][n - 1];
}

int main()
{
    Point points[] = { {0, 0}, {1, 0}, {2, 1}, {1, 2}, {0, 2} };
    int n = sizeof(points) / sizeof(points[0]);
    // std::cout << minimumCost(points, 0, n - 1);  // for method 1
    std::cout << minimumCost(points, n);
    return 0;
}

