#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES]; // Adjacency matrix representing the graph
int colors[MAX_VERTICES]; // Array to store colors assigned to vertices
int numVertices; // Number of vertices in the graph

// Function to check if it's safe to assign color c to vertex v
bool isSafe(int v, int c) {
    for (int i = 0; i < numVertices; i++) {
        if (graph[v][i] && c == colors[i]) {
            return false;
        }
    }
    return true;
}

// Function to assign colors recursively
bool assignColors(int v) {
    if (v == numVertices) {
        return true; // All vertices are colored
    }
    for (int c = 1; c <= numVertices; c++) {
        if (isSafe(v, c)) {
            colors[v] = c; // Assign color c to vertex v
            if (assignColors(v + 1)) {
                return true; // Recursively assign colors to next vertices
            }
            colors[v] = 0; // Backtrack
        }
    }
    return false; // No valid color found
}

int main() {
    // Input number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    // Input adjacency matrix
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Initialize colors array with 0 (no color assigned)
    for (int i = 0; i < numVertices; i++) {
        colors[i] = 0;
    }

    // Call the function to assign colors
    if (assignColors(0)) {
        printf("Colors assigned successfully:\n");
        for (int i = 0; i < numVertices; i++) {
            printf("Vertex %d -> Color %d\n", i + 1, colors[i]);
        }
    } else {
        printf("Failed to assign colors. No valid coloring exists.\n");
    }

    return 0;
}
