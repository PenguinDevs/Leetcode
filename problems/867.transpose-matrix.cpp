/*
 * @lc app=leetcode id=867 lang=cpp
 *
 * [867] Transpose Matrix
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        const int n = matrix.size();
        const int m = matrix[0].size();

        if (n < m) {
            // Horizontal rectangle
            for (int i {0}; i < m - n; ++i) {
                matrix.push_back({});
            }
        }

        for (int i {0}; i < n; ++i) {
            for (int j {0}; j < m; ++j) {
                if (i < m && j < n) {
                    if (i >= j) continue;
                    // Square
                    int temp = matrix[i][j];
                    matrix[i][j] = matrix[j][i];
                    matrix[j][i] = temp;
                // } else if (i >= m) {
                //     // Vertical rectangle
                //     matrix[j].push_back(matrix[i][j]);
                // } else if (j >= n) {
                //     // Horizontal rectangle
                //     matrix[j].push_back(matrix[i][j]);
                // }
                } else {
                    matrix[j].push_back(matrix[i][j]);
                }
            }
        }

        if (n < m) {
            // Horizontal rectangle
            for (int i {0}; i < n; ++i) {
                matrix[i].resize(n);
            }
        } else if (n > m) {
            // Vertical rectangle
            for (int i {n - 1}; i >= m; --i) {
                matrix.pop_back();
            }
        }

        return matrix;
    }
};
// @lc code=end

