/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> charFreq(26);
        for (const char sChar : s) ++charFreq[sChar - 'a'];
        for (const char tChar : t) --charFreq[tChar - 'a'];

        for (int i {0}; i < 26; ++i) {
            if (charFreq[i]) return false;
        }
        return true;
    }
};
// @lc code=end

