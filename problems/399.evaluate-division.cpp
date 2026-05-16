/*
 * @lc app=leetcode id=399 lang=cpp
 *
 * [399] Evaluate Division
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<double> calcEquation(
        vector<vector<string>>& equations,
        vector<double>& values,
        vector<vector<string>>& queries
    ) {
        unordered_map<string,int> id;
        vector<vector<pair<int, double>>> adjList = buildAdjList(equations, values, id);

        vector<double> queryResults;
        for (const auto& query : queries) {
            const string &s = query[0];
            const string &t = query[1];
            if (id.find(s) == id.end() || id.find(t) == id.end()) {
                queryResults.push_back(-1.0);
                continue;
            }
            const int u = id[s];
            const int v = id[t];
            vector<bool> visited(adjList.size());
            visited[u] = true;
            queryResults.push_back(dfs(adjList, u, v, visited));
        }

        return queryResults;
    }
private:
    vector<vector<pair<int, double>>> buildAdjList(
        vector<vector<string>>& equations,
        vector<double>& values,
        unordered_map<string,int>& id
    ) {
        int nextId = 0;
        for (const auto &p : equations) {
            if (id.find(p[0]) == id.end()) id[p[0]] = nextId++;
            if (id.find(p[1]) == id.end()) id[p[1]] = nextId++;
        }

        vector<vector<pair<int, double>>> adjList(nextId);

        for (int i = 0; i < (int)equations.size(); ++i) {
            const auto &pair = equations[i];
            const int u = id[pair[0]];
            const int v = id[pair[1]];
            const double value = values[i];

            adjList[u].push_back({v, value});
            adjList[v].push_back({u, 1.0 / value});
        }

        return adjList;
    }

    double dfs(
        vector<vector<pair<int, double>>>& adjList,
        const int root,
        const int target,
        vector<bool>& visited,
        const double result = 1.0
    ) {
        if (root == target) return result;

        for (const auto& [neighbour, factor] : adjList[root]) {
            if (visited[neighbour]) continue;
            visited[neighbour] = true;
            const double neighbourResult = dfs(adjList, neighbour, target, visited, result * factor);
            if (neighbourResult != -1.0) return neighbourResult;
            visited[neighbour] = false;
        }

        return -1.0;
    }
};
// @lc code=end

