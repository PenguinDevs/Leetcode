/*
 * @lc app=leetcode id=463 lang=cpp
 *
 * [463] Island Perimeter
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
    static constexpr pair<int, int> DIRECTIONS[] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();
        for (int i {0}; i < m; ++i) {
            for (int j {0}; j < n; ++j) {
                if (grid[i][j] == 1) return dfs(grid, i, j);
            }
        }

        return 0;
    }
private:
    int dfs(
        vector<vector<int>>& grid,
        int i,
        int j
    ) {
        const int m = grid.size();
        const int n = grid[0].size();

        int perimeter {0};

        grid[i][j] = -1;
        for (const auto [di, dj] : DIRECTIONS) {
            const int ni {i + di};
            const int nj {j + dj};
            if (ni < 0 || ni >= m || nj < 0 || nj >= n) {
                ++perimeter;
                continue;
            };
            switch (grid[ni][nj]) {
                case 1:
                    perimeter += dfs(grid, ni, nj);
                    break;
                case 0:
                    perimeter += 1;
                    break;
                case -1:
                    break;
            }
        }

        return perimeter;
    }
};
// @lc code=end

