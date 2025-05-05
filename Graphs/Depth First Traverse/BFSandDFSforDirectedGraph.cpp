#include <iostream>
#include <stack>
#include <queue>
#define V 7 // Number of vertices in the graph
using namespace std;

// Initialize the adjacency matrix to represent a directed graph
void init(int arr[V][V]) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            arr[i][j] = 0;
        }
    }
}

// Add a directed edge from vertex 'a' to vertex 'b'
void add_edge(int arr[V][V], int a, int b) {
    arr[a][b] = 1;
}

// Display the adjacency matrix
void display(int arr[V][V]) {
    cout << "Adjacency Matrix of Directed Graph:" << endl;
    for (int i = 0; i < V; i++) {
        cout << i << ": ";
        for (int j = 0; j < V; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

// Perform Depth First Search (DFS) on a directed graph
void DFS(int arr[V][V]) {
    stack<int> s;
    bool visited[V] = {false};

    cout << "DFS Traversal:" << endl;
    for (int start = 0; start < V; start++) {
        if (!visited[start]) {
            s.push(start);

            while (!s.empty()) {
                int current = s.top();
                s.pop();

                if (!visited[current]) {
                    visited[current] = true;
                    cout << current << " ";

                    for (int i = V - 1; i >= 0; i--) { // Reverse order for stack-based traversal
                        if (arr[current][i] == 1 && !visited[i]) {
                            s.push(i);
                        }
                    }
                }
            }
        }
    }
    cout << endl;
}

// Perform Breadth First Search (BFS) on a directed graph
void BFS(int arr[V][V]) {
    queue<int> q;
    bool visited[V] = {false};

    cout << "BFS Traversal:" << endl;
    for (int start = 0; start < V; start++) {
        if (!visited[start]) {
            q.push(start);
            visited[start] = true;

            while (!q.empty()) {
                int current = q.front();
                q.pop();

                cout << current << " ";

                for (int j = 0; j < V; j++) {
                    if (arr[current][j] == 1 && !visited[j]) {
                        q.push(j);
                        visited[j] = true;
                    }
                }
            }
        }
    }
    cout << endl;
}

int main() {
    int arr[V][V];
    init(arr);

    // Add directed edges to the graph (0-based indexing)
    add_edge(arr, 0, 1);
    add_edge(arr, 0, 2);
    add_edge(arr, 1, 3);
    add_edge(arr, 2, 3);
    add_edge(arr, 3, 4);
    add_edge(arr, 4, 5);
    add_edge(arr, 5, 6);

    display(arr);

    DFS(arr); // Perform Depth First Search
    BFS(arr); // Perform Breadth First Search

    return 0;
}
