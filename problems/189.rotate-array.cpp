/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 * 
 * NOTE: The O(1) space time comp sol below below is interesting
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    // void rotate(vector<int>& nums, int k) {
    //     vector<int> output(nums.size());
    //     for (int i {0}; i < nums.size(); ++i) {
    //         output[(i + k) % nums.size()] = nums[i];
    //     }

    //     for (int i {0}; i < output.size(); ++i) {
    //         nums[i] = output[i];
    //     }
    // }

    void rotate(vector<int>& nums, int k) {
        const int n = nums.size();
        if (n <= 1) return;

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k % n);
        reverse(nums.begin() + k % n, nums.end());
    }
};
// @lc code=end

