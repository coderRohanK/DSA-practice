#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii; // (weight, node)

// Prim's Algorithm to compute MST total weight
int primMST(int n, vector<vector<pii>>& adj) {
    vector<bool> inMST(n, false); // track visited nodes
    priority_queue<pii, vector<pii>, greater<pii>> pq; // min-heap: (weight, node)
    
    int totalWeight = 0;
    pq.push({0, 0}); // Start with node 0 and weight 0

    while (!pq.empty()) {
        auto [weight, node] = pq.top();
        pq.pop();

        if (inMST[node]) continue; // Skip if already added
        inMST[node] = true;
        totalWeight += weight;

        for (auto [neighbor, edgeWeight] : adj[node]) {
            if (!inMST[neighbor]) {
                pq.push({edgeWeight, neighbor});
            }
        }
    }

    return totalWeight;
}

int main() {
    int n = 5; // number of nodes
    vector<vector<pii>> adj(n); // adjacency list

    // Undirected weighted edges
    adj[0].push_back({1, 2});
    adj[1].push_back({0, 2});

    adj[0].push_back({3, 6});
    adj[3].push_back({0, 6});

    adj[1].push_back({2, 3});
    adj[2].push_back({1, 3});

    adj[1].push_back({3, 8});
    adj[3].push_back({1, 8});

    adj[1].push_back({4, 5});
    adj[4].push_back({1, 5});

    adj[2].push_back({4, 7});
    adj[4].push_back({2, 7});

    // Run Prim's algorithm
    cout << "Total weight of MST: " << primMST(n, adj) << endl;
    return 0;
}
