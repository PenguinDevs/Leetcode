/*
 * @lc app=leetcode id=134 lang=cpp
 *
 * [134] Gas Station
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (accumulate(gas.begin(), gas.end(), 0) < accumulate(cost.begin(), cost.end(), 0)) return -1;

        int fuel {gas[0]};
        int start {-1};
        for (int i {0}; i < gas.size() - 1; ++i) {
            fuel -= cost[i];
            if (fuel < 0) {
                start = -1;
                fuel = gas[i + 1];
                continue;
            }
            if (start == -1) start = i;
            fuel += gas[i + 1];
        }

        fuel -= cost[gas.size() - 1];        
        if (fuel >= 0 && start == -1) return gas.size() - 1;

        return start;
    }
};
// @lc code=end

