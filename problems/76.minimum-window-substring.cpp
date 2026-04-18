/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    static int serializeChar(char c) {
        if (c >= 'A' && c <= 'Z') return c - 'A';
        return 26 + (c - 'a');
    }

    string minWindow(string s, string t) {
        vector<int> count(52, 0);
        vector<bool> inT(52, false);
        int needCount {0};
        for (const char& c : t) {
            int idx = serializeChar(c);
            if (!inT[idx]) {
                inT[idx] = true;
                ++needCount;
            }
            --count[idx];
        }

        int minWindowSize {INT_MAX};
        int minL {0};
        int minR {-1};

        int l {0};
        for (int r {0}; r < s.size(); ++r) {
            int rIdx = serializeChar(s[r]);
            if (inT[rIdx] && ++count[rIdx] == 0) --needCount;
            // cout << "window: " << l << " " << r << " : " << needCount << '\n';

            while (needCount == 0 && l <= r) {
                int lIdx = serializeChar(s[l]);
                if (!inT[lIdx]) {
                    ++l;
                    continue;
                }
                if (count[lIdx] == 0) break;
                if (--count[lIdx] == -1) ++needCount;
                
                ++l;
            }
            if (needCount == 0 && minWindowSize > r - l) {
                // cout << "set " << l << " " << r << '\n';
                minWindowSize = r - l;
                minL = l;
                minR = r;
            }
        }

        // cout << '\n';
        // cout << minWindowSize << " " << minL << " " << minR;
        return s.substr(minL, minR - minL + 1);
    }
};
// @lc code=end

