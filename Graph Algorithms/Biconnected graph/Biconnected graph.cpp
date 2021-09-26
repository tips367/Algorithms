// Biconnected graph

#include <iostream>
#include <unordered_map>
#include <vector>

#define V	5

std::unordered_map<int, std::vector<int>> adj;

bool hasArticulationPoints(int u, std::vector<int>& disc, std::vector<int>& low, std::vector<int>& parent)
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

			if (hasArticulationPoints(v, disc, low, parent))
				return true;
			low[u] = std::min(low[u], low[v]);

			// Case-1: U is root and has two or more children.
			if (parent[u] == -1 && children > 1)
				return true;

			// Case-2: If u is not root and low value of one of its child is more than discovery value of u
			// Atleast 1 component will get separated
			if(parent[u] != -1 && low[v]>= disc[u])
				return true;
		}
		else if(v != parent[u])			// Ignore child to parent edge
			low[u] = std::min(low[u], disc[v]);
	}
	return false;
}

bool isBiconnected()
{
	std::vector<int> disc(V, -1), low(V, -1), parent(V, -1);

	// find if there is an articulation point in given graph
	if (hasArticulationPoints(0, disc, low, parent))
		return false;

	// Check whether the given graph is connected or not
	for (int i = 0; i < V; i++)
	{
		if (disc[i] == -1)
			return false;
	}
	return true;
}

int main()
{
	adj[0].push_back(1);
	adj[1].push_back(0);
	adj[0].push_back(2);
	adj[2].push_back(0);
	adj[2].push_back(1);
	adj[1].push_back(2);
	adj[0].push_back(3);
	adj[3].push_back(0);
	adj[3].push_back(4);
	adj[4].push_back(3);
	adj[2].push_back(4);
	adj[4].push_back(2);

	if (isBiconnected())
		std::cout << "Yes\n";
	else
		std::cout << "No\n";

	return 0;
}

