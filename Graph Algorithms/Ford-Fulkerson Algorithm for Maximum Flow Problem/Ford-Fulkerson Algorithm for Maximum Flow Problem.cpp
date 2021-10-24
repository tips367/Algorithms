// Ford-Fulkerson Algorithm for Maximum Flow Problem

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(int source, int sink, vector<int>& parent, vector<vector<int>>& residualGraph) 
{
    fill(parent.begin(), parent.end(), -1);
    int V = residualGraph.size();
    parent[source] = -2;
    queue<pair<int, int>> q;
    q.push({ source, INT_MAX });

    while (!q.empty()) 
    {
        int u = q.front().first;
        int capacity = q.front().second;
        q.pop();
        for (int av = 0; av < V; av++) 
        {
            if (u != av && parent[av] == -1 && residualGraph[u][av] != 0) 
            {
                parent[av] = u;
                int min_cap = min(capacity, residualGraph[u][av]);
                if (av == sink)
                    return min_cap;
                q.push({ av, min_cap });
            }
        }
    }
    return 0;
}

int ford_fulkerson(vector<vector<int>>& graph, int source, int sink) 
{
    vector<int> parent(graph.size(), -1);
    vector<vector<int>> residualGraph = graph;
    int min_cap = 0, max_flow = 0;
    while (min_cap = bfs(source, sink, parent, residualGraph)) 
    {
        max_flow += min_cap;
        int u = sink;
        while (u != source) 
        {
            int v = parent[u];
            residualGraph[u][v] += min_cap;
            residualGraph[v][u] -= min_cap;
            u = v;
        }
    }
    return max_flow;
}

void addEdge(vector<vector<int>>& graph, int u, int v, int w)
{
    graph[u][v] = w;
}

int main()
{
    int V = 6;
    vector<vector<int>> graph(V, vector<int>(V, 0));

 /* addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 3, 3);
    addEdge(graph, 1, 2, 4);
    addEdge(graph, 2, 3, 3);
    addEdge(graph, 2, 5, 2);
    addEdge(graph, 3, 4, 6);
    addEdge(graph, 4, 5, 6); */

    addEdge(graph, 0, 1, 16);
    addEdge(graph, 0, 2, 13);
    addEdge(graph, 1, 2, 10);
    addEdge(graph, 1, 3, 12);
    addEdge(graph, 2, 1, 4);
    addEdge(graph, 2, 4, 14);
    addEdge(graph, 3, 2, 9);
    addEdge(graph, 3, 5, 20);
    addEdge(graph, 4, 3, 7);
    addEdge(graph, 4, 5, 4);

    cout << "Maximum Flow: " << ford_fulkerson(graph, 0, 5) << endl;
    return 0;
}
