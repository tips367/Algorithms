// Euler Circuit in a Directed Graph

#include <iostream>
#include <list>

class Graph
{
    int V;    
    std::list<int>* adj;    
    int* inDegree;
public:
    Graph(int V);
    ~Graph() 
    { 
        delete[] adj; 
        delete[] inDegree; 
    }

    void addEdge(int v, int w) 
    { 
        adj[v].push_back(w);  
        inDegree[w]++; 
    }

    bool isEulerianCycle();

    // Method to check if all non-zero degree vertices are connected
    bool isSC();

    void DFSUtil(int v, bool visited[]);

    Graph getTranspose();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new std::list<int>[V];
    inDegree = new int[V];
    for (int i = 0; i < V; i++)
        inDegree[i] = 0;
}

void Graph::DFSUtil(int v, bool visited[])
{
    visited[v] = true;

    std::list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}

Graph Graph::getTranspose()
{
    Graph* g = new Graph(V);
    for (int v = 0; v < V; v++)
    {
        // Recur for all the vertices adjacent to this vertex
        std::list<int>::iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            (*g).adj[*i].push_back(v);
            (*g).inDegree[v]++;
        }
    }
    return *g;
}

bool Graph::isSC()
{
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Find the first vertex with non-zero degree
    int n;
    for (n = 0; n < V; n++)
        if (adj[n].size() > 0)
            break;

    // Do DFS traversal starting from first non zero degrees vertex.
    DFSUtil(n, visited);

    // If DFS traversal doesn't visit all vertices, then return false.
    for (int i = 0; i < V; i++)
        if (adj[i].size() > 0 && visited[i] == false)
            return false;

    // Create a reversed graph
    Graph gr = getTranspose();

    // Mark all the vertices as not visited (For second DFS)
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Do DFS for reversed graph starting from first vertex.
    // Starting Vertex must be same starting point of first DFS
    gr.DFSUtil(n, visited);

    for (int i = 0; i < V; i++)
        if (adj[i].size() > 0 && visited[i] == false)
            return false;

    return true;
}

bool Graph::isEulerianCycle()
{
    // Check if all non-zero degree vertices are connected
    if (isSC() == false)
        return false;

    // Check if in degree and out degree of every vertex is same
    for (int i = 0; i < V; i++)
        if (adj[i].size() != inDegree[i])
            return false;

    return true;
}

int main()
{
    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 0);

    if (g.isEulerianCycle())
        std::cout << "Given directed graph is eulerian";
    else
        std::cout << "Given directed graph is NOT eulerian";
    return 0;
}