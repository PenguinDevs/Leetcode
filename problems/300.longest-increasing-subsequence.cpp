/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        const int n = nums.size();
        
        vector<int> dp;
        dp.push_back(nums[0]);

        int count {1};
        for (int i {1}; i < n; ++i) {
            if (dp.back() < nums[i]) {
                dp.push_back(nums[i]);
                count += 1;
                continue;
            }

            const int insertionIdx = lower_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
            dp[insertionIdx] = nums[i];
        }

        return count;
    }
};
// @lc code=end

