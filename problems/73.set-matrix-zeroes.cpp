/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        const int n = matrix.size(), m = matrix[0].size();

        bool topRowZero {false};
        bool leftColZero {false};
        for (int i {0}; i < n; ++i) {
            for (int j {0}; j < m; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;

                    if (i == 0) topRowZero = true;
                    if (j == 0) leftColZero = true;
                }
            }
        }

        // for (const auto& row : matrix) {
        //     for (const int x : row) cout << x << ' ';
        //     cout << endl;
        // }

        for (int i {1}; i < n; ++i) {
            if (matrix[i][0] == 0) {
                for (int j {0}; j < m; ++j) {
                    matrix[i][j] = 0;
                }
            }
        }

        for (int j {1}; j < m; ++j) {
            if (matrix[0][j] == 0) {
                for (int i {0}; i < n; ++i) {
                    matrix[i][j] = 0;
                }
            }
        }

        if (topRowZero) {
            for (int j {0}; j < m; ++j) {
                matrix[0][j] = 0;
            }
        }

        if (leftColZero) {
            for (int i {0}; i < n; ++i) {
                matrix[i][0] = 0;
            }
        }
    }
};
// @lc code=end

