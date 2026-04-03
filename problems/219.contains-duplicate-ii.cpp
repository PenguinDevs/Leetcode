/*
 * @lc app=leetcode id=219 lang=cpp
 *
 * [219] Contains Duplicate II
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> lastIdxs;
        for (int i {0}; i < nums.size(); ++i) {
            const int x = nums[i];
            if (lastIdxs.contains(x)) {
                if (i - lastIdxs[x] <= k) return true;
            }

            lastIdxs[x] = i;
        }

        return false;
    }
};
// @lc code=end

