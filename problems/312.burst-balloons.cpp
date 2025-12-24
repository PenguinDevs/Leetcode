/*
 * @lc app=leetcode id=312 lang=cpp
 *
 * [312] Burst Balloons
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        const int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        // for (int i {0}; i < n; ++i) {
        //     dp[i][i] = nums[i];
        // }

        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        
        for (int i {0}; i < n; ++i) {
            // i + 1 is the middle (chosen) value
            dp[i][i] = nums[i] * nums[i + 1] * nums[i + 2];
        }
        
        return testEach(nums, dp, 0, n - 1);
    }
private:
    int testEach(const vector<int>& nums, vector<vector<int>>& dp, const int l, const int r) {
        // cout << l << " " << r << endl;
        if (dp[l][r] != -1) return dp[l][r];
        
        for (int i {l}; i <= r; ++i) {
            // i + 1 is the middle (chosen) value
            int chosenSum = nums[l] * nums[i + 1] * nums[r + 2];
            // cout << "(" << l << ":" << r << ") i@" << i << " using: " << nums[i] << "," << nums[i + 1] << "," << nums[i + 2] << endl;

            const int lSum = (i != l && l <= i - 1) ? testEach(nums, dp, l, i - 1) : 0;
            const int rSum = (i != r && i + 1 <= r) ? testEach(nums, dp, i + 1, r) : 0;
            // if (lSum == 0) chosenSum *= nums[i];
            // if (rSum == 0) chosenSum *= nums[i + 2];

            // cout << "summing: " << lSum << "," << chosenSum << "," << rSum << endl;
        
            dp[l][r] = max(dp[l][r], lSum + chosenSum + rSum);
        }

        // cout << "l:" << l << " r:" << r << " sum:" << dp[l][r] << endl;

        return dp[l][r];
    }
};
// @lc code=end

