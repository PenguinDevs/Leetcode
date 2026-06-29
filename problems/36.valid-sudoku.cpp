/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int m = board.size(), n = board[0].size();
        
        for (int i {0}; i < m; ++i) {
            vector<bool> seen(9);
            for (int j {0}; j < n; ++j) {
                const char x = board[i][j];
                if (x == '.') continue;
                if (seen[x - '1']) return false;
                seen[x - '1'] = true;
            }
        }

        for (int j {0}; j < n; ++j) {
            vector<bool> seen(9);
                for (int i {0}; i < m; ++i) {
                const char x = board[i][j];
                if (x == '.') continue;
                if (seen[x - '1']) return false;
                seen[x - '1'] = true;
            }
        }

        for (int i {0}; i < m - 1; ++++++i) {
            for (int j {0}; j < n - 1; ++++++j) {
                vector<bool> seen(9);
                for (int di {0}; di < 3; ++di) {
                    for (int dj {0}; dj < 3; ++dj) {
                        const char x = board[i + di][j + dj];
                        if (x == '.') continue;
                        if (seen[x - '1']) return false;
                        seen[x - '1'] = true;
                    }
                }
            }
        }

        return true;
    }
};
// @lc code=end

