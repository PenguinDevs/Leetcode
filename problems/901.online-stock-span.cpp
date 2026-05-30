/*
 * @lc app=leetcode id=901 lang=cpp
 *
 * [901] Online Stock Span
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class StockSpanner {
public:
    stack<pair<int, int>> monotonicStack;

    int next(int price) {
        int days {1};
        
        while (!monotonicStack.empty() && monotonicStack.top().first <= price) {
            days += monotonicStack.top().second;
            monotonicStack.pop();
        }
        monotonicStack.push({price, days});
        
        return days;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// @lc code=end

