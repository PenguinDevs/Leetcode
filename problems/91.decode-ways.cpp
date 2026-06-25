/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size() + 1);
        dp[s.size()] = 1;
        dp[s.size() - 1] = 1;
        dp[s.size() - 1] = s.back() != '0';
        for (int i = s.size() - 2; i >= 0; --i) {
            if (s[i] == '0') {
                dp[i] = 0;
                continue;
            }
            // string skippedStr = {s[i],  s[i + 1]};
            // if (stoi(skippedStr) <= 26) {
            // cout << skippedStr << " " << (s[i] - '0' == 2) << " " << (s[i + 1] - '0' <= 6) << '\n';
            if ((s[i] - '0' == 2 && s[i + 1] - '0' <= 6) || (s[i] - '0' < 2)) {
                dp[i] = dp[i + 1] + dp[i + 2];
            } else {
                dp[i] = dp[i + 1];
            }
        }

        return dp[0];
    }
};
// @lc code=end

