// Travelling Salesman Problem (TSP)

#include <iostream>
#include <vector>
#include <algorithm>

#define V 4

// Method 1 : Naive...Time complexity : O(n!)
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
}


