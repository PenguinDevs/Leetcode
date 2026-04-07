/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        const int idx = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if (idx >= nums.size() || nums[idx] != target) return -1;
        return idx;
    }
};
// @lc code=end

