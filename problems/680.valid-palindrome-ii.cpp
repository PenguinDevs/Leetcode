/*
 * @lc app=leetcode id=680 lang=cpp
 *
 * [680] Valid Palindrome II
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool validPalindrome(string s) {
        int l {0};
        int r = s.size() - 1;
        int exceptions {0};
        while (l <= r) {
            // cout << l << " " << r << '\n';
            if (s[l] != s[r]) {
                ++exceptions;
                // cout << "rah " << l << " " << r << '\n';
                int i = l;
                int j = r;
                while (s[i + 1] == s[j] && s[i] == s[j - 1]) {
                    ++i;
                    --j;
                }
                if (s[i + 1] == s[j]) {
                    ++i;
                } else {
                    --j;
                }
                l = i;
                r = j;
            } else {
                ++l;
                --r;
            }
        }

        return exceptions <= 1;
    }
};
// @lc code=end

