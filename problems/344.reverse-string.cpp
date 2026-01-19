/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
        for (int i {0}; i < s.size() / 2; ++i) {
            swap(s[i], s[s.size() - i - 1]);
        }
    }
};
// @lc code=end

