/*
 * @lc app=leetcode id=767 lang=cpp
 *
 * [767] Reorganize String
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    string reorganizeString(string s) {
        vector<int> charFreq(26);
        for (const char c : s) ++charFreq[c - 'a'];
        
        priority_queue<pair<int, char>> largestChars;
        for (int i {0}; i < 26; ++i) {
            if (charFreq[i] == 0) continue;
            largestChars.push({charFreq[i], i + 'a'});
        }

        string out;
        while (!largestChars.empty()) {
            if (largestChars.size() > 1) {
                auto [largestCount, largest] = largestChars.top();
                largestChars.pop();
                auto [nextLargestCount, nextLargest] = largestChars.top();
                largestChars.pop();

                out += largest;
                out += nextLargest;

                if (largestCount > 1) largestChars.push({--largestCount, largest});
                if (nextLargestCount > 1) largestChars.push({--nextLargestCount, nextLargest});
            } else {
                auto [largestCount, largest] = largestChars.top();
                largestChars.pop();
                if (out.size() > 0 && out.back() == largest) return "";
                if (largestCount != 1) return "";
                out += largest;
            }
        }

        return out;
    }
};
// class Solution {
// public:
//     string reorganizeString(string s) {
//         for (int i {0}; i < s.size(); ++i) {
//             if (
//                 i > 0 && s[i - 1] != s[i]
//                 && i < s.size() - 1 && s[i + 1] != s[i]
//             ) continue;
            
//             bool hasSwapped {false};
//             for (int j {0}; j < s.size(); ++j) {
//                 if (s[i] == s[j]) continue;
//                 if (j > 0 && j - 1 != i && s[j - 1] == s[i]) continue;
//                 if (j < s.size() - 1 && j + 1 != i && s[j + 1] == s[i]) continue;
//                 if (i > 0 && i - 1 != j && s[i - 1] == s[j]) continue;
//                 if (i < s.size() - 1 && i + 1 != j && s[i + 1] == s[j]) continue;
//                 swap(s[i], s[j]);
//                 cout << "swapped " << i << " " << j << endl;
//                 hasSwapped = true;
//                 break;
//             }

//             cout << s << endl;

//             if (!hasSwapped) return "";
//         }

//         return s;
//     }
// };
// @lc code=end

