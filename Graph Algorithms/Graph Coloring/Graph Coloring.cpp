// Graph Coloring

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

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
    ~Graph() { delete[] adj; }

    void addEdge(int v, int w);

    void greedyColoring();
};

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v); 
}

void Graph::greedyColoring()
{
    std::vector<int> color(V, -1);

    // Assign the first color to first vertex
    color[0] = 0;

    // colors already assigned to neighbors
    std::vector<bool> alreadyAssigned(V);

    for (int u = 1; u < V; u++)
    {
        fill(alreadyAssigned.begin(), alreadyAssigned.end(), false);

        // Process all adjacent vertices and flag their colors as unavailable
        for(auto i : adj[u])
            if(color[i] != -1)
                alreadyAssigned[color[i]] = true;

        // Find the first available color
        int c;
        for (c = 0; c < V; c++)
            if (alreadyAssigned[c] == false)
                break;

        color[u] = c; // Assign the found color
    }

    for (int u = 0; u < V; u++)
        std::cout << "Vertex " << u << " ---> Color " << color[u] << std::endl;
    std::cout << "Number of colors required: " << *max_element(color.begin(), color.end()) + 1 << std::endl;
}

int main()
{
    Graph g1(5);
    g1.addEdge(0, 1);
    g1.addEdge(0, 2);
    g1.addEdge(1, 2);
    g1.addEdge(1, 3);
    g1.addEdge(2, 3);
    g1.addEdge(3, 4);
    std::cout << "Coloring of graph 1 \n";
    g1.greedyColoring();

    Graph g2(5);
    g2.addEdge(0, 1);
    g2.addEdge(0, 2);
    g2.addEdge(1, 2);
    g2.addEdge(1, 4);
    g2.addEdge(2, 4);
    g2.addEdge(4, 3);
    std::cout << "\nColoring of graph 2 \n";
    g2.greedyColoring();

    return 0;
}

