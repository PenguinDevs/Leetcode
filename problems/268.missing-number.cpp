/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        const int n = nums.size();
        int total {n * (2 + (n - 1) * 1) / 2};
        for (const int x : nums) total -= x;
        return  total;
    }
};
// @lc code=end

