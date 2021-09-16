/* Given a Directed Graph and two vertices in it, check whether there is a path from the first given vertex to second. */

#include <iostream>
#include <list>
#include <vector>
#include <queue>

class Graph
{
public:
    Graph(int V);  
    void addEdge(int v, int w); 
    bool isReachable(int s, int d);
private:
    int V;                  // No. of vertices
    std::list<int>* adj;    // Pointer to an array containing adjacency lists
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new std::list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}

bool Graph::isReachable(int s, int d)
{
    if (s == d)
        return true;

    std::vector<int> visited(V, false);

    std::queue<int> q;

    // Mark the current node as visited and enqueue it
    visited[s] = true;
    q.push(s);

    while (!q.empty())
    {
        s = q.front();
        q.pop();

        for (auto it : adj[s])
        {
            // If this adjacent node is the destination node, then return true
            if (it == d)
                return true;
            if (!visited[it])
            {
                visited[it] = true;
                q.push(it);
            }
        }
    }
    return false;
}

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    int u = 1, v = 3;

    if (g.isReachable(u, v))
        std::cout << "\n There is a path from " << u << " to " << v;
    else
        std::cout << "\n There is no path from " << u << " to " << v;

    u = 3, v = 1;
    if (g.isReachable(u, v))
        std::cout << "\n There is a path from " << u << " to " << v;
    else
        std::cout << "\n There is no path from " << u << " to " << v;

    return 0;
}


