/*
 * @lc app=leetcode id=1768 lang=cpp
 *
 * [1768] Merge Strings Alternately
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        auto word1Char = word1.begin();
        auto word2Char = word2.begin();

        string output;
        bool pickedWord1 {false};
        while (word1Char != word1.end() || word2Char != word2.end()) {
            if ((pickedWord1 && word2Char != word2.end()) || word1Char == word1.end()) {
                output += *word2Char;
                ++word2Char;
            } else {
                output += *word1Char;
                ++word1Char;
            }
            pickedWord1 = !pickedWord1;
        }

        return output;
    }
};
// @lc code=end

