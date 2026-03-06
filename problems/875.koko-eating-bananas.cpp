/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        auto canEatBananas = [piles, h](int targetRate) -> bool {
            long long totalHours {0};
            for (const int bananaCount : piles) {
                totalHours += (bananaCount + targetRate - 1LL) / targetRate;
                // cout << "hours: " << totalHours << '\n';

                if (totalHours > h) {
                    return false;
                }
            }

            return true;
        };

        int l {1};
        int r {*max_element(piles.begin(), piles.end())};
        int lastHourlyRate {r};
        while (l <= r) {
            const int m = l + (r - l) / 2;
            // cout << m << '\n';
            if (canEatBananas(m)) {
                // cout << " it works\n";
                lastHourlyRate = min(lastHourlyRate, m);
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return lastHourlyRate;
    }
};
// @lc code=end

