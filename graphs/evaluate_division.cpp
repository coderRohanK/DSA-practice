#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    unordered_map<string, vector<pair<string, double>>> graph;

    // DFS to find path from start to end
    double dfs(string& start, string& end, unordered_set<string>& visited, double product) {
        if (graph.find(start) == graph.end() || graph.find(end) == graph.end())
            return -1.0;
        if (start == end)
            return product;

        visited.insert(start);
        for (auto& neighbor : graph[start]) {
            if (visited.count(neighbor.first)) continue;
            double result = dfs(neighbor.first, end, visited, product * neighbor.second);
            if (result != -1.0)
                return result;
        }

        return -1.0;
    }

    vector<double> calcEquation(
        vector<vector<string>>& equations,
        vector<double>& values,
        vector<vector<string>>& queries
    ) {
        graph.clear();

        // Build graph
        for (int i = 0; i < equations.size(); i++) {
            string a = equations[i][0];
            string b = equations[i][1];
            double val = values[i];

            graph[a].push_back({b, val});
            graph[b].push_back({a, 1.0 / val});
        }

        // Process queries
        vector<double> results;
        for (auto& query : queries) {
            unordered_set<string> visited;
            double res = dfs(query[0], query[1], visited, 1.0);
            results.push_back(res);
        }

        return results;
    }
};
