/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int i {0}; i < nums.size(); ++i) {
            const int idx {abs(nums[i]) - 1};
            nums[idx] *= -1;
            if (nums[idx] > 0) return abs(nums[i]);
        }
        return -1;
    }
};
// @lc code=end

