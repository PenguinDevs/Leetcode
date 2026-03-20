/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        const int n = nums.size();
        
        for (int i {0}; i < n; ++i) {
            if (nums[i] <= 0) {
                nums[i] = n + 1;
            }
        }
        
        // for (int i {0}; i < n; ++i) cout << nums[i] << ' ';
        // cout << '\n';
        for (int i {0}; i < n; ++i) {
            if (abs(nums[i]) <= n) nums[abs(nums[i]) - 1] = -abs(nums[abs(nums[i]) - 1]);
        }

        // for (int i {0}; i < n; ++i) cout << nums[i] << ' ';
        for (int i {0}; i < n; ++i) {
            if (nums[i] > 0) return i + 1;
        }

        return n + 1;
    }
};
// @lc code=end

