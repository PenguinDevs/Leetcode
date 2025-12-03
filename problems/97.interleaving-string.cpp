/*
 * @lc app=leetcode id=97 lang=cpp
 *
 * [97] Interleaving String
 * 
 * NOTE: I predict that this is genuinely a fun problem
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
        if (s1.size() == 0) return s2 == s3;
        if (s2.size() == 0) return s1 == s3;

        vector<bool> prev;
        vector<bool> cur(s2.size() + 1);
        cur[0] = true;

        for (int i {0}; i <= s1.size(); ++i) {
            for (int j {0}; j <= s2.size(); ++j) {
                if (i == 0 && j == 0) continue;

                // Going down or picking s1
                if (i > 0) {
                    cur[j] = prev[j] && s3[i + j - 1] == s1[i - 1];
                }
                
                // Going right or picking s2
                if (j > 0) {
                    cur[j] = cur[j] || (cur[j - 1] && s3[i + j - 1] == s2[j - 1]);
                }
            }
            swap(prev, cur);
            // for (bool n : cur) cout << n << " ";
            // cout << endl;
            cur.clear();
            cur.resize(s2.size() + 1);
        }

        return prev[s2.size()];
    }
};
// @lc code=end

