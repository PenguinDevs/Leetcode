/*
 * @lc app=leetcode id=1909 lang=cpp
 *
 * [1909] Remove One Element to Make the Array Strictly Increasing
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int adjInversions {0};
        int prev {nums[0]};
        for (int i {1}; i < nums.size(); ++i) {
            if (prev >= nums[i]) {
                if (adjInversions > 0) return false;
                ++adjInversions;
                
                if (i == 1 || (i > 1 && nums[i - 2] < nums[i])) {
                    prev = nums[i]; // Safe to use since 
                }
            } else {
                prev = nums[i];
            }
        }

        return true;
    }
};
// @lc code=end
