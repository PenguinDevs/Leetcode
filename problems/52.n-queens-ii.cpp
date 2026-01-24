/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int totalNQueens(int n) {
        int solsCount {0};
        nQueensAux(n, 0, 0, 0, 0, solsCount);

        return solsCount;
    }
private:
    void nQueensAux(
        const int n,
        const int i,
        int takenCols,
        int takenDiagL,
        int takenDiagR,
        int& solsCount
    ) {
        if (i >= n) {
            ++solsCount;

            return;
        }

        for (int j {0}; j < n; ++j) {
            if (1 << j & takenCols) continue;
            if (1 << (i - j + n - 1) & takenDiagL) continue;
            if (1 << ((n - j - 1) - i + n - 1) & takenDiagR) continue;
            takenCols |= 1 << j;
            takenDiagL |= 1 << (i - j + n - 1);
            takenDiagR |= 1 << ((n - j - 1) - i + n - 1);

            nQueensAux(n, i + 1, takenCols, takenDiagL, takenDiagR, solsCount);
            
            takenCols ^= 1 << j;
            takenDiagL ^= 1 << (i - j + n - 1);
            takenDiagR ^= 1 << ((n - j - 1) - i + n - 1);
        }
    }
};
// class Solution {
// public:
//     int totalNQueens(int n) {
//         vector<bool> takenCols(n);
//         vector<bool> takenDiagL(2 * n - 1);
//         vector<bool> takenDiagR(2 * n - 1);
//         int solsCount {0};

//         nQueensAux(0, takenCols, takenDiagL, takenDiagR, solsCount);

//         return solsCount;
//     }
// private:
//     void nQueensAux(
//         const int i,
//         vector<bool>& takenCols,
//         vector<bool>& takenDiagL,
//         vector<bool>& takenDiagR,
//         int& solsCount
//     ) {
//         const int n = takenCols.size();

//         if (i >= n) {
//             ++solsCount;

//             return;
//         }

//         for (int j {0}; j < n; ++j) {
//             if (takenCols[j]) continue;
//             if (takenDiagL[i - j + n - 1]) continue;
//             if (takenDiagR[(n - j - 1) - i + n - 1]) continue;
//             takenCols[j] = true;
//             takenDiagL[i - j + n - 1] = true;
//             takenDiagR[(n - j - 1) - i + n - 1] = true;

//             nQueensAux(i + 1, takenCols, takenDiagL, takenDiagR, solsCount);
            
//             takenCols[j] = false;
//             takenDiagL[i - j + n - 1] = false;
//             takenDiagR[(n - j - 1) - i + n - 1] = false;
//         }
//     }
// };
// @lc code=end

