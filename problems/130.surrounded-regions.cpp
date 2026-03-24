/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
// class DSU {
//     vector<int> parent;
//     vector<int> size;
// public:
//     DSU(const int n) : parent(n), size(n, 1) {
//         iota(parent.begin(), parent.end(), 0);
//     }

//     int get_parent(const int u) {
//         if (u == parent[u]) return u;
        
//         parent[u] = get_parent(parent[u]);
//         return parent[u];
//     }

//     void set_union(int u, int v) {
//         if (size[u] > size[v]) {
//             swap(u, v);
//         }
//         // u < v

//         size[v] += size[u];
//         parent[get_parent(u)] = get_parent(v);
//     }
// };

class Solution {
    static constexpr pair<int, int> directions[] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
// public:
//     void solve(vector<vector<char>>& board) {
//         const int m = board.size();
//         const int n = board[0].size();

//         DSU dsu(n * m);
//         for (int i {0}; i < m; ++i) {
//             for (int j {0}; j < n; ++j) {
//                 if (board[i][j] != 'O') continue;
//                 for (const auto [di, dj] : directions) {
//                     const int ni = i + di;
//                     const int nj = j + dj;
//                     if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
//                     if (board[ni][nj] != 'O') continue;

//                     dsu.set_union(i * n + j, ni * n + nj);
//                 }
//             }
//         }

//         vector<bool> exclude(n * m);
//         for (int i {0}; i < m; ++i) {
//             for (const int j : {0, n - 1}) {
//                 exclude[dsu.get_parent(i * n + j)] = true;
//             }
//         }

//         for (int j {0}; j < n; ++j) {
//             for (const int i : {0, m - 1}) {
//                 exclude[dsu.get_parent(i * n + j)] = true;
//             }
//         }

//         for (int i {0}; i < m; ++i) {
//             for (int j {0}; j < n; ++j) {
//                 if (!exclude[dsu.get_parent(i * n + j)]) {
//                     board[i][j] = 'X';
//                 }
//             }
//         }
//     }
public:
    void solve(vector<vector<char>>& board) {
        mark(board);
        removeCircles(board);
        resetMarkings(board);
    }
private:
    void mark(vector<vector<char>>& board) {
        const int m = board.size();
        const int n = board[0].size();

        // for (int i {0}; i < m; ++i) {
        //     for (int j {0}; j < n; ++j) {
        //         if (board[i][j] != 'O') continue;
                
        //     }
        // }

        priority_queue<pair<int, int>> q;
        for (int i {0}; i < m; ++i) {
            for (const int j : {0, n - 1}) {
                if (board[i][j] != 'O') continue;
                board[i][j] = 'M';
                q.push({i, j});
            }
        }

        for (int j {0}; j < n; ++j) {
            for (const int i : {0, m - 1}) {
                if (board[i][j] != 'O') continue;
                board[i][j] = 'M';
                q.push({i, j});
            }
        }

        while (!q.empty()) {
            const auto [i, j] = q.top();
            q.pop();
            for (const auto [di, dj] : directions) {
                const int ni = i + di;
                const int nj = j + dj;
                if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
                if (board[ni][nj] != 'O') continue;
                board[ni][nj] = 'M';
                q.push({ni, nj});
            }
        }
    }

    void removeCircles(vector<vector<char>>& board) {
        const int m = board.size();
        const int n = board[0].size();

        for (int i {0}; i < m; ++i) {
            for (int j {0}; j < n; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }

    void resetMarkings(vector<vector<char>>& board) {
        const int m = board.size();
        const int n = board[0].size();

        for (int i {0}; i < m; ++i) {
            for (int j {0}; j < n; ++j) {
                if (board[i][j] == 'M') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
// @lc code=end

