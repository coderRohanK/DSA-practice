#include <iostream>
#include <vector>
#include <queue>
#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii; // (distance, node)

vector<int> dijkstra(int V, vector<vector<pii>>& adj, int source) {
    vector<int> dist(V, INT_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main() {
    int V = 5;
    vector<vector<pii>> adj(V);

    // Example edges: (u, v, weight)
    adj[0].push_back({1, 10});
    adj[0].push_back({4, 5});
    adj[1].push_back({2, 1});
    adj[1].push_back({4, 2});
    adj[2].push_back({3, 4});
    adj[3].push_back({2, 6});
    adj[3].push_back({0, 7});
    adj[4].push_back({1, 3});
    adj[4].push_back({2, 9});
    adj[4].push_back({3, 2});

    int source = 0;
    vector<int> dist = dijkstra(V, adj, source);

    cout << "Shortest distances from source " << source << ":\n";
    for (int i = 0; i < V; ++i) {
        cout << "Node " << i << ": " << dist[i] << "\n";
    }

    return 0;
}
