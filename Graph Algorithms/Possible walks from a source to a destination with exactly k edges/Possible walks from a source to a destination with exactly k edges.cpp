/* Given a directed graph and two vertices ‘u’ and ‘v’ in it, count all possible walks from ‘u’ to ‘v’ with exactly k edges on the walk. */

#include <iostream>
#include <vector>

using namespace std;

#define V 4

// Method 1. Time complexity : O(V ^ k)
/*
int countWalks(int graph[][V], int u, int v, int k)
{
    if (k == 0 && u == v)
        return 1;
    if (k == 1 && graph[u][v])
        return 1;
    if (k <= 0)
        return 0;

    int count = 0;

    // Go to all adjacents of u and recur
    for (int i = 0; i < V; i++)
    {
        // Check if is adjacent of u
        if(graph[u][i] == 1)
            count += countWalks(graph, i, v, k - 1);
    }
    return count;
} */

// Method 2. Using Dynamic programming...Time complexity : O(V ^ 3), Space : O(V ^ 3)
int countWalks(int graph[][V], int u, int v, int k)
{
    vector<vector<vector<int>>> count(V, vector<vector<int>>(V, vector<int>(k+1)));

    // Loop for number of edges from 0 to k
    for (int e = 0; e <= k; e++)
    {
        // for source
        for (int i = 0; i < V; i++)
        {
            // for destination
            for (int j = 0; j < V; j++)
            {
                count[i][j][e] = 0;

                if (e == 0 && i == j)
                    count[i][j][e] = 1;
                if (e == 1 && graph[i][j])
                    count[i][j][e] = 1;

                if (e > 1)
                {
                    for (int x = 0; x < V; x++)
                        if (graph[i][x])
                            count[i][j][e] += count[x][j][e - 1];
                }
            }
        }
    }
    return count[u][v][k];
}

int main()
{
    int graph[V][V] = { { 0, 1, 1, 1 },
                        { 0, 0, 0, 1 },
                        { 0, 0, 0, 1 },
                        { 0, 0, 0, 0 } };

    int u = 0, v = 3, k = 2;
    std::cout << countWalks(graph, u, v, k);
    return 0;
}


