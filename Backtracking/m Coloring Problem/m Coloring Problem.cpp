/* Given an undirected graph and a number m, determine if the graph can be coloured with at most m colours such 
that no two adjacent vertices of the graph are colored with the same color. Here coloring of a graph means 
the assignment of colors to all vertices. */

#include <iostream>

#define V 4

bool isSafe(int v, bool graph[V][V], int color[], int c)
{
    //checks whether the edge exists or not (i.e, graph[v][i] == 1). If exist then checks whether the color to
    // be filled in the new vertex is already used by its adjacent
    for (int i = 0; i < V; i++)
        if (graph[v][i] && c == color[i])
            return false;
    return true;
}

bool graphColoringUtil(bool graph[V][V], int m, int color[], int vertex)
{
    // If all vertices are assigned a color then return true
    if (vertex == V)
        return true;

    // Consider this vertex v and try different colors
    for (int c = 1; c <= m; c++)
    {
        if (isSafe(vertex, graph, color, c))
        {
            color[vertex] = c;

            // recur to assign colors to rest of the vertices
            if (graphColoringUtil(graph, m, color, vertex + 1))
                return true;

            // If assigning color c doesn't lead to a solution then remove it
            color[vertex] = 0;
        }
    }

    // If no color can be assigned to this vertex then return false
    return false;
}

void graphColoring(bool graph[V][V], int m)
{
    int color[V];
    for (int i = 0; i < V; i++)
        color[i] = 0;

    if (graphColoringUtil(graph, m, color, 0))
    {
        std::cout << "Solution Exists: Following are the assigned colors\n";
        for (int i = 0; i < V; i++)
            std::cout << color[i] << " ";
    }
    else
        std::cout << "Solution does not exist"; 
}

int main()
{

    /* Create following graph and test whether it is 3 colorable
      (3)---(2)
       |   / |
       |  /  |
       | /   |
      (0)---(1)
    */
    bool graph[V][V] = { { 0, 1, 1, 1 },
                         { 1, 0, 1, 0 },
                         { 1, 1, 0, 1 },
                         { 1, 0, 1, 0 }, };

    // Number of colors
    int m = 3;
    graphColoring(graph, m);
    return 0;
}
