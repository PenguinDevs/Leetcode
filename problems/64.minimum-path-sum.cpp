/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid[0].size();
        
        vector<int> prevRow(n, INT_MAX);
        vector<int> currRow(n);
        for (int i {0}; i < m; ++i) {
            for (int j {0}; j < n; ++j) {
                if (i == 0 && j == 0) continue;
                currRow[j] = min(
                    j > 0 ? currRow[j - 1] + grid[i][j - 1] : INT_MAX,
                    i > 0 ? prevRow[j] + grid[i - 1][j] : INT_MAX
                );
            }
            swap(prevRow, currRow);
            memset(currRow.data(), 0, currRow.size() * sizeof(int));
        }

        return prevRow[n - 1] + grid[m - 1][n - 1];
    }
};
// @lc code=end

