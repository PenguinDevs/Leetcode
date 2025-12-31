/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        const int n = obstacleGrid.size();
        const int m = obstacleGrid[0].size();

        if (obstacleGrid[0][0]) return 0;

        vector<int> prevRow(m);
        vector<int> dp(m);
        dp[0] = 1;

        for (int i {0}; i < n; ++i) {
            for (int j {0}; j < m; ++j) {
                if (obstacleGrid[i][j]) continue;
                if (j > 0) dp[j] += dp[j - 1];
                if (i > 0) dp[j] += prevRow[j];
            }

            swap(dp, prevRow);
            memset(dp.data(), 0, dp.size() * sizeof(int));
        }

        return prevRow[m - 1];
    }
};
// @lc code=end

