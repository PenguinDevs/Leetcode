/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subsets;
        vector<int> curSet;
        dfsBuild(nums, subsets, curSet);
        return subsets;
    }
private:
    void dfsBuild(vector<int>& nums, vector<vector<int>>& subsets, vector<int>& curSet, int i = 0) {
        if (i >= nums.size()) {
            subsets.push_back(curSet);
            return;
        };
        
        dfsBuild(nums, subsets, curSet, i + 1); // Without

        curSet.push_back(nums[i]);
        dfsBuild(nums, subsets, curSet, i + 1); // With
        curSet.pop_back();
    }
};
// @lc code=end

