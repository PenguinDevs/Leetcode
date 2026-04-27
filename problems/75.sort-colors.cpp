/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l {0};
        int r = nums.size() - 1;
        int m {l};

        while (l <= m && m <= r) {
            // cout << l << " " << m << " " << r << '\n';
            if (nums[l] == 0) {
                ++l;
                if (l >= m) ++m;
                continue;
            } else if (nums[r] == 2) {
                --r;
                if (r <= m) --m;
                continue;
            }

            if (nums[m] == 0) {
                // cout << "swap " << l << " " << m << '\n';
                swap(nums[l], nums[m]);
                ++l;
                if (m <= l) ++m;
            } else if (nums[m] == 2) {
                // cout << "swap " << r << " " << m << '\n';
                swap(nums[r], nums[m]);
                --r;
                if (m >= r) --m;
            } else {
                ++m;
            }
            // cout << "current: ";
            // for (int x : nums) cout << x << ' ';
            // cout << '\n';
        }
    }
};
// @lc code=end

