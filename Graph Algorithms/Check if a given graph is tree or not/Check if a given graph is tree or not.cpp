/* Write a function that returns true if a given undirected graph is tree and false otherwise. 

For example, the following graph is a tree.

            1------0------3
                 /        |
                /         |
               /          |
             2            4

But the following graph is not a tree.

            1------0------3
            |    /        |
            |   /         |
            |  /          |
             2            4
*/

#include <iostream>
#include <list>

class Graph
{
public:
    Graph(int V);
    void addEdge(int v, int w);
    bool isTree();
private:
    int V;
    std::list<int>* adj;    // Pointer to an array containing adjacency lists
    bool isCyclicRecur(int v, bool visited[], int parent);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new std::list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

bool Graph::isCyclicRecur(int v, bool visited[], int parent)
{
    // Mark the current node as visited
    visited[v] = true;

    for (auto i = adj[v].begin(); i != adj[v].end(); i++)
    {
        if (!visited[*i])
        {
            if (isCyclicRecur(*i, visited, v))
                return true;
        }
        // If an adjacent vertex is visited and is not parent of current vertex,
        // then there exists a cycle in the graph.
        else if (*i != parent)
            return true;
    }
    return false;
}

bool Graph::isTree()
{
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // The call to isCyclicRecur serves two purposes.
    // It returns true if graph reachable from vertex 0 is cyclcic. It also marks all vertices reachable from 0.
    if (isCyclicRecur(0, visited, -1))
        return false;

    // If we find a vertex which is not reachable from 0 (not marked by isCyclicRecur(), then we return false
    for (int i = 0; i < V; i++)
        if (!visited[i])
            return false;

    return true;
}

int main()
{
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.isTree() ? std::cout << "Graph is Tree\n" : std::cout << "Graph is not a Tree\n";

    Graph g2(5);
    g2.addEdge(1, 0);
    g2.addEdge(0, 2);
    g2.addEdge(2, 1);
    g2.addEdge(0, 3);
    g2.addEdge(3, 4);
    g2.isTree() ? std::cout << "Graph is Tree\n" : std::cout << "Graph is not a Tree\n";

    return 0;
}
