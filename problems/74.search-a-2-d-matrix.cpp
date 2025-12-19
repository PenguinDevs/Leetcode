/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Binary search by row first
        const int m = matrix.size();
        const int n = matrix[0].size();

        int b {0};
        int t {m - 1};
        while (b < t) {
            const int mid = (t + b) / 2;

            if (target < matrix[mid][0]) {
                // cout << "too high" << endl;
                t = mid - 1;
            } else if (target > matrix[mid][n - 1]) {
                // cout << "too low" << endl;
                b = mid + 1;
            } else {
                // Found
                break;
            }
        }

        const int m_found = (t + b) / 2;
        if (target < matrix[m_found][0] || matrix[m_found][n - 1] < target) {
            return false;
        }

        int l {0};
        int r {n - 1};
        while (l < r) {
            const int mid = (l + r) / 2;
            // cout << mid << endl;

            if (target < matrix[m_found][mid]) {
                // cout << "too high" << endl;
                r = mid - 1;
            } else if (target > matrix[m_found][mid]) {
                // cout << "too low" << endl;
                l = mid + 1;
            } else {
                // Found
                return true;
            }
        }

        return matrix[m_found][l] == target;
    }
};
// @lc code=end

