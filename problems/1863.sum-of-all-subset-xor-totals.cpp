/*
 * @lc app=leetcode id=1863 lang=cpp
 *
 * [1863] Sum of All Subset XOR Totals
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        return dfs(nums);
    }
private:
    int dfs(vector<int>& nums, int xorTotal = 0, int i = 0) {
        if (i >= nums.size()) return xorTotal;

        int total {0};
        total += dfs(nums, xorTotal, i + 1);
        total += dfs(nums, xorTotal ^ nums[i], i + 1);

        return total;
    }
};
// @lc code=end

