﻿// Prim’s Minimum Spanning Tree

#include <iostream>
#include <vector>
#include <utility>

#define V 6		//No of vertices

// Time complexity : O(V^2)
int selectMinVertex(std::vector<int>& value, std::vector<bool>& setMST)
{
	int minimum = INT_MAX;
	int vertex;

	for (int i = 0; i < V; ++i)
	{
		if (setMST[i] == false && value[i] < minimum)
		{
			vertex = i;
			minimum = value[i];
		}
	}
	return vertex;
}

void findMST(int graph[V][V])
{
	int parent[V];						// Stores MST
	std::vector<int> value(V, INT_MAX);	// Used for edge relaxation
	std::vector<bool> setMST(V, false);	// TRUE->Vertex is included in MST

	//Assuming start point as Node-0
	parent[0] = -1;	// start node has no parent
	value[0] = 0;	// start node has value=0 to get picked 1st

	// Form MST with (V-1) edges
	for (int i = 0; i < V - 1; ++i)
	{
		// Select best Vertex by applying greedy method
		int U = selectMinVertex(value, setMST);
		setMST[U] = true;	//Include new Vertex in MST

		// Relax adjacent vertices (not yet included in MST)
		for (int j = 0; j < V; ++j)
		{
			/* 3 constraints to relax:-
				  1.Edge is present from U to j.
				  2.Vertex j is not included in MST
				  3.Edge weight is smaller than current edge weight
			*/
			if (graph[U][j] != 0 && setMST[j] == false && graph[U][j] < value[j])
			{
				value[j] = graph[U][j];
				parent[j] = U;
			}
		}
	}

	// Print MST
	for (int i = 1; i < V; ++i)
		std::cout << "U->V: " << parent[i] << "->" << i << "  wt = " << graph[parent[i]][i] << "\n";
}

int main()
{
	int graph[V][V] = { {0, 4, 6, 0, 0, 0},
						{4, 0, 6, 3, 4, 0},
						{6, 6, 0, 1, 8, 0},
						{0, 3, 1, 0, 2, 3},
						{0, 4, 8, 2, 0, 7},
						{0, 0, 0, 3, 7, 0} };

	findMST(graph);
	return 0;
}

// Optimized...Time complexity : O(E log V)
/*
int main() 
{
	int N, m;
	std::cin >> N >> m;
	std::vector<std::pair<int, int> > adj[N];

	int a, b, wt;
	for (int i = 0; i < m; i++) 
	{
		std::cin >> a >> b >> wt;
		adj[a].push_back(std::make_pair(b, wt));
		adj[b].push_back(std::make_pair(a, wt));
	}

	int parent[N];

	int key[N];

	bool mstSet[N];

	for (int i = 0; i < N; i++)
		key[i] = INT_MAX, mstSet[i] = false;

	priority_queue< pair<int, int>, vector <pair<int, int>>, greater<pair<int, int>> > pq;

	key[0] = 0;
	parent[0] = -1;
	pq.push({ 0, 0 });
	// Run the loop till all the nodes have been visited
	// because in the brute code we checked for mstSet[node] == false while computing the minimum
	// but here we simply take the minimal from the priority queue, so a lot of times a node might be taken twice
	// hence its better to keep running till all the nodes have been taken. 
	// try the following case: 
	// Credits: Srejan Bera
	// 6 7 
	// 0 1 5 
	// 0 2 10 
	// 0 3 100 
	// 1 3 50 
	// 1 4 200
	// 3 4 250
	// 4 5 50 
	while (!pq.empty())
	{
		int u = pq.top().second;
		pq.pop();

		mstSet[u] = true;

		for (auto it : adj[u]) {
			int v = it.first;
			int weight = it.second;
			if (mstSet[v] == false && weight < key[v]) {
				parent[v] = u;
				key[v] = weight;
				pq.push({ key[v], v });
			}
		}

	}

	for (int i = 1; i < N; i++)
		cout << parent[i] << " - " << i << " \n";
	return 0;
} */