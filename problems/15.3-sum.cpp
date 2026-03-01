/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> sols;
        const int n = nums.size();
        for (int i {0}; i < n - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            int j {i + 1};
            int k {n - 1};
            while (j < k) {
                const int sum = nums[i] + nums[j] + nums[k];
                if (sum > 0) {
                    --k;
                } else if (sum < 0) {
                    ++j;
                } else {
                    vector<int> triplet = {nums[i], nums[j], nums[k]};
                    sols.push_back(triplet);
                    --k;
                    ++j;
                    while (j < k && nums[j] == nums[j - 1]) ++j;
                }
            }
            
            // while (i + 1 < n && nums[i] == nums[i + 1]) ++i;
        }

        return sols;
    }
};
// @lc code=end

