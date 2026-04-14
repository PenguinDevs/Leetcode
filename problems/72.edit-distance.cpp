/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 *
 * NOTE: Think about how u gotta shape this problem to an easy brute force / DP
 * bottom up
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        const int n = word1.size();
        const int m = word2.size();
        
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for (int j {0}; j <= m; ++j) {
            dp[n][j] = m - j;
        }
        for (int i {0}; i <= n; ++i) {
            dp[i][m] = n - i;
        }

        for (int i {n - 1}; i >= 0; --i) {
            for (int j {m - 1}; j >= 0; --j) {
                if (word1[i] == word2[j]) {
                    dp[i][j] = dp[i + 1][j + 1];
                } else {
                    dp[i][j] = 1 + min(
                        dp[i + 1][j + 1],
                        min(
                            dp[i + 1][j],
                            dp[i][j + 1]
                        )
                    );
                }
            }
        }

        // for (int i {0}; i < n; ++i) {
        //     for (const int x : dp[i]) cout << x << ' ';
        //     cout << '\n';
        // }

        return dp[0][0];
    }
};
// class Solution {
// public:
//     int minDistance(string word1, string word2) {
//         if (word1.size() < word2.size()) {
//             swap(word1, word2);
//         } // word1 > word2

//         unordered_map<char, queue<int>> word2CharToIdx;
//         for (int i {0}; i < word2.size(); ++i) word2CharToIdx[word2[i]].push(i);

//         queue<char> commonChars;
//         int lastCharIdx{0};
//         for (const char c : word1) {
//             // if (!word2CharToIdx.contains(c)) continue;
//             while (!word2CharToIdx[c].empty()) {
//                 const int i = word2CharToIdx[c].front();
//                 word2CharToIdx[c].pop();

//                 cout << c << " " << i << " " << lastCharIdx << '\n';
//                 if (i > lastCharIdx) {
//                     lastCharIdx = i;
//                     commonChars.push(c);
//                     break;
//                 }
//             }
//         }

//         int changes {0};
//         for (const char c : word1) {
//             if (!commonChars.empty() && c == commonChars.front()) {
//                 cout << "has " << c << '\n';
//                 commonChars.pop();
//             } else {
//                 ++changes;
//             }
//         }

//         return changes;
//     }
// };
// @lc code=end

