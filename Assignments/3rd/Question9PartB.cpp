#include <iostream>
#include <climits>
using namespace std;

const int nodes = 11;

int findMinKey(int key[nodes], bool mstKeys[nodes])
{
    int minIndex = -1;
    int minimum = INT_MAX;

    for (int i = 0; i < nodes; i++)
    {
        if (!mstKeys[i] && key[i] < minimum)
        {
            minIndex = i;
            minimum = key[i];
        }
    }
    return minIndex;
}

void printMST(int parent[nodes], int graph[nodes][nodes])
{
    cout << "Edge\tWeight" << endl;
    for (int i = 1; i < nodes; i++)
        cout << char(parent[i] + 'A') << " - " << char(i + 'A') << "\t" << graph[parent[i]][i] << endl;
}

void primMST(int graph[nodes][nodes])
{
    int key[nodes];
    int parent[nodes];
    bool mstKeys[nodes];

    for (int i = 0; i < nodes; i++)
    {
        key[i] = INT_MAX;
        mstKeys[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int i = 0; i < nodes - 1; i++)
    {
        int x = findMinKey(key, mstKeys);
        mstKeys[x] = true;

        for (int y = 0; y < nodes; y++)
        {
            if (graph[x][y] && !mstKeys[y] && graph[x][y] < key[y])
            {
                key[y] = graph[x][y];
                parent[y] = x;
            }
        }
    }

    printMST(parent, graph);
}

int main()
{
    int graph[nodes][nodes] = {
        // A, B, C, D, E, F, G, H, I, J, K
        {0, 3, 4, 0, 0, 5, 0, 0, 0, 0, 0},
        {3, 0, 0, 6, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0},
        {0, 6, 0, 0, 3, 0, 5, 6, 0, 0, 0},
        {0, 0, 0, 3, 0, 0, 4, 0, 0, 0, 0},
        {5, 0, 3, 0, 0, 0, 0, 8, 0, 0, 7},
        {0, 0, 0, 5, 4, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 6, 0, 8, 0, 0, 7, 0, 0},
        {0, 0, 0, 0, 0, 0, 2, 7, 0, 6, 0},
        {0, 8, 0, 0, 0, 0, 8, 0, 6, 0, 8},
        {0, 0, 0, 0, 0, 7, 0, 0, 0, 8, 0}};

    primMST(graph);

    return 0;
}
