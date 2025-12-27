/*
 * @lc app=leetcode id=329 lang=cpp
 *
 * [329] Longest Increasing Path in a Matrix
 * 
 * // NOTE: Lesson learnt: see if the problem can be solved with top sort
 */

#include <bits/stdc++.h>
using namespace std;


// @lc code=start
class Solution {
private:
    struct TopSortEntry {
        const int i;
        const int j;
        const int len;
    };
public:
    static constexpr array<pair<int, int>, 4> directions = {{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        const int n = matrix.size();
        const int m = matrix[0].size();

        vector<vector<int>> indegree(n, vector<int>(m));
        for (int i {0}; i < n; ++i) {
            for (int j {0}; j < m; ++j) {
                for (const auto [di, dj] : directions) {
                    const int ci = i + di;
                    const int cj = j + dj;
                    if (ci < 0 || ci >= n || cj < 0 || cj >= m) continue;

                    if (matrix[ci][cj] > matrix[i][j]) {
                        ++indegree[ci][cj];
                    }
                }
            }
        }

        queue<TopSortEntry> topSortQ;
        for (int i {0}; i < n; ++i) {
            for (int j {0}; j < m; ++j) {
                if (indegree[i][j] == 0) topSortQ.push({i, j, 1});
            }
        }

        int longestLen {0};
        while (!topSortQ.empty()) {
            const auto [i, j, len] = topSortQ.front();
            topSortQ.pop();

            longestLen = max(longestLen, len);

            for (const auto [di, dj] : directions) {
                const int ci = i + di;
                const int cj = j + dj;
                if (ci < 0 || ci >= n || cj < 0 || cj >= m) continue;

                if (matrix[ci][cj] > matrix[i][j]) {
                    --indegree[ci][cj];
                
                    if (indegree[ci][cj] == 0) topSortQ.push({ci, cj, len + 1});
                }
            }
        }

        return longestLen;
    }
};

// struct MultiTreeNode {
//     int indegree;
//     vector<MultiTreeNode*> children;
// };

// class Solution {
// public:
//     int longestIncreasingPath(vector<vector<int>>& matrix) {
//         const int n = matrix.size();
//         const int m = matrix[0].size();

//         vector<vector<MultiTreeNode*>> nodes(n, vector<MultiTreeNode*>(m));
//         for (int i {0}; i < n; ++i) {
//             for (int j {0}; j < m; ++j) {
//                 nodes[i][j] = new MultiTreeNode();
//                 if (i > 0) {
//                     if (matrix[i - 1][j] > matrix[i][j]) {
//                         nodes[i][j]->children.push_back(nodes[i - 1][j]);
//                         ++nodes[i - 1][j]->indegree;
//                     } else if (matrix[i - 1][j] < matrix[i][j]) {
//                         nodes[i - 1][j]->children.push_back(nodes[i][j]);
//                         ++nodes[i][j]->indegree;
//                     }
//                 }
//                 if (j > 0) {
//                     if (matrix[i][j - 1] > matrix[i][j]) {
//                         nodes[i][j]->children.push_back(nodes[i][j - 1]);
//                         ++nodes[i][j-1]->indegree;
//                     } else if (matrix[i][j - 1] < matrix[i][j]) {
//                         nodes[i][j - 1]->children.push_back(nodes[i][j]);
//                         ++nodes[i][j]->indegree;
//                     }
//                 }
//             }
//         }
        
//         queue<pair<int, MultiTreeNode*>> topSortQ;
//         for (int i {0}; i < n; ++i) {
//             for (int j {0}; j < m; ++j) {
//                 if (nodes[i][j]->indegree == 0) topSortQ.push({1, nodes[i][j]});
//             }
//         }

//         int longestLen {0};
//         while (!topSortQ.empty()) {
//             auto [len, node] = topSortQ.front();
//             topSortQ.pop();

//             longestLen = max(longestLen, len);

//             for (MultiTreeNode* child : node->children) {
//                 --child->indegree;
//                 if (child->indegree == 0) {
//                     topSortQ.push({len + 1, child});
//                 }
//             }
//         }

//         return longestLen;
//     }
// };
// struct MultiTreeNode {
//     int i;
//     int j;
//     vector<MultiTreeNode*> parents;
// };

// class Solution {
// public:
//     int longestIncreasingPath(vector<vector<int>>& matrix) {
//         const int n = matrix.size();
//         const int m = matrix[0].size();
//         vector<vector<MultiTreeNode*>> nodes(n, vector<MultiTreeNode*>(m));

//         for (int i {0}; i < n; ++i) {
//             for (int j {0}; j < m; ++j) {
//                 nodes[i][j] = new MultiTreeNode();
//                 nodes[i][j]->i = i;
//                 nodes[i][j]->j = j;
//                 if (i > 0) {
//                     if (matrix[i - 1][j] > matrix[i][j]) {
//                         nodes[i - 1][j]->parents.push_back(nodes[i][j]);
//                     } else if (matrix[i - 1][j] < matrix[i][j]) {
//                         nodes[i][j]->parents.push_back(nodes[i - 1][j]);
//                     }
//                 }
//                 if (j > 0) {
//                     if (matrix[i][j - 1] > matrix[i][j]) {
//                         nodes[i][j - 1]->parents.push_back(nodes[i][j]);
//                     } else if (matrix[i][j - 1] < matrix[i][j]) {
//                         nodes[i][j]->parents.push_back(nodes[i][j - 1]);
//                     }
//                 }
//             }
//         }

//         stack<pair<int, MultiTreeNode*>> dfsStack;
//         for (int i {0}; i < n; ++i) {
//             for (int j {0}; j < m; ++j) {
//                 // cout << matrix[i][j] << ": " << nodes[i][j]->children.size() << endl;
//                 if (nodes[i][j]->parents.size() == 0) {
//                     dfsStack.push({1, nodes[i][j]});
//                 }
//             }
//         }

//         vector<vector<int>> dp(n, vector<int>(m));
//         int longestLen {0};
//         while (!dfsStack.empty()) {
//             const auto [len, node] = dfsStack.top();
//             dfsStack.pop();

//             if (dp[node->i][node->j] >= len) continue;
//             dp[node->i][node->j] = len;
//             longestLen = max(longestLen, len);

//             for (MultiTreeNode* parent : node->parents) {
//                 dfsStack.push({len + 1, parent});
//             }
//         }

//         return longestLen;
//     }
// };
// @lc code=end

