/*
 * @lc app=leetcode id=877 lang=cpp
 *
 * [877] Stone Game
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        const int n  = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        const int aliceScore = dfs(piles, dp, 0, n - 1);
        const int bobScore = accumulate(piles.begin(), piles.end(), 0) - aliceScore;

        // cout << aliceScore << " " << bobScore;

        return aliceScore > bobScore;
    }
private:
    int dfs(
        vector<int>& piles,
        vector<vector<int>>& dp,
        int l,
        int r
    ) {
        if (l > r) return 0;
        if (dp[l][r] != -1) return dp[l][r];

        const bool isAliceTurn {(l + r) % 2 == 1}; // On odd turn since 0-indexed
        const int leftPile = isAliceTurn ? piles[l] : 0;
        const int rightPile = isAliceTurn ? piles[r] : 0;
        // cout << isAliceTurn << " " << leftPile << " " << rightPile << endl;
        dp[l][r] = max(dfs(piles, dp, l + 1, r) + leftPile, dfs(piles, dp, l, r - 1) + rightPile);

        return dp[l][r];
    }
};
// @lc code=end

