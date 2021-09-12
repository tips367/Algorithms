/* The Floyd Warshall Algorithm is for solving the All Pairs Shortest Path problem. The problem is to find shortest distances
between every pair of vertices in a given edge weighted directed Graph.

Example :

Input:
       graph[][] = { {0,   5,  INF, 10},
                    {INF,  0,  3,  INF},
                    {INF, INF, 0,   1},
                    {INF, INF, INF, 0} }
which represents the following graph
             10
       (0)------->(3)
        |         /|\
      5 |          |
        |          | 1
       \|/         |
       (1)------->(2)
            3
Note that the value of graph[i][j] is 0 if i is equal to j
And graph[i][j] is INF (infinite) if there is no edge from vertex i to j.

Output:
Shortest distance matrix
      0      5      8      9
    INF      0      3      4
    INF    INF      0      1
    INF    INF    INF      0
*/

// Number of vertices in the graph  
#define V 4 
#define INF INT_MAX 
#include <iostream>
#include <vector>

void printShortestDistanceMatrix(std::vector<std::vector<int>> const& distance);
void printShortestDistancePath(std::vector<std::vector<int>> const& path);

void floydWarshall(int graph[][V])
{
    // distance[][] will be the output matrix that will finally have the shortest distances between every pair of vertices
    std::vector<std::vector<int>> distance(V, std::vector<int>(V)); // similar to distance[V][V];
    std::vector<std::vector<int>> path(V, std::vector<int>(V));

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            // initially distance would be same as weight of the edge
            distance[i][j] = graph[i][j];

            if (i == j)
                path[i][j] = 0;
            else if (distance[i][j] != INF)
                path[i][j] = i;
            else
                path[i][j] = -1;
        }
    }
    // Add all vertices one by one to the set of intermediate vertices.
    // ---> Before start of an iteration, we have shortest distances between all pairs of vertices such that the
    // shortest distances consider only the vertices in set {0, 1, 2, .. k-1} as intermediate vertices.

    // ----> After the end of an iteration, vertex no. k is added to the set of intermediate vertices and the set becomes {0, 1, 2, .. k}
    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (distance[i][k] != INF && distance[k][j] != INF)     // to avoid overflow
                    if (distance[i][k] + distance[k][j] < distance[i][j])
                    {
                        distance[i][j] = distance[i][k] + distance[k][j];
                        path[i][j] = path[k][j];
                    }
            }
            // if diagonal elements become negative, the graph contains a negative weight cycle
            if (distance[i][i] < 0)
            {
                std::cout << "Negative Weight Cycle Found!!";
                return;
            }
        }
    }
    printShortestDistanceMatrix(distance);
    printShortestDistancePath(path);
}

void printShortestDistanceMatrix(std::vector<std::vector<int>> const& distance)
{

    std::cout << "The following matrix shows the shortest distances between every pair of vertices \n";
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (distance[i][j] == INF)
                std::cout << "INF" << " ";
            else
                std::cout << distance[i][j] << "   ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

// Recursive Function to print path of given vertex j from source vertex i
void printPath(std::vector<std::vector<int>> const& path, int i, int j)
{
    if (path[i][j] == i)
        return;

    printPath(path, i, path[i][j]);
    std::cout << path[i][j] << " ";
}

void printShortestDistancePath(std::vector<std::vector<int>> const& path)
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (i != j && path[i][j] != -1)
            {
                std::cout << "Shortest Path from " << i << " -> " << j << " is (" << i << " ";
                printPath(path, i, j);
                std::cout << j << ")" << std::endl;
            }
        }
    }
}

// Driver code  
int main()
{
    /* Let us create the following weighted graph
              10
       (0)------->(3)
        |         /|\
      5 |          |
        |          | 1
       \|/         |
       (1)------->(2)
            3             */

    int graph[V][V] = { {0, 5, INF, 10},
                        {INF, 0, 3, INF},
                        {INF, INF, 0, 1},
                        {INF, INF, INF, 0} };
    floydWarshall(graph);
    return 0;
}
