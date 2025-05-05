#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(vector<int> graph[], int start, int nodes)
{
    vector<bool> visited(nodes, false);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int x = q.front();
        cout << x << " ";
        q.pop();
        for (int neighbour : graph[x])
        {
            if (!visited[neighbour])
            {
                q.push(neighbour);
                visited[neighbour] = true;
            }
        }
    }
}

int main()
{
    vector<int> graph[8];
    graph[1] = {2, 4, 3};
    graph[2] = {4, 5};
    graph[3] = {6};
    graph[4] = {3, 6, 7};
    graph[5] = {4, 7};
    graph[6] = {};
    graph[7] = {6};

    BFS(graph, 1, 7);
}
