/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);

        int greatest {0};
        for (int i {0}; i < nums.size(); ++i) {
            greatest = max(greatest, robOneCycle(nums, i));
        }

        return greatest;
    }
private:
    int robOneCycle(vector<int>& nums, int startIdx) {
        int prev2 {0};
        int prev1 {0};
        
        for (int i {startIdx}; i < startIdx + nums.size() - 1; ++i) {
            int curr {max(prev1, prev2 + nums[i % nums.size()])};
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};
// @lc code=end

