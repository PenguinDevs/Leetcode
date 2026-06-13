/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int replaceAt {0};
        for (int i {1}; i < nums.size(); ++i) {
            if (nums[i - 1] != nums[i]) {
                ++replaceAt;
                nums[replaceAt] = nums[i];
            }
        }

        const int leftoverCount = nums.size() - replaceAt - 1;
        for (int i {0}; i < leftoverCount; ++i) {
            nums.pop_back();
        }

        return nums.size();
    }
};
// @lc code=end

