/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX / 2);
        dp[0] = 0;

        for (int target {0}; target <= amount; ++target) {
            for (const int c : coins) {
                if (target - c < 0) continue;
                dp[target] = min(dp[target], dp[target - c] + 1);
            }
        }

        // for (const int x : dp) cout << x << " ";

        return dp[amount] != INT_MAX / 2 ? dp[amount] : -1;
    }
};
// @lc code=end

