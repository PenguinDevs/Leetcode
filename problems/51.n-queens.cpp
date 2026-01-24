/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> curSol(n, string(n, '.'));
        vector<bool> takenCols(n);
        vector<bool> takenDiagL(2 * n - 1);
        vector<bool> takenDiagR(2 * n - 1);
        vector<vector<string>> allSols;

        nQueensAux(curSol, 0, takenCols, takenDiagL, takenDiagR, allSols);

        return allSols;
    }
private:
    void nQueensAux(
        vector<string>& curSol,
        int i,
        vector<bool>& takenCols,
        vector<bool>& takenDiagL,
        vector<bool>& takenDiagR,
        vector<vector<string>>& allSols
    ) {
        const int n = curSol.size();

        if (i >= n) {
            allSols.push_back(curSol);

            return;
        }

        for (int j {0}; j < curSol.size(); ++j) {
            if (takenCols[j]) continue;
            if (takenDiagL[i - j + n - 1]) continue;
            if (takenDiagR[(n - j - 1) - i + n - 1]) continue;
            takenCols[j] = true;
            takenDiagL[i - j + n - 1] = true;
            takenDiagR[(n - j - 1) - i + n - 1] = true;
            curSol[i][j] = 'Q';

            nQueensAux(curSol, i + 1, takenCols, takenDiagL, takenDiagR, allSols);
            
            takenCols[j] = false;
            takenDiagL[i - j + n - 1] = false;
            takenDiagR[(n - j - 1) - i + n - 1] = false;
            curSol[i][j] = '.';
        }
    }
};
// @lc code=end

