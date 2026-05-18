/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> valueToIdx;

        for (int i {0}; i < nums.size(); ++i) {
            const int n {nums[i]};
            if (valueToIdx.contains(target - n)) {
                return {valueToIdx[target - n], i};
            }
            valueToIdx[n] = i;
        }

        return {};

    }
};
// @lc code=end

