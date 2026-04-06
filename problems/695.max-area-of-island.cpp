/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    static constexpr pair<int, int> DIRECTIONS[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        const int n = grid.size(), m = grid[0].size();
        
        int maxArea {0};
        
        for (int i {0}; i < n; ++i) {
            for (int j {0}; j < m; ++j) {
                if (grid[i][j] == 1) {
                    maxArea = max(maxArea, getArea(grid, i, j));
                };
            }
        }
        
        return maxArea;
    }
private:
    int getArea(vector<vector<int>>& grid, const int i0, const int j0) {
        const int n = grid.size(), m = grid[0].size();

        queue<pair<int, int>> q;
        q.emplace(i0, j0);
        grid[i0][j0] = 0;

        int area {0};
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            area += 1;
            
            for (auto [di, dj] : DIRECTIONS) {
                const int ni = i + di, nj = j + dj;
                if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
                if (grid[ni][nj] != 1) continue;
                grid[ni][nj] = 0;
                q.emplace(ni, nj);
            }
        }

        return area;
    }
};
// @lc code=end

