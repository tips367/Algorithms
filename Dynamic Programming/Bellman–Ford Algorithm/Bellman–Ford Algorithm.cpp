/* Given a graph and a source vertex src in graph, find shortest paths from src to all vertices in the given graph. 
The graph may contain negative weight edges. 

                           2
                  >(B)---------->(E)
                 /  |/\ \         /  
             -1 /   |  \ \ 2     /-3  
               /   3|  1\ \     /    
              /    \|/   \ \/ \/ 
            (A)--->(C)<----(D)
                4        5
*/

#include <iostream>

struct Edge 
{
    int src, dest, weight;
};

struct Graph 
{
    // V-> Number of vertices, E-> Number of edges
    int V, E;

    // graph is represented as an array of edges.
    struct Edge* edge;
};

struct Graph* createGraph(int V, int E)
{
    struct Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
}

void printArr(int dist[], int n)
{
    std::cout << "Vertex    Distance from Source\n";
    for (int i = 0; i < n; ++i)
        std::cout<< i << "\t\t" << dist[i] << std::endl;
}

void bellmanFord(struct Graph* graph, int source)
{
    int V = graph->V;
    int E = graph->E;
    int* distance = new int[V];     // Keeps shortest path values to each vertex from source

    // Step 1: Initialize distances from src to all other vertices as INFINITE
    for (int i = 0; i < V; i++)
        distance[i] = INT_MAX;
    distance[source] = 0;

    bool updated;
    // Step 2: Relax all edges |V| - 1 times. A simple shortest
    // path from src to any other vertex can have at-most |V| - 1 edges
    for (int i = 0; i < V - 1; i++)
    {
        updated = false;
        for (int j = 0; j < E; j++)
        {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int weight = graph->edge[j].weight;
            if (distance[u] != INT_MAX && distance[u] + weight < distance[v])
            {
                distance[v] = distance[u] + weight;
                updated = true;
            }
        }
        if (updated == false)
            break;
    }

    // Step 3: check for negative-weight cycles.  The above step guarantees shortest distances if graph doesn't contain
    // negative weight cycle.  If we get a shorter path, then there is a cycle.
    for (int i = 0; i < E; i++) 
    {
        int u = graph->edge[i].src;
        int v = graph->edge[i].dest;
        int weight = graph->edge[i].weight;
        if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) 
        {
            std::cout << "Graph contains negative weight cycle";
            return; 
        }
    }

    printArr(distance, V);

 }

int main()
{
    /* Let us create the following graph
                           2
                  >(B)---------->(E)
                 /  |/\ \         /  
             -1 /   |  \ \ 2     /-3  
               /   3|  1\ \     /    
              /    \|/   \ \/ \/ 
            (A)--->(C)<----(D)
                4        5
     */

    int V = 5; // Number of vertices in graph
    int E = 8; // Number of edges in graph
    struct Graph* graph = createGraph(V, E);

    // add edge 0-1 (or A-B in above figure)
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = -1;

    // add edge 0-2 (or A-C in above figure)
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 4;

    // add edge 1-2 (or B-C in above figure)
    graph->edge[2].src = 1;
    graph->edge[2].dest = 2;
    graph->edge[2].weight = 3;

    // add edge 1-3 (or B-D in above figure)
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 2;

    // add edge 1-4 (or A-E in above figure)
    graph->edge[4].src = 1;
    graph->edge[4].dest = 4;
    graph->edge[4].weight = 2;

    // add edge 3-2 (or D-C in above figure)
    graph->edge[5].src = 3;
    graph->edge[5].dest = 2;
    graph->edge[5].weight = 5;

    // add edge 3-1 (or D-B in above figure)
    graph->edge[6].src = 3;
    graph->edge[6].dest = 1;
    graph->edge[6].weight = 1;

    // add edge 4-3 (or E-D in above figure)
    graph->edge[7].src = 4;
    graph->edge[7].dest = 3;
    graph->edge[7].weight = -3;

    bellmanFord(graph, 0);

    return 0;
}


