// Articulation Points (or Cut Vertices) in a Graph using Tarjan's Algorithm

#include <iostream>
#include <unordered_map>
#include <vector>

#define V	5

std::unordered_map<int, std::vector<int>> adj;

void DFS(int u, std::vector<int>& disc, std::vector<int>& low, std::vector<int>& parent, std::vector<bool>& articulationPoint)
{
	static int time = 0;
	disc[u] = low[u] = time;
	time += 1;

	int children = 0;

	for (int v : adj[u])
	{
		// If v is not visited
		if (disc[v] == -1)
		{
			children += 1;
			parent[v] = u;

			DFS(v, disc, low, parent, articulationPoint);
			low[u] = std::min(low[u], low[v]);

			// Case-1: U is root
			if (parent[u] == -1 && children > 1)
				articulationPoint[u] = true;

			// Case-2: Atleast 1 component will get separated
			if (parent[u] != -1 && low[v] >= disc[u])
				articulationPoint[u] = true;
		}
		else if (v != parent[u])	// Ignore child to parent edge
			low[u] = std::min(low[u], disc[v]);
	}
}

void findAPs_Tarjan()
{
	std::vector<int> disc(V, -1), low(V, -1), parent(V, -1);
	std::vector<bool> articulationPoint(V, false);

	for (int i = 0; i < V; ++i)
	{
		if(disc[i] == -1)
			DFS(i, disc, low, parent, articulationPoint);
	}

	std::cout << "Articulation Points are:";
	for (int i = 0; i < V; ++i)
		if (articulationPoint[i] == true)
			std::cout << i << " ";
}

int main()
{
	adj[0].push_back(2);
	adj[2].push_back(0);
	adj[0].push_back(3);
	adj[3].push_back(0);
	adj[1].push_back(0);
	adj[0].push_back(1);
	adj[2].push_back(1);
	adj[1].push_back(2);
	adj[3].push_back(4);
	adj[4].push_back(3);

	findAPs_Tarjan();
	return 0;
}


