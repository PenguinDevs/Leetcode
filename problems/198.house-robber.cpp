/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int includePrevious {nums[0]};
        int notIncludePrevious {0};

        for (int i {1}; i < nums.size(); ++i) {
            int temp {includePrevious};
            includePrevious = max(notIncludePrevious + nums[i], includePrevious - nums[i - 1] + nums[i]);
            notIncludePrevious = temp;
        }

        return max(includePrevious, notIncludePrevious);
    }
};
// @lc code=end

