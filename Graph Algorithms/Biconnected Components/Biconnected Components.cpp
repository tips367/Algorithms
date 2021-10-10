// Biconnected Components

#include <iostream>
#include <list>
#include <stack>
#include <vector>

int count = 0;

class Edge {
public:
    int u;
    int v;
    Edge(int u, int v);
};

Edge::Edge(int u, int v)
{
    this->u = u;
    this->v = v;
}

class Graph 
{
    int V;
    int E;
    std::list<int>* adj;

    void BCCUtil(int u, std::vector<int>& disc, std::vector<int>& low, std::stack<Edge>& st, std::vector<int>& parent);

public:
    Graph(int V);
    void addEdge(int v, int w);
    void BCC();
};

Graph::Graph(int V)
{
    this->V = V;
    this->E = 0;
    adj = new std::list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    E++;
}

void Graph::BCCUtil(int u, std::vector<int>& disc, std::vector<int>& low, std::stack<Edge>& st, std::vector<int>& parent)
{
    static int time = 0;
    disc[u] = low[u] = time;
    time += 1;

    int children = 0;

    for (auto v : adj[u])
    {
        // If v is not visited
        if (disc[v] == -1)
        {
            children += 1;
            parent[v] = u;

            // store the edge in stack
            st.push(Edge(u, v));
            BCCUtil(v, disc, low, st, parent);
            low[u] = std::min(low[u], low[v]);

            // If u is an articulation point, pop all edges from stack till u -- v
            if (parent[u] == -1 && children > 1 || parent[u] != -1 && low[v] >= disc[u])
            {
                while (st.top().u != u || st.top().v != v) 
                {
                    std::cout << st.top().u << "--" << st.top().v << " ";
                    st.pop();
                }
                std::cout << st.top().u << "--" << st.top().v;
                st.pop();
                std::cout << std::endl;
                count++;
            }
        }
        else if (v != parent[u])	// Ignore child to parent edge
        {
            low[u] = std::min(low[u], disc[v]);
            if (disc[v] < disc[u])
                st.push(Edge(u, v));
        }
    }
}

void Graph::BCC()
{
    std::vector<int> disc(V, -1), low(V, -1), parent(V, -1);
    std::stack<Edge> st;

    for (int i = 0; i < V; i++) 
    {
        if (disc[i] == -1)
            BCCUtil(i, disc, low, st, parent);

        int j = 0;
        // If stack is not empty, pop all edges from stack
        while (st.size() > 0) 
        {
            j = 1;
            std::cout << st.top().u << "--" << st.top().v << " ";
            st.pop();
        }
        if (j == 1) 
        {
            std::cout << std::endl;
            count++;
        }
    }
}

int main()
{
    Graph g(12);
    g.addEdge(0, 1);
    g.addEdge(1, 0);
    g.addEdge(1, 2);
    g.addEdge(2, 1);
    g.addEdge(1, 3);
    g.addEdge(3, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 2);
    g.addEdge(2, 4);
    g.addEdge(4, 2);
    g.addEdge(3, 4);
    g.addEdge(4, 3);
    g.addEdge(1, 5);
    g.addEdge(5, 1);
    g.addEdge(0, 6);
    g.addEdge(6, 0);
    g.addEdge(5, 6);
    g.addEdge(6, 5);
    g.addEdge(5, 7);
    g.addEdge(7, 5);
    g.addEdge(5, 8);
    g.addEdge(8, 5);
    g.addEdge(7, 8);
    g.addEdge(8, 7);
    g.addEdge(8, 9);
    g.addEdge(9, 8);
    g.addEdge(10, 11);
    g.addEdge(11, 10);
    g.BCC();

    std::cout << "Above are " << count << " biconnected components in graph";
    return 0;
}


