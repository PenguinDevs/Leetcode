/*
 * @lc app=leetcode id=410 lang=cpp
 *
 * [410] Split Array Largest Sum
 * 
 * NOTE: Come back and do the DP variant instead
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        auto canSplit = [nums, k](int targetSize) -> bool {
            int currSum {0};
            int arrayCount {1};
            for (const int x : nums) {
                if (x > targetSize) return false;

                currSum += x;
                if (currSum > targetSize) {
                    arrayCount += 1;
                    currSum = x;

                    if (arrayCount > k) {
                        return false;
                    }
                }
            }

            return true;
        };

        int l {*max_element(nums.begin(), nums.end())};
        int r {accumulate(nums.begin(), nums.end(), 0)};
        while (l <= r) {
            const int m = (l + r) / 2;
            if (canSplit(m)) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return l;
    }
};
// @lc code=end

