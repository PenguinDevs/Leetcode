/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 * 
 * // NOTE: For DP, think brute, then top-down, then bottom-up
 */

#include <bits/stdc++.h>
using namespace std;

// [1,2,3,0,2]
// (-1, 0) (2, 0) (-2, 0)
// (5, 0) (2, 0) (2, 0)

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int n = prices.size();
        
        vector<int> noStocks(n + 2);
        vector<int> holdStocks(n + 2);

        for (int i {n - 1}; i >= 0; --i) {
            const int sell = noStocks[i + 2] + prices[i];
            const int skipSell = holdStocks[i + 1];
            holdStocks[i] = max(sell, skipSell);
            
            const int buy = holdStocks[i + 1] - prices[i];
            const int skipBuy = noStocks[i + 1];
            noStocks[i] = max(buy, skipBuy);
        }

        return noStocks[0];
    }
};
// @lc code=end

