#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
};

bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

// Disjoint Set Union (Union-Find)
class DSU {
    vector<int> parent, rank;
public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // path compression
        return parent[x];
    }

    bool unite(int x, int y) {
        int xr = find(x);
        int yr = find(y);
        if (xr == yr) return false;

        if (rank[xr] < rank[yr])
            parent[xr] = yr;
        else if (rank[xr] > rank[yr])
            parent[yr] = xr;
        else {
            parent[yr] = xr;
            rank[xr]++;
        }
        return true;
    }
};

int kruskalMST(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end(), compare); // sort by weight
    DSU dsu(n);

    int totalWeight = 0;
    for (Edge e : edges) {
        if (dsu.unite(e.u, e.v)) {
            totalWeight += e.weight;
        }
    }
    return totalWeight;
}

int main() {
    int n = 5; // number of vertices

    vector<Edge> edges = {
        {0, 1, 2},
        {0, 3, 6},
        {1, 2, 3},
        {1, 3, 8},
        {1, 4, 5},
        {2, 4, 7}
    };

    cout << "Total weight of MST: " << kruskalMST(n, edges) << endl;
    return 0;
}
