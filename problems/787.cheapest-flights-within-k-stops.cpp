/*
 * @lc app=leetcode id=787 lang=cpp
 *
 * [787] Cheapest Flights Within K Stops
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int findCheapestPrice(
        int n,
        vector<vector<int>>& flights,
        int src,
        int dst,
        int k
    ) {
        const int INF = INT_MAX / 2;
        vector<int> dpOld(n, INF), dp(n, INF);
        dpOld[src] = 0;

        for (int q {0}; q < k + 1; ++q) {
            dp = dpOld;
            for (const auto &flightDetail : flights) {
                const int from {flightDetail[0]}, to {flightDetail[1]}, price {flightDetail[2]};
                if (dpOld[from] + price < dp[to]) dp[to] = dpOld[from] + price;
            }
            swap(dp, dpOld);
        }

        return dpOld[dst] < INF ? dpOld[dst] : -1;
    }
};
// @lc code=end

