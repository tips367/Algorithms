// Detect Cycle in an Undirected Graph using Disjoint Set

#include <iostream>

class Edge
{
public:
    int src, dest;
};

class Graph
{
public:
    int V, E;
    Edge* edge;
};

Graph* createGraph(int V, int E)
{
    Graph* graph = new Graph();
    graph->V = V;
    graph->E = E;

    graph->edge = new Edge[graph->E * sizeof(Edge)];

    return graph;
}

// Method 1 : Simple

/*
// A utility function to find the subset of an element i
int find(int parent[], int i)
{
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

// A utility function to do union of two subsets
void Union(int parent[], int x, int y)
{
    parent[x] = y;
}

bool isCycle(Graph* graph)
{
    int* parent = new int[graph->V * sizeof(int)];

    // Initialize all subsets as single element sets
    memset(parent, -1, sizeof(int) * graph->V);

    // Iterate through all edges of graph, find subset of both vertices of every edge, if both subsets are
    // same, then there is cycle in graph.
    for (int i = 0; i < graph->E; i++) 
    {
        int x = find(parent, graph->edge[i].src);
        int y = find(parent, graph->edge[i].dest);

        if (x == y)
            return true;

        Union(parent, x, y);
    }
    return false;
} */

// Method 2 : Optimized using union by rank and path compression
class subset 
{
public:
    int parent;
    int rank;
};

int find(subset subsets[], int i)
{
    // find root and make root as parent of i (path compression)
    if (subsets[i].parent == -1)
        return i;
       
    return subsets[i].parent = find(subsets, subsets[i].parent);
}

void Union(subset subsets[], int xroot, int yroot)
{
    // Attach smaller rank tree under root of high rank tree (Union by Rank)
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    // If ranks are same, then make one as root and increment its rank by one
    else 
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

bool isCycle(Graph* graph)
{
    int V = graph->V;
    int E = graph->E;

    subset* subsets = new subset[V];

    for (int v = 0; v < V; ++v) 
    {
        subsets[v].parent = -1;
        subsets[v].rank = 0;
    }

    // Iterate through all edges of graph, find sets of both vertices of every edge, if sets are same, then there
    // is cycle in graph.
    for (int e = 0; e < E; ++e) 
    {
        int x = find(subsets, graph->edge[e].src);
        int y = find(subsets, graph->edge[e].dest);

        if (x == y)
            return true;

        Union(subsets, x, y);
    }
    return false;
}

int main()
{
    /* Let us create the following graph
        0
        | \
        |  \
        1---2 
    */

    int V = 3, E = 3;
    Graph* graph = createGraph(V, E);

    // add edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;

    // add edge 1-2
    graph->edge[1].src = 1;
    graph->edge[1].dest = 2;

    // add edge 0-2
    graph->edge[2].src = 0;
    graph->edge[2].dest = 2;

    if (isCycle(graph))
        std::cout << "Graph contains cycle";
    else
        std::cout << "Graph doesn't contain cycle";

    return 0;
}