/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l {0};
        int r = nums.size() - 1;

        while (l < r) {
            int mid {(l + r) / 2};

            // Cases:
            // #1: LH not strictly increasing -> investigate LH
            // #2: RH not strictly increasing -> investigate RH
            // #3: LH and RH are strictly increasing -> investigate LH

            // cout << l << " " << r << " " << mid << endl;
            if (nums[l] > nums[mid]) {
                // cout << "low " << nums[l] << " " << nums[mid] << endl;
                r = mid;
            } else if (nums[r] < nums[mid]) {
                // cout << "high " << nums[r] << " " << nums[mid + 1] << endl;
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        return nums[l];
    }
};
// @lc code=end

