#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>
#include <iomanip>

using namespace std;

// Struct for Edge (Shows Roads between Cities, Works as a Inner/Minor Linked List)
struct Edge {                
    string destination;
    int distance;
    Edge* next;
};

// Struct for Node (Shows Cities, Works as a Outer/Major Linked List)
struct Node {
    string city;
    Edge* head;
    Edge* tail;
    Node* next;
};

// Global pointers for adjacency list and matrix
Node* head = NULL;
Node* tail = NULL;
vector<string> cities;  // List of cities to index in the matrix
vector<vector<int>> adjMatrix;  // Adjacency Matrix

// Stack class definition
class Stack {
private:
    int l;
    int* s;
    int top;

public:
    Stack(int length) {
        l = length;
        s = new int[length];
        top = -1;
    }

    ~Stack() {}

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == l - 1;
    }

    void push(int val) {
        if (isFull()) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        s[++top] = val;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return;
        }
        top--;
    }

    int peak() {
        if (isEmpty()) {
            return -1;
        }
        return s[top];
    }

    void displayStack() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Elements of the stack: ";
        for (int i = top; i >= 0; i--) {
            cout << s[i] << " ";
        }
        cout << endl;
    }
};

// Queue class definition as per provided code
class Queue {
    private:
    int l;
    int *q;
    int front;
    int rear;
    public:
    Queue(int length) {
        l = length;
        q = new int[length];
        front = rear = -1;
    }
    
    ~Queue() {}

    bool isFull() {
        return rear == l - 1;
    }

    bool isEmpty() {
        return front == -1 && rear == -1;
    }

    void enQueue(int val) {
        if (isFull()) {
            cout << "Queue is Full!" << endl;
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear++;
        }
        q[rear] = val;
    }

    void deQueue() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }
        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
    }

    int peek() {
        if (isEmpty()) {
            return -1;
        }
        return q[front];
    }

    void displayQueue() {
        if (isEmpty()) {
            cout << "Queue doesn't exist!" << endl;
            return;
        }
        cout << "Elements of the queue are: " << endl;
        for (int i = front; i <= rear; i++) {
            cout << q[i] << " ";
        }
        cout << endl;
    }
};

// Function to insert a vertex (city)
void insert_vertex(const string& city) {
    Node* n = new Node;
    n->city = city;
    n->next = NULL;
    n->head = n->tail = NULL;
    if (head == NULL) {
        head = tail = n;
    } else {
        tail->next = n;
        tail = n;
    }

    // Add city to the list for matrix indexing
    cities.push_back(city);

    // Update adjacency matrix with infinity (-1 or some large number)
    for (auto& row : adjMatrix) {
        row.push_back(999999);  // No direct path initially
    }
    adjMatrix.push_back(vector<int>(cities.size(), 999999));  // Add new row for new city
}

// Function to check if a vertex exists
bool check_vertex(const string& city) {
    for (const auto& c : cities) {
        if (c == city) {
            return true;
        }
    }
    return false;
}

// Function to get the index of a city
int get_city_index(const string& city) {
    for (size_t i = 0; i < cities.size(); i++) {
        if (cities[i] == city) {
            return i;
        }
    }
    return -1;
}

// Function to add an edge between two cities (adjacency list and matrix)
void add_edge(const string& origin, const string& destination, int distance) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->city == origin) {
            break;
        }
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Origin City Not Found: " << origin << endl;
        return;
    }

    if (!check_vertex(destination)) {
        cout << "Destination City Not Found: " << destination << endl;
        return;
    }

    // Add edge in adjacency list
    Edge* e = new Edge;
    e->destination = destination;
    e->distance = distance;
    e->next = NULL;

    if (temp->head == NULL) {
        temp->head = temp->tail = e;
    } else {
        temp->tail->next = e;
        temp->tail = e;
    }

    // Add edge in adjacency matrix
    int origin_idx = get_city_index(origin);
    int destination_idx = get_city_index(destination);
    adjMatrix[origin_idx][destination_idx] = distance;
}
// Function to display all nodes of the graph
void displayGraph() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->city << " has edges to: ";
        Edge* edge = temp->head;
        while (edge != NULL) {
            cout << "(" << edge->destination << ", " << edge->distance << " km) ";
            edge = edge->next;
        }
        cout << endl;
        temp = temp->next;
    }
}

// Function to display adjacency list
void displayAdjlist() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->city << " -> ";
        Edge* edge = temp->head;
        while (edge != NULL) {
            cout << "(" << edge->destination << ", " << edge->distance << " km) ";
            edge = edge->next;
        }
        cout << endl;
        temp = temp->next;
    }
}

// Function to display adjacency matrix in 10x10 chunks
void displayAdjmatrix() {
    const int CHUNK_SIZE = 10; // Number of columns per chunk

    cout << "\nAdjacency Matrix:\n";

    // Print the adjacency matrix in chunks
    for (size_t start_col = 0; start_col < cities.size(); start_col += CHUNK_SIZE) {
        size_t end_col = min(start_col + CHUNK_SIZE, cities.size());

        // Print column headers for this chunk
        cout << setw(12) << " "; // Align for row headers
        for (size_t col = start_col; col < end_col; ++col) {
            cout << setw(10) << cities[col];
        }
        cout << "\n";

        // Print each row with only the relevant chunk of columns
        for (size_t i = 0; i < cities.size(); ++i) {
            cout << setw(12) << cities[i]; // Print row header (city name)

            for (size_t col = start_col; col < end_col; ++col) {
                // Check for no edge and display '0' instead of a large value
                if (adjMatrix[i][col] == 999999) {
                    cout << setw(10) << "0";
                } else {
                    cout << setw(10) << adjMatrix[i][col];
                }
            }
            cout << "\n";
        }

        cout << "\n"; // Add spacing between chunks
    }
}


// BFT Implementation using Queue
void bft(const string& start_city) {
    // Queue for BFS
    Queue q(cities.size());
    bool visited[20];  // To mark cities as visited

    // Get the index of the start city
    int start_index = get_city_index(start_city);
    if (start_index == -1) {
        cout << "Start city not found!" << endl;
        return;
    }

    // Start BFT
    visited[start_index] = true;
    q.enQueue(start_index);

    cout << "Breadth First Traversal (BFT) starting from " << start_city << ": " << endl;

    while (!q.isEmpty()) {
        int current_index = q.peek();
        cout << cities[current_index] << " -> ";
        q.deQueue();

        // Explore all the neighbors of the current city
        Node* temp = head;
        while (temp != NULL) {
            if (temp->city == cities[current_index]) {
                break;
            }
            temp = temp->next;
        }

        Edge* edge = temp->head;
        while (edge != NULL) {
            int neighbor_index = get_city_index(edge->destination);
            if (!visited[neighbor_index]) {
                visited[neighbor_index] = true;
                q.enQueue(neighbor_index);
            }
            edge = edge->next;
        }
    }
    cout << endl;
}

// DFT Implementation using Stack
void dft(const string& start_city) {
    Stack s(cities.size());
    bool visited[20];

    // Get the index of the start city
    int start_index = get_city_index(start_city);
    if (start_index == -1) {
        cout << "Start city not found!" << endl;
        return;
    }

    // Start DFT
    visited[start_index] = true;
    s.push(start_index);

    cout << "Depth First Traversal (DFT) starting from " << start_city << ": " << endl;

    while (!s.isEmpty()) {
        int current_index = s.peak();
        cout << cities[current_index] << " -> ";
        s.pop();

        // Explore all the neighbors of the current city
        Node* temp = head;
        while (temp != NULL) {
            if (temp->city == cities[current_index]) {
                break;
            }
            temp = temp->next;
        }

        Edge* edge = temp->head;
        while (edge != NULL) {
            int neighbor_index = get_city_index(edge->destination);
            if (!visited[neighbor_index]) {
                visited[neighbor_index] = true;
                s.push(neighbor_index);
            }
            edge = edge->next;
        }
    }
    cout << endl;
}

// Function to find the city with the minimum distance that is not yet visited
int min_distance(const vector<int>& dist, const vector<bool>& visited, int num_cities) {
    int min = INT_MAX, min_index = -1;
    for (int i = 0; i < num_cities; i++) {
        if (!visited[i] && dist[i] <= min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

// Function to reconstruct the path from the source to the target city
vector<string> reconstruct_path(int target, const vector<int>& previous) {
    vector<string> path;

    // Reconstruct path by following the previous cities
    while (target != -1) {
        path.push_back(cities[target]);
        target = previous[target];
    }

    // The path is in reverse order, so we reverse it
    reverse(path.begin(), path.end());

    return path;
}

// Dijkstra's Algorithm to find the shortest path from source city to all other cities
void dijkstra(const string& start_city) {
    // Get the index of the start city
    int start_index = get_city_index(start_city);
    if (start_index == -1) {
        cout << "Start city not found!" << endl;
        return;
    }

    int num_cities = cities.size();

    // Initialize distances as infinite and visited as false
    vector<int> dist(num_cities, INT_MAX);  // Distance from start city to all others
    vector<bool> visited(num_cities, false);  // Visited status for each city
    vector<int> previous(num_cities, -1);  // Previous city on the shortest path

    // Distance from start city to itself is 0
    dist[start_index] = 0;

    cout << "Dijkstra's Algorithm starting from " << start_city << ": " << endl;

    // Process all cities
    for (int count = 0; count < num_cities - 1; count++) {
        // Get the city with the minimum distance from the set of unvisited cities
        int u = min_distance(dist, visited, num_cities);

        // Mark the selected city as visited
        visited[u] = true;

        // Update the distance of the neighboring cities of the current city
        Node* temp = head;
        while (temp != NULL) {
            if (temp->city == cities[u]) {
                break;
            }
            temp = temp->next;
        }

        // Update distances of all the unvisited neighbors of the selected city
        Edge* edge = temp->head;
        while (edge != NULL) {
            int v = get_city_index(edge->destination);
            if (!visited[v] && dist[u] != INT_MAX && dist[u] + edge->distance < dist[v]) {
                dist[v] = dist[u] + edge->distance;
                previous[v] = u;  // Store the previous city on the shortest path
            }
            edge = edge->next;
        }
    }

    // Output the results with formatting
    cout << left << setw(15) << "City" << setw(25) << "Distance from " + start_city << " Path" << endl;
    for (int i = 0; i < num_cities; i++) {
        cout << left << setw(15) << cities[i];
        if (dist[i] == INT_MAX) {
            cout << setw(25) << "Inf" << "No path" << endl;
        } else {
            cout << setw(25) << dist[i] << " ";
            // Reconstruct and print the path
            vector<string> path = reconstruct_path(i, previous);
            for (size_t j = 0; j < path.size(); j++) {
                cout << path[j];
                if (j != path.size() - 1) {
                    cout << " -> ";
                }
            }
            cout << endl;
        }
    }
}

bool reverseEdgeExists(string source, string destination, int distance) {
    Node* cityNode = head;
    while (cityNode != NULL) {
        if (cityNode->city == source) {  // Found the source city
            Edge* edge = cityNode->head;
            while (edge != NULL) {
                if (edge->destination == destination && edge->distance == distance) {
                    return true;  // Reverse edge exists
                }
                edge = edge->next;
            }
            return false;  // Reverse edge doesn't exist
        }
        cityNode = cityNode->next;
    }
    return false;  // Source city not found
}
// Function to convert a directed graph to an undirected graph
void convertToUndirected() {
    Node* temp = head;
    while (temp != NULL) {
        Edge* edge = temp->head;
        while (edge != NULL) {
            // Check if the reverse edge already exists
            if (!reverseEdgeExists(edge->destination, temp->city, edge->distance)) {
                add_edge(edge->destination, temp->city, edge->distance);
            }
            edge = edge->next;
        }
        temp = temp->next;
    }
}
// Structure for a Disjoint Set (Union-Find)
struct DisjointSet {
    vector<int> parent;
    vector<int> rank;

    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;  // Initially, each node is its own parent
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);  // Path compression
        }
        return parent[x];
    }

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            // Union by rank
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};
// Renamed the struct to KruskalEdge to avoid conflict
struct KruskalEdge {
    int u, v, weight;
    KruskalEdge(int u, int v, int weight) : u(u), v(v), weight(weight) {}
};
// Function to perform Kruskal's Algorithm
void kruskal() {
    int num_cities = cities.size();
    vector<KruskalEdge> edges;  // Using KruskalEdge instead of Edge

    // Step 1: Build the list of all edges from the graph
    Node* temp = head;
    while (temp != NULL) {
        Edge* edge = temp->head;
        while (edge != NULL) {
            int u = get_city_index(temp->city);
            int v = get_city_index(edge->destination);
            edges.push_back(KruskalEdge(u, v, edge->distance));  // Use KruskalEdge here
            edge = edge->next;
        }
        temp = temp->next;
    }

    // Step 2: Sort the edges by weight
    sort(edges.begin(), edges.end(), [](KruskalEdge a, KruskalEdge b) {
        return a.weight < b.weight;
    });

    // Step 3: Initialize Disjoint Set for Union-Find
    DisjointSet ds(num_cities);

    vector<KruskalEdge> mst;  // This will store the MST edges
    int mst_weight = 0;  // This will store the total weight of MST

    // Step 4: Process each edge
    for (const KruskalEdge& edge : edges) {
        int u = edge.u;
        int v = edge.v;

        // If u and v are in different sets, include this edge in the MST
        if (ds.find(u) != ds.find(v)) {
            mst.push_back(edge);
            mst_weight += edge.weight;
            ds.unionSets(u, v);
        }
    }

    // Step 5: Output the MST
    cout << "Kruskal's Algorithm: Minimum Spanning Tree" << endl;
    cout << left << setw(15) << "City 1" << setw(15) << "City 2" << setw(15) << "Weight" << endl;
    for (const KruskalEdge& e : mst) {
        cout << left << setw(15) << cities[e.u] << setw(15) << cities[e.v] << setw(15) << e.weight << endl;
    }
    cout << "Total weight of MST: " << mst_weight << endl;
}
// Prim's Algorithm to find the Minimum Spanning Tree
void prim(const string& start_city) {
    // Get the index of the start city
    int start_index = get_city_index(start_city);
    if (start_index == -1) {
        cout << "Start city not found!" << endl;
        return;
    }

    int num_cities = cities.size();

    // Initialize arrays
    vector<int> key(num_cities, INT_MAX);   // Key values to pick minimum weight edge
    vector<bool> included(num_cities, false); // To track included nodes in MST
    vector<int> parent(num_cities, -1);    // To store MST structure

    // Start with the source city
    key[start_index] = 0;
    parent[start_index] = -1; // Root of MST

    cout << "Prim's Algorithm starting from " << start_city << ":" << endl;

    // MST will have num_cities - 1 edges
    for (int count = 0; count < num_cities - 1; count++) {
        // Find the minimum key value among nodes not yet included in MST
        int u = min_distance(key, included, num_cities);

        // Include the selected node in MST
        included[u] = true;

        // Update the key and parent for neighbors of the selected node
        Node* temp = head;
        while (temp != NULL) {
            if (temp->city == cities[u]) {
                break;
            }
            temp = temp->next;
        }

        Edge* edge = temp->head;
        while (edge != NULL) {
            int v = get_city_index(edge->destination);
            if (!included[v] && edge->distance < key[v]) {
                key[v] = edge->distance;
                parent[v] = u;
            }
            edge = edge->next;
        }
    }

    // Display the MST in a cleaner format
    int total_cost = 0;  // To calculate the total cost of MST
    cout << "Edges in the MST:\n";
    for (int i = 0; i < num_cities; i++) {
        if (parent[i] != -1) {
            cout << cities[parent[i]] << " - " << cities[i] << " : " << key[i] << endl;
            total_cost += key[i];  // Add the weight of this edge to the total cost
        }
    }

    // Print the total cost of the MST
    cout << "\nTotal Cost of MST: " << total_cost << endl;
}
// Function to load data from CSV and build the graph
void load_data(const string& filename) {
    ifstream file(filename);
    string line, origin, destination;
    int distance;

    // Skip the header line if any
    getline(file, line);

    while (getline(file, line)) {
        stringstream ss(line);
        getline(ss, origin, ',');  // Read origin city
        getline(ss, destination, ',');  // Read destination city
        ss >> distance;  // Read distance

        // Insert vertices into the graph if not already present
        if (!check_vertex(origin)) {
            insert_vertex(origin);
        }
        if (!check_vertex(destination)) {
            insert_vertex(destination);
        }

        // Add edge between cities
        add_edge(origin, destination, distance);
    }

    file.close();
}

// Main Function
int main() {
    string filename = "D:\\Study Material\\Bachelors in Artificial Intelligence (AI)\\3rd Semester\\Data Structures & Algorithms (DSA)\\Lab Work\\Final Semester Project\\dataset.csv";  // Replace with your CSV file path
    load_data(filename);  // Load data from CSV and construct the graph
    int choice;
    string startCity;

    while (true) {
        cout << "\nCities Distances Simulation Menu:\n";
        cout << "1: Display graph\n";
        cout << "2: Display Adjacency List of graph\n";
        cout << "3: Display Adjacency Matrix of graph\n";
        cout << "4: Perform Breadth-First Traversal (BFT)\n";
        cout << "5: Perform Depth-First Traversal (DFT)\n";
        cout << "6: Apply Dijikstra Algorithm to find shortest distances\n";
        cout << "7: Convert the graph from Directed to Undirected and Display Graph\n";
        cout << "8: Apply Kruskal's Algorithm to find Minimum Spanning Tree (MST)\n";
        cout << "9: Apply Prim's Algorithm to find Minimum Spanning Tree (MST)\n";
        cout << "10: Exiting the Simulation Program!\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayGraph();
                break;
            case 2:
                displayAdjlist();
                break;
            case 3:
                displayAdjmatrix();
                break;
            case 4:
                cout << "Enter starting city for BFT: ";
                cin >> ws; // Consume whitespace
                getline(cin, startCity);
                bft(startCity);
                break;
            case 5:
                cout << "Enter starting city for DFT: ";
                cin >> ws; // Consume whitespace
                getline(cin, startCity);
                dft(startCity);
                break;
            case 6:
                cout << "Enter starting city for Dijikstra's Algorithm: ";
                cin >> ws; // Consume whitespace
                getline(cin, startCity);
                dijkstra(startCity);
                break;
            case 7:
                convertToUndirected();
                displayGraph();
                break;
            case 8:
                convertToUndirected();
                kruskal();
                break;
            case 9:
                convertToUndirected();
                cout << "Enter starting city for Prim's Algorithm: ";
                cin >> ws; // Consume whitespace
                getline(cin, startCity);
                prim(startCity);
                break;
            case 10:
                cout<<"Exiting Program!";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}
