#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(numCourses);
    vector<int> inDegree(numCourses, 0);

    // Build the graph
    for (auto& pre : prerequisites) {
        adj[pre[1]].push_back(pre[0]);
        inDegree[pre[0]]++;
    }

    queue<int> q;
    vector<int> order;

    // Push courses with no prerequisites
    for (int i = 0; i < numCourses; ++i) {
        if (inDegree[i] == 0)
            q.push(i);
    }

    while (!q.empty()) {
        int course = q.front(); q.pop();
        order.push_back(course);

        for (int neighbor : adj[course]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0)
                q.push(neighbor);
        }
    }

    if (order.size() == numCourses)
        return order;
    else
        return {};
}

int main() {
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    
    vector<int> result = findOrder(numCourses, prerequisites);
    
    if (result.empty()) {
        cout << "No valid course order exists.\n";
    } else {
        cout << "Course order: ";
        for (int course : result)
            cout << course << " ";
        cout << endl;
    }

    return 0;
}
