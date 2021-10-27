/* Given an array of strings, find if the given strings can be chained to form a circle. A string X can be put before another 
string Y in circle if the last character of X is same as first character of Y.

Input: arr[] = {"for", "geek", "rig", "kaf"}
Output: Yes, the given strings can be chained.
The strings can be chained as "for", "rig", "geek" and "kaf"

Input : arr[] = [“ijk”, “kji”, “abc”, “cba”]
Output : No

*/

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
    for (int i : adj[v])
    {
        if (!visited[i])
            DFSUtil(i, visited);
    }
}

Graph Graph::getTranspose()
{
    Graph* g = new Graph(V);
    for (int v = 0; v < V; v++)
    {
        for (int i : adj[v])
        {
            (*g).adj[i].push_back(v);
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
    {
        if (adj[n].size() > 0)
            break;
    }

    // Do DFS traversal starting from first non zero degrees vertex.
    DFSUtil(n, visited);

    // If DFS traversal doesn't visit all vertices, then return false.
    for (int i = 0; i < V; i++)
    {
        if (adj[i].size() > 0 && visited[i] == false)
            return false;
    }

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

bool canBeChained(std::string arr[], int n)
{
    Graph g(26);
    
    // Create an edge from first character to last character of every string
    for (int i = 0; i < n; i++)
    {
        std::string s = arr[i];
        g.addEdge(s[0] - 'a', s[s.length() - 1] - 'a');
    }

    // The given array of strings can be chained if there is an eulerian cycle in the created graph
    return g.isEulerianCycle();
}

int main()
{
    std::string arr1[] = { "for", "geek", "rig", "kaf" };
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    canBeChained(arr1, n1) ? std::cout << "Can be chained \n" : std::cout << "Can't be chained \n";

    std::string arr2[] = { "aab", "abb" };
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    canBeChained(arr2, n2) ? std::cout << "Can be chained \n" : std::cout << "Can't be chained \n";

    return 0;
}


