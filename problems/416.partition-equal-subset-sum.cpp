/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        const int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 2) return false;
        const int target = total / 2;

        vector<bool> dp(target + 1);
        dp[0] = true;
        for (int i {0}; i < nums.size(); ++i) {
            for (int j = dp.size(); j >= 0; --j) {
                if (j - nums[i] >= 0) dp[j] = dp[j - nums[i]] || dp[j];
            }
            // for (const int x : dp) cout << x << ' ';
            // cout << '\n';
        }

        return dp[target];
    }
};
// @lc code=end

