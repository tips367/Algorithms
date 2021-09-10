// Kruskal’s Minimum Spanning Tree

#include <iostream>
#include <vector>
#include <algorithm>

class Edge 
{
public:
    int src, dest, weight;
};

class Graph 
{
public:
    int V, E;
    std::vector<Edge> edge;
};

class subset 
{
public:
    int parent;
    int rank;
};

bool comparator(Edge a, Edge b)
{
    return a.weight < b.weight;
}

Graph* createGraph(int V, int E)
{
    Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;

    graph->edge.resize(E);

    return graph;
}

int find(subset subsets[], int i)
{
    // find root and make root as parent of i (path compression)
    if (subsets[i].parent == -1)
        return i;

    return subsets[i].parent = find(subsets, subsets[i].parent);
}

void Union(subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

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

void KruskalMST(Graph* graph)
{
    int V = graph->V;

    std::vector<Edge> mst;
   
    std::sort(graph->edge.begin(), graph->edge.end(), comparator);

    subset* subsets = new subset[V];

    // Create V subsets with single elements
    for (int v = 0; v < V; ++v)
    {
        subsets[v].parent = -1;
        subsets[v].rank = 0;
    }

    int e = 0;
    int i = 0;

    // Number of edges to be taken is equal to V-1
    while (e < V - 1 && i < graph->E)
    {
        // Pick the smallest edge. And increment the index for next iteration
        Edge nextEdge = graph->edge[i++];

        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        // If including this edge does't cause cycle, include it in result and increment the index
        // of result for next edge.
        if (x != y) 
        {
            mst.push_back(nextEdge);
            Union(subsets, x, y);
            e++;
        }
        // Else discard the nextEdge
    }

    std::cout << "Following are the edges in the constructed MST\n";

    int minimumCost = 0;
    for (i = 0; i < e; ++i)
    {
        std::cout << mst[i].src << " -- " << mst[i].dest << " wt = " << mst[i].weight << std::endl;
        minimumCost = minimumCost + mst[i].weight;
    }

    std::cout << "Minimum Cost Spanning Tree: " << minimumCost << std::endl;
}

int main()
{
    int V = 4; 
    int E = 5; 
    Graph* graph = createGraph(V, E);

    // add edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 10;

    // add edge 0-2
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 6;

    // add edge 0-3
    graph->edge[2].src = 0;
    graph->edge[2].dest = 3;
    graph->edge[2].weight = 5;

    // add edge 1-3
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 15;

    // add edge 2-3
    graph->edge[4].src = 2;
    graph->edge[4].dest = 3;
    graph->edge[4].weight = 4;

    KruskalMST(graph);

    return 0;
}


