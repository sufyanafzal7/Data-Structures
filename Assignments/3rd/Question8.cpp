#include <iostream>
using namespace std;

const int nodes = 9;

int findMin(int distance[nodes], bool visited[nodes])
{
    int mindex = -1;
    int minimum = INT_MAX;

    for (int i = 0; i < nodes; i++)
    {
        if (!visited[i] && distance[i] < minimum)
        {
            mindex = i;
            minimum = distance[i];
        }
    }
    return mindex;
}

void print(int distance[nodes])
{
    cout << "Node\t\tDistance" << endl;
    for (int i = 0; i < nodes; i++)
        cout << i << "\t\t" << distance[i] << endl;
    cout << endl;
}

void djikstra(int graph[nodes][nodes], int start)
{
    int distance[nodes];
    bool visited[nodes];

    for (int i = 0; i < nodes; i++)
    {
        distance[i] = INT_MAX;
        visited[i] = false;
    }

    distance[start] = 0;
    for (int i = 0; i < nodes - 1; i++)
    {
        int x = findMin(distance, visited);
        visited[x] = true;
        for (int y = 0; y < nodes; y++)
        {
            if (!visited[y] && graph[x][y] && distance[x] != INT_MAX && distance[y] > distance[x] + graph[x][y])
                distance[y] = distance[x] + graph[x][y];
        }
    }
    print(distance);
}

int main()
{
    int graph[nodes][nodes] = {
        //   0, 1, 2, 3, 4, 5, 6, 7, 8
        {0, 4, 0, 0, 0, 0, 0, 8, 0},   // 0
        {4, 0, 8, 0, 0, 0, 0, 11, 0},  // 1
        {0, 8, 0, 7, 0, 4, 0, 0, 2},   // 2
        {0, 0, 7, 0, 5, 14, 0, 0, 0},  // 3
        {0, 0, 0, 8, 0, 10, 0, 0, 0},  // 4
        {0, 0, 4, 14, 10, 0, 2, 0, 0}, // 5
        {0, 0, 0, 0, 0, 2, 0, 1, 6},   // 6
        {8, 11, 0, 0, 0, 0, 1, 0, 7},  // 7
        {0, 0, 2, 0, 0, 0, 6, 7, 0}};  // 8

    djikstra(graph, 0);
}