/*
 * @lc app=leetcode id=304 lang=cpp
 *
 * [304] Range Sum Query 2D - Immutable
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class NumMatrix {
public:
    vector<vector<int>> prefix;

    NumMatrix(vector<vector<int>>& matrix) : prefix(matrix.size(), vector<int>(matrix[0].size())) {
        const int n = matrix.size();
        const int m = matrix[0].size();
        
        for (int i {0}; i < n; ++i) {
            for (int j {0}; j < m; ++j) {
                int topColSum {0};
                if (i > 0) {
                    topColSum = prefix[i - 1][j] - (j > 0 ? prefix[i - 1][j - 1] : 0);
                }
                prefix[i][j] = matrix[i][j] + (j > 0 ? prefix[i][j - 1] : 0) + topColSum;
            }
        }

        // for (const auto row : prefix) {
        //     for (const int x : row) cout << x << ' ';
        //     cout << '\n';
        // }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return prefix[row2][col2]
            - (col1 > 0 ? prefix[row2][col1 - 1] : 0)
            - (row1 > 0 ? prefix[row1 - 1][col2] : 0)
            + (row1 > 0 && col1 > 0 ? prefix[row1 - 1][col1 - 1] : 0);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end

