/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        const int n = matrix.size();

        for (int j {0}; j < n / 2; ++j) {
            for (int i {j}; i < n - j - 1; ++i) {
                int prev = matrix[i][j];
                // cout << "starting " << i << " " << j << '\n';
                for (int k {0}; k < 4; ++k) {
                    pair<int, int> newCoords = getRotatedIdxs(n, i, j, (k + 1) % 4);
                    const int oldPrev = prev;
                    prev = matrix[newCoords.first][newCoords.second];
                    matrix[newCoords.first][newCoords.second] = oldPrev;
                    // break;
                }
            }
        }

        // for (const auto& row : matrix) {
        //     for (const int x : row) cout << x << ' ';
        //     cout << '\n';
        // }
    }
private:
    pair<int, int> getRotatedIdxs(
        const int n,
        const int i,
        const int j,
        const int r
    ) {
        switch (r) {
            case 0 : {
                return {i, j};
            }
            case 1 : {
                return {j, n - i - 1};
            }
            case 2 : {
                return {n - i - 1, n - j - 1};
            }
            case 3 : {
                return {n - j - 1, i};
            }
            default: {
                return {i, j};
            }
        }
    }
};
// @lc code=end

