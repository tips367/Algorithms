// Eulerian path and circuit for undirected graph

#include <iostream>
#include <list>
#include <vector>

class Graph
{
    int V;    
    std::list<int>* adj;  

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

    int isEulerian();

    // Method to check if all non-zero degree vertices are connected
    bool isConnected();

    void DFSUtil(int v, std::vector<bool>& visited);
};

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);  
}

void Graph::DFSUtil(int v, std::vector<bool>& visited)
{
    visited[v] = true;

    // Recur for all the vertices adjacent to this vertex
    std::list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}

bool Graph::isConnected()
{
    std::vector<bool> visited(V, false);

    int node = -1;	// Node to start DFS

    for (int i = 0; i < V; ++i)
    {
        if (adj[i].size() > 0)
        {
            node = i;	// Found a node to start DFS
            break;
        }
    }

    // No start node was found-->No edges are present in graph
    // It's always Eulerian
    if (node == -1)	
        return true; 

    // Start DFS traversal from a vertex with non-zero degree
    DFSUtil(node, visited);

    // Check if all non-zero degree vertices are visited
    for (int i = 0; i < V; i++)
        // We have edges in multi-component
        if (visited[i] == false && adj[i].size() > 0)
            return false;
    return true;
}

/* The function returns one of the following values
   0 --> If graph is not Eulerian
   1 --> If graph has an Euler path (Semi-Eulerian)
   2 --> If graph has an Euler Circuit (Eulerian)  
*/
int Graph::isEulerian()
{
    // Check if all non-zero degree vertices are connected
    if (isConnected() == false)
        return 0;

    // Count vertices with odd degree
    int odd = 0;
    for (int i = 0; i < V; i++)
        if (adj[i].size() & 1)
            odd++;

    // If count is more than 2, then graph is not Eulerian
    if (odd > 2)
        return 0;

    // If odd count is 2, then semi-eulerian.
    // If odd count is 0, then eulerian
    // Note that odd count can never be 1 for undirected graph
    return (odd) ? 1 : 2;
}

// Function to run test cases
void test(Graph& g)
{
    int res = g.isEulerian();
    if (res == 0)
        std::cout << "Graph is not Eulerian\n";
    else if (res == 1)
        std::cout << "Graph has a Euler path\n";
    else
        std::cout << "Graph has a Euler cycle\n";
}

int main()
{
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    test(g1);

    Graph g2(5);
    g2.addEdge(1, 0);
    g2.addEdge(0, 2);
    g2.addEdge(2, 1);
    g2.addEdge(0, 3);
    g2.addEdge(3, 4);
    g2.addEdge(4, 0);
    test(g2);

    Graph g3(5);
    g3.addEdge(1, 0);
    g3.addEdge(0, 2);
    g3.addEdge(2, 1);
    g3.addEdge(0, 3);
    g3.addEdge(3, 4);
    g3.addEdge(1, 3);
    test(g3);

    Graph g4(3);
    g4.addEdge(0, 1);
    g4.addEdge(1, 2);
    g4.addEdge(2, 0);
    test(g4);

    Graph g5(3);
    test(g5);

    return 0;
}