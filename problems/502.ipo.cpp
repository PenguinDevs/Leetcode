/*
 * @lc app=leetcode id=502 lang=cpp
 *
 * [502] IPO
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int> highestProfits;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> cheapestCapitals;

        const int n = profits.size();
        
        for (int i {0}; i < n; ++i) {
            if (capital[i] <= w) {
                highestProfits.push(profits[i]);
            } else {
                cheapestCapitals.push({capital[i], profits[i]});
            }
        }
        
        int totalCapital {w};
        for (int i {0}; i < k; ++i) {
            if (highestProfits.empty()) break;

            int greatestProfit = highestProfits.top();
            highestProfits.pop();
            totalCapital += greatestProfit;
            
            while (cheapestCapitals.size() > 0 && cheapestCapitals.top().first <= totalCapital) {
                highestProfits.push(cheapestCapitals.top().second);
                cheapestCapitals.pop();
            }
        }

        return totalCapital;
    }
};
// @lc code=end

