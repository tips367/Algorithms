/* Given a directed graph, find out whether the graph is strongly connected or not. A directed graph is strongly connected 
there is a path in each direction between each pair of vertices of the graph. */

#include <iostream>
#include <list>
#include <stack>
#include <vector>

class Graph
{
    int V;    
    std::list<int>* adj; 

    void DFSUtil(int v, std::vector<bool>& visited);
public:
    Graph(int V) 
    { 
        this->V = V;  
        adj = new std::list<int>[V]; 
    }

    ~Graph() 
    { 
        delete[] adj; 
    }

    void addEdge(int v, int w);
    bool isStronglyConnected();

    // Function that returns reverse (or transpose) of this graph
    Graph getTranspose();
};

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::DFSUtil(int v, std::vector<bool>& visited)
{
    visited[v] = true;

    for (auto i : adj[v])
        if (!visited[i])
            DFSUtil(i, visited);
}

Graph Graph::getTranspose()
{
    Graph* g = new Graph(V);

    for (int v = 0; v < V; v++)
    {
        // Recur for all the vertices adjacent to this vertex
        for (auto i : adj[v])
        {
            (*g).adj[i].push_back(v);
        }
    }
    return *g;
}

bool Graph::isStronglyConnected()
{
    std::vector<bool> visited(V, false);

    // Do DFS traversal starting from first vertex.
    DFSUtil(0, visited);

    // If DFS traversal doesn’t visit all vertices, then return false.
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            return false;

    // Create a reversed graph
    Graph revGraph = getTranspose();

    // Mark all the vertices as not visited (For second DFS)
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Do DFS for reversed graph starting from first vertex.
    // Staring Vertex must be same starting point of first DFS
    revGraph.DFSUtil(0, visited);

    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            return false;

    return true;
}

int main()
{
    Graph g1(5);
    g1.addEdge(0, 1);
    g1.addEdge(1, 2);
    g1.addEdge(2, 3);
    g1.addEdge(3, 0);
    g1.addEdge(2, 4);
    g1.addEdge(4, 2);
    g1.isStronglyConnected() ? std::cout << "Yes\n" : std::cout << "No\n";

    Graph g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
    g2.isStronglyConnected() ? std::cout << "Yes\n" : std::cout << "No\n";

    return 0;
}