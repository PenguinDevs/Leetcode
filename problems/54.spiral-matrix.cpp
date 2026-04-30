/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        const int m = matrix.size();
        const int n = matrix[0].size();
        
        if (m == 1) {
            return matrix[0];
        }

        vector<int> path;
        int direction = 1; // Right
        int remainingWidth {n};
        int remainingHeight {m - 1};

        int i {0}, j {-1};
        while (remainingWidth > 0 || remainingHeight > 0) {
            int count {0};
            // cout << remainingWidth << " " << remainingHeight << '\n';
            if (((direction == 0 || direction == 2) ? remainingHeight : remainingWidth) == 0) break;
            // cout << direction << " " << ((direction == 1 || direction == 3) ? remainingHeight : remainingWidth) << '\n';
            while (count++ < ((direction == 0 || direction == 2) ? remainingHeight : remainingWidth)) {
                switch (direction) {
                    case 0:
                        --i;
                        break;
                    case 1:
                        ++j;
                        break;
                    case 2:
                        ++i;
                        break;
                    case 3:
                        --j;
                        break;
                }
                // cout << i << " " << j << '\n';
                path.push_back(matrix[i][j]);
            }
            // cout << "skipped\n";

            if (direction == 0 || direction == 2) {
                --remainingHeight;
            } else {
                --remainingWidth;
            }

            direction = (direction + 1) % 4;
        }

        return path;
    }
};
// @lc code=end

