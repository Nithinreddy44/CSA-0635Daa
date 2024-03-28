#include <stdio.h>
#include <stdbool.h>

#define V 5 // Number of vertices in the graph

void printSolution(int path[]);

// A utility function to check if the vertex v can be added at index 'pos' in the Hamiltonian Circuit constructed so far
bool isSafe(int v, bool graph[V][V], int path[], int pos) {
    if (!graph[path[pos - 1]][v])
        return false;

    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

// A recursive utility function to solve hamiltonian cycle problem
bool hamCycleUtil(bool graph[V][V], int path[], int pos) {
    if (pos == V) {
        if (graph[path[pos - 1]][path[0]])
            return true;
        else
            return false;
    }

    for (int v = 1; v < V; v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;
            if (hamCycleUtil(graph, path, pos + 1) == true)
                return true;
            path[pos] = -1;
        }
    }

    return false;
}

// This function solves the Hamiltonian Cycle problem using Backtracking.
// It mainly uses hamCycleUtil() to solve the problem. It returns false
// if there is no Hamiltonian Cycle possible, otherwise, return true and prints
// one of the Hamiltonian cycles.
bool hamCycle(bool graph[V][V]) {
    int path[V];
    for (int i = 0; i < V; i++)
        path[i] = -1;

    path[0] = 0;
    if (hamCycleUtil(graph, path, 1) == false) {
        printf("\nSolution does not exist");
        return false;
    }

    printSolution(path);
    return true;
}

// A utility function to print solution
void printSolution(int path[]) {
    printf ("Solution Exists: Following is one Hamiltonian cycle \n");
    for (int i = 0; i < V; i++)
        printf(" %d ", path[i]);
    printf(" %d ", path[0]);
    printf("\n");
}

int main() {
    bool graph[V][V] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0},
    };

    hamCycle(graph);
    return 0;
}
