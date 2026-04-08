/*
 * @lc app=leetcode id=417 lang=cpp
 *
 * [417] Pacific Atlantic Water Flow
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
    pair<int, int> constexpr static DIRECTIONS[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        const int m = heights.size();
        const int n = heights[0].size();
        
        queue<pair<int, int>> pacificQ;
        for (int i {0}; i < m; ++i) {
            pacificQ.push({i, 0});
        }
        for (int j {0}; j < n; ++j) {
            pacificQ.push({0, j});
        }
        vector<vector<bool>> pacificVisited = bfsVisit(heights, pacificQ);

        queue<pair<int, int>> atlanticQ;
        for (int i {0}; i < m; ++i) {
            atlanticQ.push({i, n - 1});
            // cout << i << " " << n - 1 << '\n';
        }
        for (int j {0}; j < n; ++j) {
            atlanticQ.push({m - 1, j});
            // cout << m - 1 << " " << j << '\n';
        }
        vector<vector<bool>> atlanticVisited = bfsVisit(heights, atlanticQ);

        vector<vector<int>> out;
        for (int i {0}; i < m; ++i) {
            for (int j {0}; j < n; ++j) {
                // cout << i << " " << j << " : " << pacificVisited[i][j] << " " << atlanticVisited[i][j] << '\n';
                if (pacificVisited[i][j] && atlanticVisited[i][j]) {
                    out.push_back({i, j});
                }
            }
        }

        return out;
    }
private:
    vector<vector<bool>> bfsVisit(vector<vector<int>>& heights, queue<pair<int, int>>& q) {
        const int m = heights.size();
        const int n = heights[0].size();
        
        vector<vector<bool>> visited(m, vector<bool>(n));
        while (!q.empty()) {
            const auto [i, j] = q.front();
            q.pop();
            visited[i][j] = true;

            for (const auto [di, dj] : DIRECTIONS) {
                const int ni = i + di, nj = j + dj;
                if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
                if (visited[ni][nj]) continue;
                if (heights[ni][nj] < heights[i][j]) continue;
                visited[ni][nj] = true;
                q.push({ni, nj});
            }
        }

        return visited;
    }
};
// class DSU {
//     vector<int> parent;
//     vector<int> size;

// public:
//     DSU(const int n) : parent(n), size(n, 1) {
//         iota(parent.begin(), parent.end(), 0);
//     }

//     int get_parent(const int u) {
//         if (parent[u] == u) return u;
//         return parent[u] = get_parent(parent[u]);
//     }

//     void set_union(int u, int v) {
//         if (size[u] > size[v]) swap(u, v);
//         // v > u

//         parent[u] = get_parent(parent[v]);
//         size[v] += size[u];
//     }
// };

// class Solution {
//     pair<int, int> constexpr static DIRECTIONS[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
// public:
//     vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
//         const int m = heights.size();
//         const int n = heights[0].size();

//         DSU pacificDSU(n * m);
//         for (int i {1}; i < m; ++i) {
//             pacificDSU.set_union(
//                 getCellIdx(i - 1, 0, n),
//                 getCellIdx(i, 0, n)
//             );
//         }
//         for (int j {1}; j < n; ++j) {
//             pacificDSU.set_union(
//                 getCellIdx(0, j - 1, n),
//                 getCellIdx(0, j, n)
//             );
//         }

//         DSU atlanticDSU(n);
//         for (int i {1}; i < m; ++i) {
//             pacificDSU.set_union(
//                 getCellIdx(i - 1, n - 1, n),
//                 getCellIdx(i, n - 1, n)
//             );
//         }
//         for (int j {1}; j < n; ++j) {
//             pacificDSU.set_union(
//                 getCellIdx(m - 1, j - 1, n),
//                 getCellIdx(m - 1, j, n)
//             );
//         }

//         const int pacificParent {pacificDSU.get_parent(getCellIdx(0, 0, n))};
//         const int atlanticParent {atlanticDSU.get_parent(getCellIdx(m - 1, n - 1, n))};

//         // for (int i {0}; i < m; ++i) {
//         //     for (int j {0}; j < n; ++j) {
//         //         for (const auto [di, dj] : DIRECTIONS) {
//         //             const int ni = i + di, nj = j + dj;
//         //             if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
//         //             if (heights[i][j] <= heights[ni][nj]) {
//         //                 pacificDSU.
//         //             }
//         //         }
//         //     }
//         // }
//     }
// private:
//     int getCellIdx(const int u, const int v, const int n) { return u * n + v; }
//     pair<int, int> cellIdxToPos(const int cellIdx, const int n) { return {cellIdx / n, cellIdx % n}; } 
//     void bfs(
//         const pair<int, int> source,
//         const int m,
//         const int n,
//         const vector<vector<int>>& heights,
//         DSU& dsu
//     ) {

//     }
// };
// @lc code=end

