#include <stdio.h>
#define V 4

// Function to initialize the adjacency matrix to zero
void init(int arr[][V]) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            arr[i][j] = 0;
        }
    }
}

// Function to add an edge to the adjacency matrix
void addEdge(int arr[][V], int i, int j) {
    arr[i][j] = 1;
}

// Function to print the adjacency matrix
void printAdjMatrix(int arr[][V]) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int adjMatrix[V][V];

    // Initialize the adjacency matrix
    init(adjMatrix);

    // Add edges to the graph with user input
    addEdge(adjMatrix, 0, 1);
    addEdge(adjMatrix, 0, 2);
    addEdge(adjMatrix, 1, 2);
    addEdge(adjMatrix, 2, 0);
    addEdge(adjMatrix, 2, 3);

    // Print the adjacency matrix
    printAdjMatrix(adjMatrix);

    return 0;
}
