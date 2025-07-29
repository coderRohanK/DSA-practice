#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor])
            dfs(neighbor, adj, visited, st);
    }
    st.push(node); // add to result stack after visiting neighbors
}

vector<int> topoSort(int V, vector<vector<int>>& adj) {
    vector<bool> visited(V, false);
    stack<int> st;

    for (int i = 0; i < V; i++) {
        if (!visited[i])
            dfs(i, adj, visited, st);
    }

    vector<int> result;
    while (!st.empty()) {
        result.push_back(st.top());
        st.pop();
    }
    return result;
}

int main() {
    int V = 6;
    vector<vector<int>> adj(V);
    // Example graph: DAG
    adj[5] = {2, 0};
    adj[4] = {0, 1};
    adj[2] = {3};
    adj[3] = {1};

    vector<int> order = topoSort(V, adj);

    cout << "Topological Sort: ";
    for (int node : order)
        cout << node << " ";
    cout << endl;

    return 0;
}
