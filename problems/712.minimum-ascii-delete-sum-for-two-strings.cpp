/*
 * @lc app=leetcode id=712 lang=cpp
 *
 * [712] Minimum ASCII Delete Sum for Two Strings
 * 
 * NOTE: Variation of LCS
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        static const int MAX_INT = numeric_limits<int>::max();
        const int n = s2.size(), m = s1.size();

        vector<int> currentRow(m + 1);
        vector<int> prevRow(m + 1);

        for (int i {0}; i <= n; ++i) {
            for (int j {0}; j <= m; ++j) {
                if (i == 0 && j == 0) continue;

                // cout << (i > 0 ? s2[i - 1] : '?') << (j > 0 ? s1[j - 1] : '?') << " ";
                currentRow[j] = min(
                    (i > 0 && j > 0) && s2[i - 1] == s1[j - 1] ? prevRow[j - 1] : MAX_INT,
                    min(
                        i > 0 ? prevRow[j] + s2[i - 1] : MAX_INT,
                        j > 0 ? currentRow[j - 1] + s1[j - 1] : MAX_INT
                    )
                );
            }

            // for (const int x : currentRow) cout << x << " ";
            // cout << endl;
            swap(currentRow, prevRow);
            memset(currentRow.data(), 0, sizeof(int) * currentRow.size());
        }

        return prevRow[m];
    }
};
// @lc code=end

