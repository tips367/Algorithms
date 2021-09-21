// Kosaraju Algorithm to find Strongly connected components in a graph

#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>


using namespace std;
#define V 8

// Time complexity : O(V+E)

unordered_map<int, vector<int>> adj, rev;

void DFS1(int i, vector<bool>& visited, stack<int>& mystack)
{
	visited[i] = true;
	for (int j : adj[i])
		if (visited[j] == false)
			DFS1(j, visited, mystack);

	mystack.push(i);
}

void reverse()
{
	for (int i = 0; i < V; ++i)
	{
		for (int j : adj[i])
			rev[j].push_back(i);
	}
}

void DFS2(int i, vector<bool>& visited)
{
	cout << i << " ";
	visited[i] = true;
	for (int j : rev[i])
		if (!visited[j])
			DFS2(j, visited);
}

void findSCCs()
{
	stack<int> mystack;

	vector<bool> visited(V, false);
	for (int i = 0; i < V; ++i)
		if (!visited[i])
			DFS1(i, visited, mystack);

	reverse();

	for (int i = 0; i < V; ++i)
		visited[i] = false;

	cout << "Strongly Connected Components are:\n";
	while (!mystack.empty())
	{
		int curr = mystack.top();
		mystack.pop();
		if (visited[curr] == false)
		{
			DFS2(curr, visited);
			cout << "\n";
		}
	}
}

int main()
{
	adj[0].push_back(1);
	adj[1].push_back(2);
	adj[2].push_back(0);
	adj[2].push_back(3);
	adj[3].push_back(4);
	adj[4].push_back(5);
	adj[4].push_back(7);
	adj[5].push_back(6);
	adj[6].push_back(4);
	adj[6].push_back(7);

	findSCCs();
	return 0;
}

