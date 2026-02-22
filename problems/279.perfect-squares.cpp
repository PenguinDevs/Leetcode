/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        const int m = sqrt(n);

        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (int i {1}; i <= n; ++i) {
            for (int j {1}; j <= (int)sqrt(i); ++j) {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }

        // for (const int x : dp) cout << x << " ";


        return dp[n];
    }
};
// @lc code=end

