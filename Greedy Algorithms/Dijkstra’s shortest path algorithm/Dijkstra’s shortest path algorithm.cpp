// Dijkstra’s shortest path algorithm.cpp 

#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

// Method 1. Time complexity : O(V^2)
/*
#define V 9		// No of vertices

int selectMinVertex(std::vector<int>& distance, std::vector<bool>& processed)
{
	int minimum = INT_MAX;
	int vertex;
	for (int i = 0; i < V; ++i)
	{
		if (processed[i] == false && distance[i] < minimum)
		{
			vertex = i;
			minimum = distance[i];
		}
	}
	return vertex;
}

void dijkstra(int graph[V][V], int source)
{
	int parent[V];							// Stores Shortest Path Structure
	std::vector<int> distance(V, INT_MAX);  // Keeps shortest path values to each vertex from source
	std::vector<bool> processed(V, false);	// TRUE->Vertex is processed

	// Distance of source vertex from itself is always 0
	distance[source] = 0;
	// Start node has no parent
	parent[source] = -1;

	// Include (V-1) edges to cover all V-vertices
	for (int i = 0; i < V - 1; ++i)
	{
		//Select best Vertex by applying greedy method
		int U = selectMinVertex(distance, processed);

		processed[U] = true;	// Include new Vertex in shortest Path Graph

		// Update distance value of adjacent vertices (not yet included in shortest path graph)
		for (int v = 0; v < V; ++v)
		{
			// 3 conditions to relax:-
			//	  1.Edge is present from U to j.
			//	  2.Vertex j is not included in shortest path graph
			//	  3.Distance from src to v through U is smaller than current value of distance[v]

			if (graph[U][v] != 0 && processed[v] == false && distance[U] != INT_MAX
				&& (distance[U] + graph[U][v] < distance[v]))
			{
				distance[v] = distance[U] + graph[U][v];
				parent[v] = U;
			}
		}
	}
	// Print Shortest Path Graph
	for (int i = 1; i < V; ++i)
		std::cout << "U->V: " << parent[i] << "->" << i << "  wt = " << distance[i] << "\n";
}

int main()
{
	int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
						{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
						{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
						{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
						{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
						{ 0, 0, 4, 14, 10, 0, 2, 0, 0 },
						{ 0, 0, 0, 0, 0, 2, 0, 1, 6 },
						{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
						{ 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

	dijkstra(graph, 0);
	return 0;
} */

// Method 2. Optimized...Time complexity : O(ElogV)
void addEdge(vector<vector<pair<int, int>>>& adj, int u, int v, int wt)
{
	adj[u].push_back(std::make_pair(v, wt));
	adj[v].push_back(std::make_pair(u, wt));
}

void dijkstra(vector<vector<pair<int, int>>>& adj, int V, int src)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;

	vector<int> distance(V, INT_MAX);

	// Insert source itself in priority queue and initialize its distance as 0.
	pq.push(make_pair(0, src));

	distance[src] = 0;

	while (!pq.empty())
	{
		// The first vertex in pair is the minimum distance vertex, extract it from priority queue.
		// vertex label is stored in second of pair (it has to be done this way to keep the vertices
		// sorted distance (distance must be first item in pair)
		int u = pq.top().second;
		int d = pq.top().first;
		pq.pop();

		// this check is very important we analyze each vertex only once
		// the other occurrences of it on queue (added earlier) will have greater distance
		if (d <= distance[u])
		{
			// Get all adjacent of u. 
			for (auto x : adj[u])
			{
				// Get vertex label and weight of current adjacent of u.
				int v = x.first;
				int weight = x.second;

				// If there is shorted path to v through u.
				if (distance[v] > distance[u] + weight)
				{
					// Updating distance of v
					distance[v] = distance[u] + weight;
					pq.push(make_pair(distance[v], v));
				}
			}
		}
	}

	// Print shortest distances stored in dist[]
	printf("Vertex Distance from Source\n");
	for (int i = 0; i < V; ++i)
		cout << i << "\t\t" << distance[i] << endl;
}

int main()
{
	int V = 9;
	vector<vector<pair<int, int>>> adj(V);

	addEdge(adj, 0, 1, 4);
	addEdge(adj, 0, 7, 8);
	addEdge(adj, 1, 2, 8);
	addEdge(adj, 1, 7, 11);
	addEdge(adj, 2, 3, 7);
	addEdge(adj, 2, 8, 2);
	addEdge(adj, 2, 5, 4);
	addEdge(adj, 3, 4, 9);
	addEdge(adj, 3, 5, 14);
	addEdge(adj, 4, 5, 10);
	addEdge(adj, 5, 6, 2);
	addEdge(adj, 6, 7, 1);
	addEdge(adj, 6, 8, 6);
	addEdge(adj, 7, 8, 7);

	dijkstra(adj, V, 0);

	return 0;
}