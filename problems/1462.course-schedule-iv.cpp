/*
 * @lc app=leetcode id=1462 lang=cpp
 *
 * [1462] Course Schedule IV
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<bool> checkIfPrerequisite(
        int numCourses,
        vector<vector<int>>& prerequisites,
        vector<vector<int>>& queries
    ) {
        vector<int> indegree(100);
        vector<vector<int>> adjacencyList(100);
        vector<bitset<100>> queryLookup(100);
        for (const auto& edge : prerequisites) {
            ++indegree[edge[1]];
            adjacencyList[edge[0]].push_back(edge[1]);
            queryLookup[edge[1]].set(edge[0]);
        }

        queue<int> q;
        for (int node {0}; node < 100; ++node) {
            if (indegree[node] == 0) q.push(node);
        }

        while (!q.empty()) {
            const int curr = q.front(); q.pop();
            for (const int neighbour : adjacencyList[curr]) {
                if (--indegree[neighbour] == 0) q.push(neighbour);
                queryLookup[neighbour] |= queryLookup[curr];
            }
        }

        vector<bool> result;
        for (const auto& query : queries) {
            result.push_back(queryLookup[query[1]].test(query[0]));
        }

        return result;
    }
};
// class Solution {
// public:
//     vector<bool> checkIfPrerequisite(
//         int numCourses,
//         vector<vector<int>>& prerequisites,
//         vector<vector<int>>& queries
//     ) {
//         vector<vector<bool>> queryLookups(100, vector<bool>(100));
//         vector<vector<int>> adjacencyList(100);
//         for (const auto& edge : prerequisites) {
//             adjacencyList[edge[0]].push_back(edge[1]);
//             queryLookups[edge[0]][edge[1]] = true;
//         }
        
//         for (int k {0}; k < 100; ++k) {
//             for (int i {0}; i < 100; ++i) {
//                 for (int j {0}; j < 100; ++j) {
//                     if (queryLookups[i][j]) continue;
//                     queryLookups[i][j] = queryLookups[i][k] && queryLookups[k][j];
//                 }
//             }
//         }

//         vector<bool> result;
//         for (const auto& query : queries) {
//             result.push_back(queryLookups[query[0]][query[1]]);
//         }

//         return result;
//     }
// };
// @lc code=end

