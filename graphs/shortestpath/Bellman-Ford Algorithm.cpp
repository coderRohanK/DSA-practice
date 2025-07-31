#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Edge {
    int u, v, wt;
};

void bellmanFord(int V, int E, vector<Edge>& edges, int src) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    // Relax all edges (V - 1) times
    for (int i = 0; i < V - 1; ++i) {
        for (int j = 0; j < E; ++j) {
            int u = edges[j].u;
            int v = edges[j].v;
            int wt = edges[j].wt;

            if (dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }

    // Check for negative weight cycles
    for (int j = 0; j < E; ++j) {
        int u = edges[j].u;
        int v = edges[j].v;
        int wt = edges[j].wt;

        if (dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
            cout << "Negative weight cycle detected" << endl;
            return;
        }
    }

    // Print shortest distances
    cout << "Vertex\tDistance from Source" << endl;
    for (int i = 0; i < V; ++i) {
        cout << i << "\t" << (dist[i] == INT_MAX ? -1 : dist[i]) << endl;
    }
}

int main() {
    int V = 5; // vertices
    int E = 8; // edges
    vector<Edge> edges = {
        {0, 1, -1}, {0, 2, 4},
        {1, 2, 3},  {1, 3, 2},
        {1, 4, 2},  {3, 2, 5},
        {3, 1, 1},  {4, 3, -3}
    };

    int src = 0;
    bellmanFord(V, E, edges, src);

    return 0;
}
