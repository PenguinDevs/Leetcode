/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int n = prices.size();

        vector<int> holdStocks(n + 2);
        vector<int> noStocks(n + 2);
        
        for (int i {n - 1}; i >= 0; --i) {
            const int sell = noStocks[i + 1] + prices[i];
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

