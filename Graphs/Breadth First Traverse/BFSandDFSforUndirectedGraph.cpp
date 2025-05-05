#include <iostream>
#include <stack>
#include <queue>
#define v 9 
using namespace std;

void init(int arr[v][v]) {
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            arr[i][j] = 0; 
        }
    }
}

void add_edge(int arr[v][v], int a, int b) {
    arr[a][b] = 1; 
    arr[b][a] = 1; 
}

void display(int arr[v][v]) {
    cout << "Adjacency Matrix of Undirected Graph: "<<endl;
    for (int i = 0; i < v; i++) {
        cout << i << ": ";
        for (int j = 0; j < v; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void DFS(int arr[v][v]) {
    stack<int> s;
    bool visited[v] = {false}; 
    
    for (int start = 0; start < v; start++) {
        if (!visited[start]) {
            s.push(start);

            while (!s.empty()) {
                int current = s.top();
                s.pop();

                if (!visited[current]) {
                    visited[current] = true;
                    cout << current << " ";
                    
                    for (int i = 0; i < v; i++) {
                        if (arr[current][i] == 1 && !visited[i]) {
                            s.push(i);
                        }
                    }
                }
            }
        }
    }
}

void BFS(int arr[v][v]) {
    queue<int> q;
    bool visited[v];

    for (int i = 0; i < v; i++) {
        visited[i] = false;
    }

    cout <<endl<< "BFS Traversal: " << endl;

    for (int start = 0; start < v; start++) {
        if (!visited[start]) {
            q.push(start);
            visited[start] = true;

            while (!q.empty()) {
                int current = q.front();
                q.pop();

                cout << current << " "; 

                for (int j = 0; j < v; j++) {
                    if (arr[current][j] == 1 && !visited[j]) {
                        q.push(j);
                        visited[j] = true;
                    }
                }
            }
        }
    }
}

int main() {
    int arr[v][v];
    init(arr);

    add_edge(arr, 0, 1);
    add_edge(arr, 0, 7);
    add_edge(arr, 1, 2);
    add_edge(arr, 1, 7);
    add_edge(arr, 7, 6);
    add_edge(arr, 7, 8);
    add_edge(arr, 2, 8);
    add_edge(arr, 2, 5);
    add_edge(arr, 2, 3);
    add_edge(arr, 8, 6);
    add_edge(arr, 5, 6);
    add_edge(arr, 3, 4);
    add_edge(arr, 3, 5);
    add_edge(arr, 4, 5);

    display(arr);

    cout << "DFS Traversal: " << endl;
    DFS(arr);

    BFS(arr);

    return 0;
}