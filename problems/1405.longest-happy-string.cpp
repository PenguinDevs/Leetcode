/*
 * @lc app=leetcode id=1405 lang=cpp
 *
 * [1405] Longest Happy String
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string out;
        const int maxSize {a + b + c};
        int aUsed {0}, bUsed {0}, cUsed {0};

        for (int i {0}; i < maxSize; ++i) {
            if (a > 0 && ((a >= b && a >= c && aUsed != 2) || bUsed == 2 || cUsed == 2)) {
                out += 'a';
                --a;
                ++aUsed;
                bUsed = 0;
                cUsed = 0;
            } else if (b > 0 && ((b >= a && b >= c && bUsed != 2) || aUsed == 2 || cUsed == 2)) {
                out += 'b';
                --b;
                ++bUsed;
                aUsed = 0;
                cUsed = 0;
            } else if (c > 0 && ((c >= a && c >= b && cUsed != 2) || aUsed == 2 || bUsed == 2)) {
                out += 'c';
                --c;
                ++cUsed;
                aUsed = 0;
                bUsed = 0;
            }
        }

        return out;
    }
};
// class Solution {
// public:
//     string longestDiverseString(int a, int b, int c) {
//         priority_queue<pair<int, char>> happyCandidates;
//         if (a > 0) happyCandidates.push({a, 'a'});
//         if (b > 0) happyCandidates.push({b, 'b'});
//         if (c > 0) happyCandidates.push({c, 'c'});

//         string out;
//         while (!happyCandidates.empty()) {
//             auto [remaining, c] = happyCandidates.top();
//             happyCandidates.pop();

//             if (out.size() >= 2 && out[out.size() - 1] == c && out[out.size() - 2] == c) {
//                 if (happyCandidates.empty()) break;
//                 auto [newRemaining, newC] = happyCandidates.top();
//                 happyCandidates.pop();

//                 happyCandidates.push({remaining, c});
//                 remaining = newRemaining;
//                 c = newC;
//             }

//             out.push_back(c);

//             if (remaining <= 1) continue;
//             happyCandidates.push({--remaining, c});
//         }

//         return out;
//     }
// };
// @lc code=end

