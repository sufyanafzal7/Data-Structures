#include <iostream>
using namespace std;

#define V 6       // Number of vertices in the graph
#define INF 999999 // A large value to represent infinity

// Initialize the graph with zeros
void init(int arr[V][V]) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            arr[i][j] = 0;
        }
    }
}

// Add an edge with weight to the graph
void addEdge(int arr[V][V], int u, int v, int weight) {
    arr[u][v] = weight;
    arr[v][u] = weight;
}

// Find the vertex with the minimum key value not yet included in the MST
int minKey(int key[], bool mstSet[]) {
    int min = INF, min_index;

    for (int i = 0; i < V; i++) {
        if (!mstSet[i] && key[i] < min) {
            min = key[i];
            min_index = i;
        }
    }

    return min_index;
}

// Print the MST generated by Prim's algorithm
void printPrimMST(int parent[], int graph[V][V]) {
    cout << "\nPrim's MST:\nEdge\tWeight\n";
    for (int i = 1; i < V-1; i++) {
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << endl;
    }
}

// Implement Prim's algorithm for finding the MST
void primMST(int graph[V][V]) {
    int parent[V];  // Array to store the MST
    int key[V];     // Key values to pick the minimum weight edge
    bool mstSet[V]; // Track vertices included in the MST

    // Initialize all keys as infinite and MST set as false
    for (int i = 0; i < V; i++) {
        key[i] = INF;
        mstSet[i] = false;
    }

    key[0] = 0;       // Start with the first vertex (0-indexed)
    parent[0] = -1;   // Root node of MST

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet); // Find the vertex with the minimum key value
        mstSet[u] = true;            // Include this vertex in the MST

        // Update key values and parent indices of the adjacent vertices
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printPrimMST(parent, graph);
}

int main() {
    int graph[V][V];
    init(graph);

    // Add edges to the graph
    addEdge(graph, 2, 1, 50);
    addEdge(graph, 1, 3, 150);
    addEdge(graph, 2, 4, 40);
    addEdge(graph, 3, 4, 20);
    addEdge(graph, 0, 1, 250); 
    addEdge(graph, 0, 2, 60);

    primMST(graph);

    return 0;
}
