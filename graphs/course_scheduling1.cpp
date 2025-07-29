#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(numCourses);
    vector<int> inDegree(numCourses, 0);
    
    // Build the graph
    for (auto& pre : prerequisites) {
        adj[pre[1]].push_back(pre[0]);
        inDegree[pre[0]]++;
    }
    
    queue<int> q;
    
    // Push all courses with no prerequisites
    for (int i = 0; i < numCourses; ++i) {
        if (inDegree[i] == 0)
            q.push(i);
    }
    
    int count = 0;
    
    while (!q.empty()) {
        int course = q.front(); q.pop();
        count++;
        for (int neighbor : adj[course]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0)
                q.push(neighbor);
        }
    }
    
    return count == numCourses;
}

int main() {
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1, 0}, {2, 1}, {3, 2}};
    
    if (canFinish(numCourses, prerequisites))
        cout << "All courses can be finished.\n";
    else
        cout << "Cannot finish all courses.\n";

    return 0;
}
