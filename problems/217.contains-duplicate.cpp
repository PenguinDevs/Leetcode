/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> checkedNums;

        for (const int x : nums) {
            if (checkedNums.contains(x)) return true;
            checkedNums.insert(x);
        }

        return false;
    }
};
// @lc code=end

