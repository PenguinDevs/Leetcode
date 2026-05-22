/*
 * @lc app=leetcode id=1094 lang=cpp
 *
 * [1094] Car Pooling
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> passengerDiff(1001);
        for (const auto& trip : trips) {
            passengerDiff[trip[1]] += trip[0];
            passengerDiff[trip[2]] += -trip[0];
        }

        int passengers {0};
        for (int i {0}; i < 1001; ++i) {
            passengers += passengerDiff[i];
            if (passengers > capacity) return false;
        }

        return true;
    }
};
// @lc code=end

