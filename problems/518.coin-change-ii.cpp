/*
 * @lc app=leetcode id=518 lang=cpp
 *
 * [518] Coin Change II
 *
 * NOTE: The order of the nested loop matters which is not obvious initially and
 * you'll need to simulate it to realise why.
 * NOTE: Was meant to be a 2D array problem.
 * NOTE: LeetNeet optimised DP has a different interpretation and solution with
 * the 2D dp as a rolling array version at like 11:30
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        static const int maxLength {300};
        static const int maxValue {5000};
        const int dpSize {amount + 1};

        vector<int> dp(dpSize, 0);
        dp[0] = 1;

        // for (int i {0}; i < dpSize; ++i) {
        //     for (int j {0}; j < coins.size(); ++j) {
        //         if (i + coins[j] > amount) continue;
        //         dp[i + coins[j]] += dp[i];
        //     }
        // }

        for (const int c : coins) {
            for (int i {c}; i < dpSize; ++i) {
                dp[i] += dp[i - c];
            }
        }

        for (int n : dp) cout << n << " ";

        return dp[amount];
    }
};
// @lc code=end

