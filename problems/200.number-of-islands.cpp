/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
    static constexpr pair<int, int> DIRECTIONS[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    int numIslands(vector<vector<char>>& grid) {
        const int n = grid.size(), m = grid[0].size();
        
        int islands {0};

        for (int i {0}; i < n; ++i) {
            for (int j {0}; j < m; ++j) {
                if (grid[i][j] == '1') {
                    markRemoved(grid, i, j);
                    ++islands;
                };
            }
        }

        return islands;
    }
private:
    void markRemoved(vector<vector<char>>& grid, const int i0, const int j0) {
        const int n = grid.size(), m = grid[0].size();

        queue<pair<int, int>> q;
        q.emplace(i0, j0);
        grid[i0][j0] = '0';

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            
            for (auto [di, dj] : DIRECTIONS) {
                const int ni = i + di, nj = j + dj;
                if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
                if (grid[ni][nj] != '1') continue;
                grid[ni][nj] = '0';
                q.emplace(ni, nj);
            }
        }
    }
};
// @lc code=end

