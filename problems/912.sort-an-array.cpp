/*
 * @lc app=leetcode id=912 lang=cpp
 *
 * [912] Sort an Array
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        sortSubArray(nums, 0, nums.size() - 1);
        return nums;
    }
private:
    void sortSubArray(vector<int>& nums, int l, int r) {
        if (l >= r) return;
        
        int pivotIdx = (l + r) / 2;
        // cout << l << " " << r << '\n';
        sortSubArray(nums, l, pivotIdx);
        sortSubArray(nums, pivotIdx + 1, r);

        int lArrayIdx = l;
        int rArrayIdx = pivotIdx + 1;
        vector<int> temp;
        temp.reserve(r - l + 1);
        while (lArrayIdx <= pivotIdx && rArrayIdx <= r) {
            if (nums[lArrayIdx] < nums[rArrayIdx]) {
                temp.push_back(nums[lArrayIdx++]);
            } else {
                temp.push_back(nums[rArrayIdx++]);
            }
        }
        while (lArrayIdx <= pivotIdx) temp.push_back(nums[lArrayIdx++]);
        while (rArrayIdx <= r) temp.push_back(nums[rArrayIdx++]);

        for (int i {0}; i < r - l + 1; ++i) nums[l + i] = temp[i];
    }
};
// @lc code=end

