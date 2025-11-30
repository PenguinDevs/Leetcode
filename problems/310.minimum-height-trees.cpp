/*
 * @lc app=leetcode id=310 lang=cpp
 *
 * [310] Minimum Height Trees
 *
 * NOTE: Check out how the BFS searches layer by layer each iteration instead of
 * each node at a time like the second attempt
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};
        if (n == 2) return {0, 1};
        
        vector<vector<int>> adjacencyList(n);
        vector<int> degs(n);

        for (const auto& edge : edges) {
            adjacencyList[edge[0]].push_back(edge[1]);
            adjacencyList[edge[1]].push_back(edge[0]);
            degs[edge[0]]++;
            degs[edge[1]]++;
        }

        queue<int> leaves;
        for (int node = 0; node < n; ++node) {
            if (degs[node] == 1) {
                leaves.push(node);
            }
        }

        int remainingCount = n;
        
        // BFS Layer by layer
        while (remainingCount > 2) {
            int layerSize = leaves.size();
            remainingCount -= layerSize;
            
            // Layer by layer
            for (int i = 0; i < layerSize; ++i) {
                int leaf = leaves.front();
                leaves.pop();
                
                for (int neighbour : adjacencyList[leaf]) {
                    if (--degs[neighbour] == 1) {
                        leaves.push(neighbour);
                    }
                }
            }
        }

        vector<int> result;
        while (!leaves.empty()) {
            result.push_back(leaves.front());
            leaves.pop();
        }
        return result;
    }
};
// class Solution {
// public:
//     vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
//         vector<vector<int>> adjacencyList(n);
//         vector<int> degs(n);

//         if (n == 1) return {0};

//         for (const auto& edge : edges) {
//             adjacencyList[edge[0]].push_back(edge[1]);
//             adjacencyList[edge[1]].push_back(edge[0]);
//             degs[edge[0]]++;
//             degs[edge[1]]++;
//         }

//         int remainingCount {n};
//         // <node, depth>
//         queue<pair<int, int>> leaves;
//         for (int node {0}; node < n; ++node) {
//             if (degs[node] == 1) {
//                 leaves.push({node, 0});
//             }
//         }

//         while (remainingCount > 2) {
//             auto [leaf, depth] = leaves.front();
//             remainingCount--;
//             leaves.pop();

//             for (int neighbour : adjacencyList[leaf]) {
//                 if (degs[neighbour] > 0) {
//                     degs[neighbour]--;
//                 }

//                 if (degs[neighbour] == 1) {
//                     leaves.push({neighbour, depth + 1});
//                 }
//             }
//         }

//         if (leaves.size() == 1) {
//             return {leaves.front().first};
//         } else {
//             // Can only have two leaves remaining otherwise
//             auto [leaf1, depth1] = leaves.front();
//             leaves.pop();
//             auto [leaf2, depth2] = leaves.front();

//             // Whether they belong to the sane BFS search layer or not
//             if (depth1 == depth2) {
//                 return {leaf1, leaf2};
//             } else {
//                 return {leaf2};
//             }
//         }
//     }
// };
// class Solution {
// public:
//     vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
//         vector<vector<int>> adjacencyList(n);

//         for (const auto& edge : edges) {
//             adjacencyList[edge[0]].push_back(edge[1]);
//             adjacencyList[edge[1]].push_back(edge[0]);
//         }

//         auto [_, endpoint1] = findEndpoint(n, 0, adjacencyList);
//         auto [diameter, endpoint2] = findEndpoint(n, endpoint1, adjacencyList);

//         vector<int> path;
//         getDiameterPath(path, n, adjacencyList, endpoint1, diameter);

//         if (path.size() % 2 == 0) {
//             return {path[path.size() / 2 - 1], path[path.size() / 2]};
//         } else {
//             return {path[path.size() / 2]};
//         }
//         return {};
//     }
// private:
//     pair<int, int> findEndpoint(
//         int n,
//         int root,
//         vector<vector<int>>& adjacencyList
//     ) {
//         stack<pair<int, int>> nodes;
//         nodes.push({root, 1});

//         vector<bool> visited(n, false);

//         int longestPathLength {-1};
//         int endpoint {-1};

//         while (!nodes.empty()) {
//             auto [current, currentLength] = nodes.top();
//             nodes.pop();
//             visited[current] = true;

//             if (currentLength > longestPathLength) {
//                 longestPathLength = currentLength;
//                 endpoint = current;
//             }

//             for (int neighbour : adjacencyList[current]) {
//                 if (visited[neighbour]) continue;
//                 nodes.push({neighbour, currentLength + 1});
//             }
//         }

//         return {longestPathLength, endpoint};
//     }

//     void getDiameterPath(
//         vector<int>& path,
//         int n,
//         vector<vector<int>>& adjacencyList,
//         int endpoint1,
//         int diameter
//     ) {
//         stack<int> nodes;
//         nodes.push(endpoint1);

//         vector<bool> visited(n);

//         while (!nodes.empty()) {
//             int current = nodes.top();
//             if (visited[current] == true) {
//                 nodes.pop();
//                 path.pop_back();
//                 continue;
//             }
//             visited[current] = true;
//             path.push_back(current);

//             if (path.size() == diameter) {
//                 return;
//             }

//             for (int neighbour : adjacencyList[current]) {
//                 if (visited[neighbour]) continue;
//                 nodes.push(neighbour);
//             }
//         }
//     }
// };
// @lc code=end
