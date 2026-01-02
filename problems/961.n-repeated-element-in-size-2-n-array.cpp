/*
 * @lc app=leetcode id=961 lang=cpp
 *
 * [961] N-Repeated Element in Size 2N Array
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int prevNum {-1};
        int prevPrevNum {-1};
        int prevPrevPrevNum {-1};
        for (const int n : nums) {
            if (n == prevNum || n == prevPrevNum || n == prevPrevPrevNum) {
                return n;
            }

            prevPrevPrevNum = prevPrevNum;
            prevPrevNum = prevNum;
            prevNum = n;
        };

        return -1;
    }
};
// @lc code=end

