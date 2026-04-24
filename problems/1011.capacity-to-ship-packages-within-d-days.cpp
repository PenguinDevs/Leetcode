/*
 * @lc app=leetcode id=1011 lang=cpp
 *
 * [1011] Capacity To Ship Packages Within D Days
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        const auto canFit = [&weights, &days](const int shipCapacity) -> bool {
            int currCapacity {0};
            int daysCounted {1};
            for (const int x : weights) {
                if (currCapacity + x > shipCapacity) {
                    currCapacity = x;
                    ++daysCounted;
                    if (currCapacity > shipCapacity) return false;
                    if (daysCounted > days) return false;
                } else {
                    currCapacity += x;
                }
            }

            return true;
        };

        int l {*max_element(weights.begin(), weights.end())};
        int r {accumulate(weights.begin(), weights.end(), 0)};

        while (l <= r) {
            int target {l + (r - l) / 2};
            if (canFit(target)) {
                r = target - 1;
            } else {
                l = target + 1;
            }
        }

        return l;
    }
};
// @lc code=end

