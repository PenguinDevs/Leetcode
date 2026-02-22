/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), greater<int>());

        return nums[k - 1];
    }
};
// @lc code=end

