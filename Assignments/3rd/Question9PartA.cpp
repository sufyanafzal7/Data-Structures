#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int nodes = 11;

class DSU
{
    int *parent;
    int *rank;

public:
    DSU(int n)
    {
        parent = new int[n];
        rank = new int[n];
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int i)
    {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }

    void unite(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY)
        {
            if (rank[rootX] < rank[rootY])
            {
                parent[rootX] = rootY;
            }
            else if (rank[rootX] > rank[rootY])
            {
                parent[rootY] = rootX;
            }
            else
            {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

class Edge
{
public:
    int weight, u, v;
    Edge(int weight, int u, int v) : weight(weight), u(u), v(v) {}
};

void kruskalMST(vector<Edge> &edges, int V)
{
    DSU dsu(V);
    int mstWeight = 0;
    cout << "Following are the edges in the constructed MST:" << endl;

    sort(edges.begin(), edges.end(), [](Edge a, Edge b)
         { return a.weight < b.weight; });

    for (Edge e : edges)
    {
        int u = e.u;
        int v = e.v;
        int weight = e.weight;

        if (dsu.find(u) != dsu.find(v))
        {
            dsu.unite(u, v);
            mstWeight += weight;
            cout << char(u + 'A') << " -- " << char(v + 'A') << " == " << weight << endl;
        }
    }

    cout << "Minimum Cost Spanning Tree: " << mstWeight << endl;
}

int main()
{
    int graph[nodes][nodes] = {
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

    vector<Edge> edges;
    for (int i = 0; i < nodes; i++)
    {
        for (int j = i + 1; j < nodes; j++)
        {
            if (graph[i][j] != 0)
            {
                edges.push_back(Edge(graph[i][j], i, j));
            }
        }
    }

    kruskalMST(edges, nodes);

    return 0;
}
