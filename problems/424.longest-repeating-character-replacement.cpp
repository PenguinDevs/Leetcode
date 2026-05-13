/*
 * @lc app=leetcode id=424 lang=cpp
 *
 * [424] Longest Repeating Character Replacement
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int characterReplacement(string& s, int k) {
        int longest {0};
        int l {0};
        int maxFreq {0};
        
        vector<int> window(26);
        
        for (int r {0}; r < s.size(); ++r) {
            ++window[s[r] - 'A'];
            maxFreq = max(maxFreq, window[s[r] - 'A']);

            int windowLength {r - l + 1};
            if (windowLength - maxFreq > k) {
                --window[s[l] - 'A'];
                ++l;
                windowLength = r - l + 1;
            }

            longest = max(longest, windowLength);
        }

        return longest;
    }
};
// @lc code=end

