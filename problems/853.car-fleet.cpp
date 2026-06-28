/*
 * @lc app=leetcode id=853 lang=cpp
 *
 * [853] Car Fleet
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        const int n = position.size();
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](const int lhs, const int rhs) {
            return position[lhs] > position[rhs];
        });

        stack<int> s;
        for (const int idx : order) {
            if (s.empty()) {
                s.push(idx);
                continue;
            }

            const int prevIdx = s.top();
            if (!doesCollide(
                position[prevIdx],
                speed[prevIdx],
                position[idx],
                speed[idx],
                target
            )) {
                s.push(idx);
            }
        }

        return s.size();
    }
private:
    bool doesCollide(
        const int p1,
        const int s1,
        const int p2,
        const int s2,
        const int target
    ) {
        const double frontTime = static_cast<double>(target - p1) / s1;
        const double rearTime = static_cast<double>(target - p2) / s2;
        return rearTime <= frontTime;
    }
};
// @lc code=end

