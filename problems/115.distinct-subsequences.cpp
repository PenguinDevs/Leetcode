/*
 * @lc app=leetcode id=115 lang=cpp
 *
 * [115] Distinct Subsequences
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int numDistinct(string s, string t) {
        const int m = s.size(), n = t.size();
        vector<vector<unsigned long long>> dp(m + 1, vector<unsigned long long>(n + 1));

        for (int i {0}; i <= m; ++i) dp[i][n] = 1;
        
        for (int i {m - 1}; i >= 0; --i) {
            for (int j {n - 1}; j >= 0; --j) {
                dp[i][j] = dp[i + 1][j];
                
                if (s[i] == t[j]) {
                    dp[i][j] += dp[i + 1][j + 1];
                }
            }
            // cout << i << '\n';
        }
        
        return dp[0][0];
    }
};
// class Solution {
// public:
//     int numDistinct(string s, string t) {
//         const int m = s.size(), n = t.size();
//         vector<vector<int>> dp(n + 1, vector<int>(m + 1));

//         for (int i {1}; i <= n; ++i) { // Each word in t
//             for (int j {i}; j <= m; ++j) { // Each word in s
//                 if (i == 3 && j == 5) {
//                     cout << t[i - 1] << " " << s[j - 1] << '\n';
//                 }

//                 if (t[i - 1] == s[j - 1]) {
//                     dp[i][j] = 1 + dp[i][j - 1];
//                 } else {
//                     dp[i][j] = dp[i][j - 1];
//                 }
//                 dp[i][j] += 1 ? dp[i][j] > 0 && dp[i][j - 1] > 0 && j - 2 >= 0 && dp[i - 1][j - 2] < dp[i - 1][j - 1] : 0;
//             }
//         }

//         cout << "asdasdasdqwdasd\nx . ";
//         for (int j {0}; j < m; ++j) cout << s[j] << " ";
//         cout << '\n';
//         for (int i {0}; i < dp.size(); ++i) {
//             const auto& row = dp[i];
//             if (i > 0) {
//                 cout << t[i - 1] << " ";
//             } else {
//                 cout << ". ";
//             };
//             for (const int x : row) {
//                 cout << x << " ";
//             }
//             cout << '\n';
//         }

//         return dp[n][m];
//     }
// };
// @lc code=end

