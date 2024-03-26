#include <stdio.h>
#include <limits.h>

#define V 4 // Number of vertices in the graph

// Function to find the minimum of two numbers
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Function to solve TSP using dynamic programming
int tsp(int graph[][V], int mask, int pos, int dp[][V]) {
    // If all cities have been visited, return the cost of returning to the starting city
    if (mask == (1 << V) - 1) {
        return graph[pos][0];
    }

    // If the current subproblem has already been solved, return its result from dp table
    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int ans = INT_MAX;

    // Try to visit all cities not yet visited
    for (int city = 0; city < V; city++) {
        // If the city has not been visited yet
        if ((mask & (1 << city)) == 0) {
            int newMask = mask | (1 << city); // Mark the city as visited
            int cost = graph[pos][city] + tsp(graph, newMask, city, dp); // Calculate cost
            ans = min(ans, cost);
        }
    }

    // Save the result to dp table and return
    return dp[mask][pos] = ans;
}

int main() {
    int graph[V][V] = { {0, 10, 15, 20},
                        {10, 0, 35, 25},
                        {15, 35, 0, 30},
                        {20, 25, 30, 0} };

    // dp table to memoize the results of subproblems
    int dp[1 << V][V];
    for (int i = 0; i < (1 << V); i++) {
        for (int j = 0; j < V; j++) {
            dp[i][j] = -1; // Initialize with -1 (indicating subproblem not solved yet)
        }
    }

    // Start TSP from city 0 with all other cities unvisited
    int result = tsp(graph, 1, 0, dp);

    printf("The minimum cost of the Travelling Salesman Problem is: %d\n", result);

    return 0;
}
