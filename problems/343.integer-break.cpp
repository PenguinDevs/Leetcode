/*
 * @lc app=leetcode id=343 lang=cpp
 *
 * [343] Integer Break
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int integerBreak(int n) {
        vector<int> maxProducts(n + 1);
        maxProducts[1] = 1;

        for (int target {1}; target <= n; ++target) {
            for (int currSubTarget {1}; currSubTarget < target; ++currSubTarget) {
                const int prevSubTarget {target - currSubTarget};
                // cout << currSubTarget << " " << prevSubTarget << '\n';

                maxProducts[target] = max(
                    max(maxProducts[target], currSubTarget * prevSubTarget),
                    currSubTarget * maxProducts[prevSubTarget]
                );
            }
        }

        return maxProducts[n];
    }
};
// @lc code=end

