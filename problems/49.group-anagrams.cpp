/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        for (const string s : strs) {
            string hash = s;
            sort(hash.begin(), hash.end());
            groups[hash].push_back(s);
            // groups[hash(s)].push_back(s);
        }

        vector<vector<string>> out;
        for (const auto& [_, group] : groups) {
            out.push_back(group);
        }

        return out;
    }
private:
    string hash(string s) {
        vector<int> charCounts(26);
        for (const char c : s) ++charCounts[c - 'a'];
        
        string out;
        for (int i {0}; i < 26; ++i) {
            if (charCounts[i] > 0) {
                out += i + 'a';
                out += to_string(charCounts[i]);
            }
        }
        return out;
    }
};
// @lc code=end

