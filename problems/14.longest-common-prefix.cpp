/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs[0].size() == 0) return "";

        int right = strs[0].size();

        for (int i {1}; i < strs.size(); ++i) {
            right = min(right, (int)strs[i].size());
            for (int j {0}; j < right; ++j) {
                if (strs[0][j] != strs[i][j]) {
                    right = j;
                    break;
                }
            }
        }

        return string(strs[0], 0, right);
    }
};
// @lc code=end

