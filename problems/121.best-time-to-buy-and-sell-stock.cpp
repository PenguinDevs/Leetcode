/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lowestPrice {INT_MAX};
        int greatestProfit {0};

        for (const int& p : prices) {
            lowestPrice = min(lowestPrice, p);
            greatestProfit = max(greatestProfit, p - lowestPrice);
        }

        return greatestProfit;
    }
};
// @lc code=end

