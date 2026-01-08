/*
 * @lc app=leetcode id=81 lang=cpp
 *
 * [81] Search in Rotated Sorted Array II
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        unsigned l {0};
        unsigned r = nums.size() - 1;

        while (l < r) {
            unsigned mid = (l + r) / 2;

            if (nums[mid] == target) return true;

            if (nums[l] == nums[mid] && nums[r] == nums[mid]) {
                l = min(l + 1, r);
                r = max(r - 1, l);
                continue;
            }

            if (mid != 0 && nums[l] <= nums[mid]) {
                if (nums[l] <= target && target <= nums[mid]) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            } else if (mid != nums.size() - 1 && nums[r] >= nums[mid + 1]) {
                if (nums[r] >= target && target >= nums[mid + 1]) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            } else {
                return -1;
            }

            // if (nums[l] <= target && target <= nums[mid - 1]) {
            //     r = mid;
            // } else if (nums[r] >= target && target >= nums[mid + 1]) {
            //     l = mid + 1;
            // } else {
            //     return -1;
            // }
        }

        return nums[l] == target;
    }
};
// @lc code=end

