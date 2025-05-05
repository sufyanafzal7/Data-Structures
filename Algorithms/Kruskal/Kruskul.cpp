#include <iostream>
#include <vector>
#include <algorithm>
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

// Edge structure for Kruskal's algorithm
struct Edge {
    int u, v, weight;
};

// Comparison function to sort edges by weight
bool compareEdges(Edge a, Edge b) {
    return a.weight < b.weight;
}

// Find the set of an element using path compression
int findSet(int parent[], int i) {
    if (parent[i] == -1)
        return i;
    return parent[i] = findSet(parent, parent[i]);
}

// Union of two sets
void unionSets(int parent[], int x, int y) {
    parent[x] = y;
}

// Implement Kruskal's algorithm for finding the MST
void kruskalMST(int graph[V][V]) {
    vector<Edge> edges;

    // Extract edges from the adjacency matrix
    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            if (graph[i][j] != 0) {
                edges.push_back({i, j, graph[i][j]});
            }
        }
    }

    // Sort edges by weight
    sort(edges.begin(), edges.end(), compareEdges);

    // Initialize the disjoint set
    int parent[V];
    for (int i = 0; i < V; i++) {
        parent[i] = -1;
    }

    vector<Edge> mst;

    for (auto &edge : edges) {
        int x = findSet(parent, edge.u);
        int y = findSet(parent, edge.v);

        // If including this edge doesn't form a cycle
        if (x != y) {
            mst.push_back(edge);
            unionSets(parent, x, y);
        }
    }

    // Print the MST
    cout << "\nKruskal's MST:\nEdge\tWeight\n";
    for (auto &edge : mst) {
        cout << edge.u << " - " << edge.v << "\t" << edge.weight << endl;
    }
}

int main() {
    int graph[V][V];
    init(graph);

    // Add edges to the graph
    addEdge(graph, 1, 2, 250);
    addEdge(graph, 1, 3, 60);
    // addEdge(graph, 2, 1, 250);
    addEdge(graph, 2, 3, 50);
    addEdge(graph, 2, 4, 150);
    // addEdge(graph, 3, 1, 60);
    // addEdge(graph, 3, 2, 50);
    addEdge(graph, 3, 5, 40);
    // addEdge(graph, 4, 2, 150);
    addEdge(graph, 4, 5, 20);
    // addEdge(graph, 5, 3, 40);
    // addEdge(graph, 5, 4, 20);

    // Generate and print MST using Kruskal's algorithm
    kruskalMST(graph);

    return 0;
}
