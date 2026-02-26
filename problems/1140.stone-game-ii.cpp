/*
 * @lc app=leetcode id=1140 lang=cpp
 *
 * [1140] Stone Game II
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        const int n = piles.size();
        
        vector<int> window(n);
        window[n - 1] = piles[n - 1];
        for (int i {n - 2}; i >= 0; --i) {
            window[i] = piles[i] + window[i + 1];
        }
        
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return dfs(piles, dp, window);
    }
private:
    int dfs(
        vector<int>& piles,
        vector<vector<int>>& dp,
        vector<int>& window,
        int M = 1,
        int pileNo = 0
    ) {
        if (pileNo >= piles.size()) {
            return 0;
        }

        if (dp[pileNo][M] != -1) {
            return dp[pileNo][M];
        }

        int result {0};
        for (int X {1}; X <= min(M * 2, (int)dp.size() - pileNo); ++X) {
            result = max(result, window[pileNo] - dfs(piles, dp, window, max(M, X), pileNo + X));
        }

        return dp[pileNo][M] = result;
    }

    // int dfs(
    //     vector<int>& piles,
    //     vector<vector<int>>& dp,
    //     int gamePos = 0,
    //     const int M = 1,
    //     bool aliceTurn = false,
    //     int aliceStones = 0,
    //     int bobStones = 0
    // ) {
    //     aliceTurn = !aliceTurn;
    //     int best {0};
    //     for (int X {1}; X <= min(2 * M, (int)piles.size() - gamePos - 1); ++X) {
    //         if (aliceTurn) {
    //             aliceStones += X;
    //         } else {
    //             bobStones += X;
    //         }

    //         best = max(
    //             best,
    //             dfs(
    //                 piles,
    //                 dp,
    //                 gamePos + X,
    //                 max(M, X),
    //                 aliceTurn,
    //                 aliceStones,
    //                 bobStones
    //             )
    //         );

    //         if (aliceTurn) {
    //             aliceStones -= X;
    //         } else {
    //             bobStones -= X;
    //         }
    //     }

    //     if (aliceTurn) {
    //         aliceStones += best;
    //     } else {
    //         bobStones += best;
    //     }

    //     dp[M][gamePos] = max(dp[M][gamePos], aliceStones);

    //     if (aliceTurn) {
    //         return aliceStones;
    //     } else {
    //         return bobStones;
    //     }
    // }
};
// @lc code=end

