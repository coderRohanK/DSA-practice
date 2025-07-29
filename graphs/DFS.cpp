#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfsIterative(int start, vector<vector<int>>& adj, vector<bool>& visited) {
    stack<int> st;
    st.push(start);

    while (!st.empty()) {
        int node = st.top();
        st.pop();

        if (!visited[node]) {
            visited[node] = true;
            cout << node << " ";

            // Push neighbors in reverse to match recursive DFS order
            for (int i = adj[node].size() - 1; i >= 0; --i) {
                int neighbor = adj[node][i];
                if (!visited[neighbor]) {
                    st.push(neighbor);
                }
            }
        }
    }
}

int main() {
    int n = 6; // number of nodes
    vector<vector<int>> adj(n);

    // Example undirected edges
    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0, 4};
    adj[3] = {1, 5};
    adj[4] = {2};
    adj[5] = {3};

    vector<bool> visited(n, false);

    cout << "Iterative DFS starting from node 0: ";
    dfsIterative(0, adj, visited);

    return 0;
}

