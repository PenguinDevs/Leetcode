/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k {0};
        int i {0};
        while (i < nums.size()) {
            if (nums[i] == val) {
                nums[i] = nums.back();
                nums.pop_back();
                ++k;
            } else ++i;
        }

        return nums.size();
    }
};
// @lc code=end

