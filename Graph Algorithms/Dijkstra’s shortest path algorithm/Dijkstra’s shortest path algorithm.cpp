// Dijkstra’s shortest path algorithm.cpp 

#include <iostream>
#include <vector>

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
	parent[0] = -1;	

	// Include (V-1) edges to cover all V-vertices
	for (int i = 0; i < V - 1; ++i)
	{
		//Select best Vertex by applying greedy method
		int U = selectMinVertex(distance, processed);

		processed[U] = true;	// Include new Vertex in shortest Path Graph

		// Update distance value of adjacent vertices (not yet included in shortest path graph)
		for (int v = 0; v < V; ++v)
		{
			/* 3 conditions to relax:-
				  1.Edge is present from U to j.
				  2.Vertex j is not included in shortest path graph
				  3.Distance from src to v through U is smaller than current value of distance[v]
			*/
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
}

