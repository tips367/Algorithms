/* There are N stations on route of a train. The train goes from station 0 to N-1. The ticket cost for all pair of 
stations (i, j) is given where j is greater than i. Find the minimum cost to reach the destination.
Consider the following example: 

Input:
cost[N][N] = { {0, 15, 80, 90},
              {INF, 0, 40, 50},
              {INF, INF, 0, 70},
              {INF, INF, INF, 0}
             };
There are 4 stations and cost[i][j] indicates cost to reach j from i. The entries where j < i are meaningless.

Output:
The minimum cost is 65
The minimum cost can be obtained by first going to station 1 from 0. Then from station 1 to station 3.
*/

#include <iostream>
#define N 4
#define INF INT_MAX

// Method 1: Using recursion
/*
int minCostRecur(int cost[N][N], int source, int destination)
{
    // If source is same as destination or destination is next to source
    if (source == destination || source + 1 == destination)
        return cost[source][destination];

    // Initialize min cost as direct ticket from source to destination
    int minCost = cost[source][destination];

    // Try every intermediate vertex to find minimum
    for (int i = source + 1; i < destination; i++)
    {
        int c = minCostRecur(cost, source, i) + minCostRecur(cost, i, destination);
        minCost = std::min(minCost, c);
    }
    return minCost;
}

int minCost(int cost[N][N])
{
    return minCostRecur(cost, 0, N - 1);
}*/

// Method 2: Using concept of Shortest path in Directed acyclic graph
int minCost(int cost[N][N])
{
    // costDP stores minimum cost to reach station i from station 0.
    int* costDP = new int[N];

    for (int i = 0; i < N; i++)
        costDP[i] = INF;

    costDP[0] = 0;

    // Go through every station and check if using it as an intermediate station gives better path
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            costDP[j] = std::min(costDP[j], cost[i][j] + costDP[i]);
        }
    }
    return costDP[N - 1];
}

int main()
{
    int cost[N][N] = { {0,   15,  80, 90},
                       {INF,  0,  40, 50},
                       {INF, INF, 0,  70},
                       {INF, INF, INF, 0}
    };
    std::cout << "The Minimum cost to reach station " << N << " is " << minCost(cost);
    return 0;
}

