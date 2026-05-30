/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        const int n = s1.size();
        const int m = s2.size();

        int unsatisfiedCount {0};
        vector<int> charCounter(26);
        for (const char c : s1) {
            ++charCounter[c - 'a'];
        }
        for (int i {0}; i < 26; ++i) if (charCounter[i] != 0) ++unsatisfiedCount;
        
        for (int i {0}; i < m; ++i) {
            const char c {s2[i]};
            // cout << "uhhhh " << c << " " << charCounter[c - 'a'] << '\n';
            if (charCounter[c - 'a']-- == 0) ++unsatisfiedCount;
            if (charCounter[c - 'a'] == 0) --unsatisfiedCount;

            if (i - n >= 0) {
                // cout << c << " " << "passes " << s2[i - n] << '\n';
                if (charCounter[s2[i - n] - 'a']++ == 0) ++unsatisfiedCount;
                if (charCounter[s2[i - n] - 'a'] == 0) --unsatisfiedCount;
            }
            if (unsatisfiedCount == 0) return true;
            // cout << c << " " << unsatisfiedCount << '\n';
            // for (int i {0}; i < 26; ++i) cout << static_cast<char>('a' + i) << ":" << charCounter[i] << ", ";
            // cout << '\n';
        }

        return false;
    }
};
// @lc code=end

