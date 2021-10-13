// Travelling Salesman Problem (TSP)

#include <iostream>
#include <vector>
#include <algorithm>

#define V 4

int VISITED_ALL = (1 << V) - 1;

// Method 1 : Naive...Time complexity : O(n!)
/*
int travellingSalesmanProblem(int graph[][V], int s)
{
    // store all vertex apart from source vertex
    std::vector<int> vertex;
    for (int i = 0; i < V; i++)
        if (i != s)
            vertex.push_back(i);

    // store minimum weight Hamiltonian Cycle.
    int minPath = INT_MAX;
    do
    {
        int currentPathWeight = 0;
        int k = s;
        for (int i = 0; i < vertex.size(); i++)
        {
            currentPathWeight += graph[k][vertex[i]];
            k = vertex[i];
        }
        currentPathWeight += graph[k][s];
        minPath = std::min(minPath, currentPathWeight);

    } while (next_permutation(vertex.begin(), vertex.end()));

    return minPath;
}

int main()
{
    // matrix representation of graph
    int graph[][V] = { { 0, 10, 15, 20 },
                       { 10, 0, 35, 25 },
                       { 15, 35, 0, 30 },
                       { 20, 25, 30, 0 } };
    int s = 0;
    std::cout << travellingSalesmanProblem(graph, s) << std::endl;
    return 0;
} */

// Method 2 : Using Dynamic programming...Time complexity : O(n^2*2^n)
int travellingSalesmanProblem(int graph[][V], int mask, int pos, std::vector<std::vector<int>>& dp)
{
    if (mask == VISITED_ALL)
        return graph[pos][0];

    if (dp[mask][pos] != -1)
        return dp[mask][pos];

    //Now from current node, we will try to go to every other node and take the min ans
    int ans = INT_MAX;

    //Visit all the unvisited cities and take the best route
    for (int city = 0; city < V; city++)
    {
        if ((mask & (1 << city)) == 0)
        {
            int newAns = graph[pos][city] + travellingSalesmanProblem(graph, mask | (1 << city), city, dp);
            ans = std::min(ans, newAns);
        }
    }
    return dp[mask][pos] = ans;
}

int main()
{
    // matrix representation of graph
    int graph[][V] = {{0, 20, 42, 25},
                      {20, 0, 30, 34},
                      {42, 30, 0, 10},
                      {25, 34, 10, 0}};

    std::vector<std::vector<int>> dp(V * V, std::vector<int>(V, -1));
    std::cout << travellingSalesmanProblem(graph, 1, 0, dp) << std::endl;
    return 0;
}
