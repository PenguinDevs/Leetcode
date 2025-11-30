/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) return {};
        set<vector<int>> output;
        
        sort(nums.begin(), nums.end());

        // cout << nums.size() << endl;
        for (int i {0}; i < nums.size() - 3; ++i) {
            for (int j {i + 1}; j < nums.size() - 2; ++j) {
                for (int k {j + 1}; k < nums.size() - 1; ++k) {
                    for (int l {k + 1}; l < nums.size(); ++l) {
                        // cout << i << " " << j << " " << k << " " << l << endl;
                        vector<int> quadruplet = {nums[i], nums[j], nums[k], nums[l]};
                        if (accumulate(quadruplet.begin(), quadruplet.end(), 0) == target) {
                            output.insert(quadruplet);
                        }
                    }
                }
            }
        }

        return vector<vector<int>>(output.begin(), output.end());
    }
};
// @lc code=end

