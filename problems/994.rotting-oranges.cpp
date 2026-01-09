/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
enum OrangeStatus {
    Empty,
    Fresh,
    Rotting
};

class Solution {
public:
    static constexpr array<array<int, 2>, 4> directions = {{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};

    int orangesRotting(vector<vector<int>>& grid) {
        const int n = grid.size();
        const int m = grid[0].size();
        
        // {{i, j}, minutes}
        queue<pair<pair<int, int>, int>> bfs;
        for (int i {0}; i < n; ++i) {
            for (int j {0}; j < m; ++j) {
                if (grid[i][j] == OrangeStatus::Rotting) {
                    bfs.push({{i, j}, 0});
                }
            }
        }

        int currentMinute {0};
        while (!bfs.empty()) {
            const auto [pos, minute] = bfs.front();
            // cout << pos.first << " " << pos.second << " " << minute << endl;
            const auto [i, j] = pos;
            bfs.pop();
            currentMinute = minute;

            for (const auto [di, dj] : directions) {
                const int ni = i + di;
                const int nj = j + dj;
                if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;

                if (grid[ni][nj] != OrangeStatus::Fresh) continue;
                grid[ni][nj] = OrangeStatus::Rotting;
                bfs.push({{ni, nj}, minute + 1});
            }
        }

        for (int i {0}; i < n; ++i) {
            for (int j {0}; j < m; ++j) {
                if (grid[i][j] == OrangeStatus::Fresh) {
                    return -1;
                }
            }
        }

        return currentMinute;
    }
};
// @lc code=end

