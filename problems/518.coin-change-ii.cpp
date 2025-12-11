/*
 * @lc app=leetcode id=518 lang=cpp
 *
 * [518] Coin Change II
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

        vector<unsigned long long> dp(dpSize, 0);
        dp[0] = 1;

        for (const int c : coins) {
            for (int i {c}; i < dpSize; ++i) {
                dp[i] += dp[i - c];
            }
        }

        // for (int n : dp) cout << n << " ";
        // cout <<endl;

        return dp[amount];
    }
};
// @lc code=end

