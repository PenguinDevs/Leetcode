/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 * 
 * // Note: You've made the same mistake before of not considering a bit
 * manipulation solution carefully. Don't do that again.
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x {0};
        for (const int n : nums) x ^= n;

        return x;
    }
};
// @lc code=end
