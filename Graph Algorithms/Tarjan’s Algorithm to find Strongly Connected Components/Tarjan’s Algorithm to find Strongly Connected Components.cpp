// Tarjan’s Algorithm to find Strongly Connected Components in a graph

#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>

#define V 7

// Time complexity : O(V+E)

std::unordered_map<int, std::vector<int>> adj;

void DFS(int u, std::vector<int>& disc, std::vector<int>& low, std::stack<int>& mystack, std::vector<bool>& presentInStack)
{
	static int time = 0;
	disc[u] = low[u] = time;
	time += 1;
	mystack.push(u);
	presentInStack[u] = true;

	for (int v : adj[u])
	{
		if (disc[v] == -1)	// If v is not visited
		{
			DFS(v, disc, low, mystack, presentInStack);
			low[u] = std::min(low[u], low[v]);
		}
		// Differentiate back-edge and cross-edge
		else if (presentInStack[v])					// Back-edge case
			low[u] = std::min(low[u], disc[v]);
	}

	if (low[u] == disc[u])	// If u is head node of SCC
	{
		std::cout << "SCC is: ";
		while (mystack.top() != u)
		{
			std::cout << mystack.top() << " ";
			presentInStack[mystack.top()] = false;
			mystack.pop();
		}

		std::cout << mystack.top() << "\n";
		presentInStack[mystack.top()] = false;
		mystack.pop();
	}
}

void findSCCs()
{
	std::vector<int> disc(V, -1), low(V, -1);
	std::vector<bool> presentInStack(V, false);		// Avoids cross-edge
	std::stack<int> mystack;

	for (int i = 0; i < V; ++i)
		if (disc[i] == -1)
			DFS(i, disc, low, mystack, presentInStack);
}

int main()
{
	adj[0].push_back(1);
	adj[1].push_back(2);
	adj[1].push_back(3);
	adj[3].push_back(4);
	adj[4].push_back(0);
	adj[4].push_back(5);
	adj[4].push_back(6);
	adj[5].push_back(6);
	adj[6].push_back(5);

	findSCCs();
	return 0;
}