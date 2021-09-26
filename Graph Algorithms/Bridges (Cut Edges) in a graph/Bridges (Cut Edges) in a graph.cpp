// Bridges (Cut Edges) in a graph

#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>

#define V 5

std::unordered_map<int, std::vector<int>> adj;

void DFS(int u, std::vector<int>& disc, std::vector<int>& low, std::vector<int>& parent, std::vector<std::pair<int, int>>& bridges)
{
	static int time = 0;
	disc[u] = low[u] = time;
	time += 1;

	for (int v : adj[u])
	{
		if (disc[v] == -1)	// If v is not visited
		{
			parent[v] = u;
			DFS(v, disc, low, parent, bridges);
			low[u] = std::min(low[u], low[v]);

			if (low[v] > disc[u])
				bridges.push_back({ u, v });
		}
		else if(v != parent[u])		// Ignore child to parent edge
			low[u] = std::min(low[u], disc[v]);
	}
}

void findBridges()
{
	std::vector<int> disc(V, -1), low(V, -1), parent(V, -1);
	std::vector<std::pair<int, int>> bridges;

	for (int i = 0; i < V; ++i)
		if (disc[i] == -1)
			DFS(i, disc, low, parent, bridges);

	std::cout << "Bridges are: \n";
	for (auto it : bridges)
		std::cout << it.first << "-->" << it.second << "\n";
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

	findBridges();
	return 0;
}


