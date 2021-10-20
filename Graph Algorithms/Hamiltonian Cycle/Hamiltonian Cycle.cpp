/* Hamiltonian Path in an undirected graph is a path that visits each vertex exactly once. A Hamiltonian cycle
(or Hamiltonian circuit) is a Hamiltonian Path such that there is an edge (in the graph) from the last vertex to
the first vertex of the Hamiltonian Path. Determine whether a given graph contains Hamiltonian Cycle or not.
If it contains, then prints the path.

For example, a Hamiltonian Cycle in the following graph is {0, 1, 2, 4, 3, 0}.

(0)--(1)--(2)
 |   / \   |
 |  /   \  |
 | /     \ |
(3)-------(4)

And the following graph doesn’t contain any Hamiltonian Cycle.

(0)--(1)--(2)
 |   / \   |
 |  /   \  |
 | /     \ |
(3)      (4)
*/

#define V 5

#include <iostream>

bool isSafe(int v, bool graph[V][V], int path[], int pos)
{
    // Check if this vertex is an adjacent vertex of the previously added vertex
    if (graph[path[pos - 1]][v] == 0)
        return false;

    // Check if the vertex has already been included
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

bool hamiltonianCycleUtil(bool graph[V][V], int path[], int pos)
{
    //If all vertices are included in Hamiltonian Cycle
    if (pos == V)
    {
        // And if there is an edge from the last included vertex to the first vertex
        if (graph[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }

    // Try different vertices as a next candidate in Hamiltonian Cycle. We don't try for 0 as
    // we included 0 as starting point in hamCycle()
    for (int v = 1; v < V; v++)
    {
        // Check if this vertex can be added to Hamiltonian Cycle
        if (isSafe(v, graph, path, pos))
        {
            path[pos] = v;

            // recur to construct rest of the path
            if (hamiltonianCycleUtil(graph, path, pos + 1) == true)
                return true;

            // If adding vertex v doesn't lead to a solution, then remove it
            path[pos] = -1;
        }
    }

    // If no vertex can be added to Hamiltonian Cycle constructed so far
    return false;
}

void printSolution(int path[])
{
    std::cout << "Solution Exists: Following is one Hamiltonian Cycle \n";
    for (int i = 0; i < V; i++)
        std::cout << path[i] << " ";

    // Print the first vertex again to show the complete cycle
    std::cout << path[0] << " \n";
}

void hamiltonianCycle(bool graph[][V])
{
    int* path = new int[V];
    for (int i = 0; i < V; i++)
        path[i] = -1;

    path[0] = 0;
    if (hamiltonianCycleUtil(graph, path, 1))
        printSolution(path);
    else
        std::cout << "\nSolution does not exist";
}

int main()
{
    /* Create the following graph
       (0)--(1)--(2)
        |   / \   |
        |  /   \  |
        | /     \ |
       (3)-------(4)
    */

    bool graph1[V][V] = { {0, 1, 0, 1, 0},
                          {1, 0, 1, 1, 1},
                          {0, 1, 0, 0, 1},
                          {1, 1, 0, 0, 1},
                          {0, 1, 1, 1, 0} };

    hamiltonianCycle(graph1);

    /* Create the following graph
       (0)--(1)--(2)
        |   / \   |
        |  /   \  |
        | /     \ |
       (3)       (4)
    */

    bool graph2[V][V] = { {0, 1, 0, 1, 0},
                          {1, 0, 1, 1, 1},
                          {0, 1, 0, 0, 1},
                          {1, 1, 0, 0, 0},
                          {0, 1, 1, 0, 0} };

    hamiltonianCycle(graph2);

    return 0;
}


