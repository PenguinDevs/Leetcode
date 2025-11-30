/*
 * @lc app=leetcode id=2435 lang=cpp
 *
 * [2435] Paths in Matrix Whose Sum Is Divisible by K
 *
 * NOTE: Improvement to typical 3D DP is to use rolling arrays instead of
 * storing everything.
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        // Rolling arrays
        vector<vector<int>> previousRow;
        vector<vector<int>> currentRow(m, vector<int>(k, 0));

        currentRow[0][grid[0][0] % k] = 1;

        constexpr int MOD = 1e9 + 7;

        for (int i {0}; i < n; ++i) {
            for (int j {0}; j < m; ++j) {
                for (int rem {0}; rem < k; ++rem) {
                    int newRem = (rem + grid[i][j]) % k;

                    if (i > 0) {
                        // Going down
                        currentRow[j][newRem] = (currentRow[j][newRem] + previousRow[j][rem]) % MOD;
                    }
                    if (j > 0) {
                        // Going right
                        currentRow[j][newRem] = (currentRow[j][newRem] + currentRow[j - 1][rem]) % MOD;
                    }
                }
            }

            // previousRow = currentRow;
            swap(previousRow, currentRow);
            currentRow.assign(m, vector<int>(k, 0));
        }

        return previousRow[m - 1][0];
    }
    // int numberOfPaths(vector<vector<int>>& grid, int k) {
    //     int n = grid.size();
    //     int m = grid[0].size();

    //     vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k, 0)));

    //     dp[0][0][grid[0][0] % k] = 1;

    //     constexpr int MOD = 1e9 + 7;

    //     for (int i {0}; i < n; ++i) {
    //         for (int j {0}; j < m; ++j) {
    //             for (int rem {0}; rem < k; ++rem) {
    //                 int newRem = (rem + grid[i][j]) % k;

    //                 if (i > 0) {
    //                     // Going down
    //                     dp[i][j][newRem] = (dp[i][j][newRem] + dp[i - 1][j][rem]) % MOD;
    //                 }
    //                 if (j > 0) {
    //                     // Going right
    //                     dp[i][j][newRem] = (dp[i][j][newRem] + dp[i][j - 1][rem]) % MOD;
    //                 }
    //             }
    //         }
    //     }

    //     return dp[n - 1][m - 1][0];
    // }
};
// @lc code=end

