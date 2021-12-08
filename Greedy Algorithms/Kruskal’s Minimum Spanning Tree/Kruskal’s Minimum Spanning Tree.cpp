// Kruskal’s Minimum Spanning Tree

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

class DSU
{
    std::vector<int> parent, rank;
public:
    DSU(int n) : parent(n), rank(n)
    {
        std::iota(begin(parent), end(parent), 0);
    }

    int find(int x)
    {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y)
    {
        int xp = find(x);
        int yp = find(y);

        if (xp == yp)
            return;

        if (rank[xp] > rank[yp])
            parent[yp] = parent[xp];
        else if (rank[yp] > rank[xp])
            parent[xp] = parent[yp];
        else
        {
            parent[xp] = parent[yp];
            rank[yp]++;
        }
    }
};

class Graph
{
    std::vector<std::vector<int>> edgelist;
    int V;

public:
    Graph(int V)
    {
        this->V = V;
    }

    void addEdge(int x, int y, int w)
    {
        edgelist.push_back({ w, x, y });
    }

    void KruskalMST()
    {
        // 1. Sort all edges
        sort(edgelist.begin(), edgelist.end());

        // Initialize the DSU
        DSU s(V);
        int minimumCost = 0;
        std::vector<std::vector<int>> mst;
        for (auto edge : edgelist)
        {
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];

            // take that edge in MST if it does form a cycle
            if (s.find(x) != s.find(y))
            {
                s.Union(x, y);
                minimumCost += w;
                mst.push_back({ x, y, w });
                if (mst.size() == V - 1)
                    break;
            }
        }

        std::cout << "Following are the edges in the constructed MST\n";
        for (auto edge : mst)
            std::cout << edge[0] << " -- " << edge[1] << " wt = " << edge[2] << std::endl;
        std::cout << "Minimum Cost Spanning Tree: " << minimumCost << std::endl;
    }
};

int main()
{
    Graph g(4);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 6);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);

    g.KruskalMST();

    return 0;
}


