#include <iostream>
#include <vector>
using namespace std;

class DSU {
    vector<int> parent, rank;
public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // Path compression
        return parent[x];
    }

    bool unite(int x, int y) {
        int xr = find(x);
        int yr = find(y);
        if (xr == yr) return false; // cycle detected

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

bool hasCycle(int V, vector<pair<int, int>>& edges) {
    DSU dsu(V);
    for (auto edge : edges) {
        if (!dsu.unite(edge.first, edge.second)) {
            return true; // cycle found
        }
    }
    return false;
}

int main() {
    int V = 5; // number of vertices
    vector<pair<int, int>> edges = {
        {0, 1},
        {1, 2},
        {2, 3},
        {3, 4},
        {4, 1} // This edge introduces a cycle
    };

    if (hasCycle(V, edges))
        cout << "Graph contains cycle\n";
    else
        cout << "Graph doesn't contain cycle\n";

    return 0;
}
