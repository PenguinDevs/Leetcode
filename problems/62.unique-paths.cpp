/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//         if (m == 1 || n == 1) return 1;
//         long long sol {n};
//         for (long long i {1}; i < m - 1; ++i) {
//             sol *= (n + i) / (i + 1);
//             cout << n + i << " " << i + 1 << endl;
//         }

//         // long long mFac {1};
//         // for (long long i {1}; i <= m - 1; ++i) {
//         //     mFac *= i;
//         // }

//         // cout << sol << " " << mFac;

//         return sol;
//     }
// };
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);
        for (int i {1}; i < m; ++i) {
            for (int j {1}; j < n; ++j) {
                if (i == 0 && j == 0) continue;
                dp[j] += dp[j - 1];
            }
        }

        return dp[n - 1];
    }
};
// @lc code=end

