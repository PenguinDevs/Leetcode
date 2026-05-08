/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> out(temperatures.size());
        stack<int> highest;

        int r {0};
        for (int i = temperatures.size() - 1; i >= 0; --i) {
            const int x {temperatures[i]};

            while (!highest.empty()) {
                if (x < temperatures[highest.top()]) {
                    out[i] = highest.top() - i;
                    break;
                }

                highest.pop();
            }

            highest.push(i);
        }

        return out;
    }
};
// class Solution {
// public:
//     vector<int> dailyTemperatures(vector<int>& temperatures) {
//         vector<int> out(temperatures.size());
        
//         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//         for (int i {0}; i < temperatures.size(); ++i) {
//             const int x {temperatures[i]};
//             while (!pq.empty()) {
//                 const auto [lowTemp, lowTempIdx] = pq.top();
//                 if (lowTemp < x) {
//                     out[lowTempIdx] = i - lowTempIdx;
//                     pq.pop();
//                 } else {
//                     break;
//                 }
//             }
//             pq.push({x, i});
//         }

//         return out;
//     }
// };
// @lc code=end

