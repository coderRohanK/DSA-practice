#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}

int main() {
    int n = 6; // number of nodes
    vector<vector<int>> adj(n);

    // Example edges (undirected)
    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0, 4};
    adj[3] = {1, 5};
    adj[4] = {2};
    adj[5] = {3};

    vector<bool> visited(n, false);

    cout << "DFS starting from node 0: ";
    dfs(0, adj, visited);

    return 0;
}
