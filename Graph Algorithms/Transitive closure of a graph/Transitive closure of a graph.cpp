/* Given a directed graph, find out if a vertex j is reachable from another vertex i for all vertex pairs (i, j) in the given graph.
Here reachable mean that there is a path from vertex i to j. The reach-ability matrix is called the transitive closure of a graph.
*/

#include <iostream>
#include <vector>

#define V 4

void transitiveClosure(int graph[][V])
{
    std::vector<std::vector<int>> reach(V, std::vector<int>(V));

    // Initial values of shortest distances are based
    // on shortest paths considering no intermediate vertex
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            reach[i][j] = graph[i][j];      
        }
    }

    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                // If vertex k is on a path from i to j
                reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
            }
        }
    }

    std::cout << "Following matrix is transitive closure of the given graph\n";
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            // i == j means same vertex and we can reach same vertex from same vertex
            if (i == j)
                std::cout << "1 ";
            else
                std::cout << reach[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    /* Let us create the following weighted graph
            10
       (0)------->(3)
        |         /|\
      5 |          |
        |          | 1
       \|/         |
       (1)------->(2)
            3           
    */

    int graph[V][V] = { {1, 1, 0, 1},
                        {0, 1, 1, 0},
                        {0, 0, 1, 1},
                        {0, 0, 0, 1}
    };

    transitiveClosure(graph);
    return 0;
}