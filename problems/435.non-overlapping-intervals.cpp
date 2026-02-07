/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Non-overlapping Intervals
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int out {0};

        sort(intervals.begin(), intervals.end());

        int prevEnd {numeric_limits<int>::min()};
        for (const vector<int>& entry : intervals) {
            const int start = entry[0], end = entry[1];

            if (start >= prevEnd) {
                prevEnd = end;
            } else {
                prevEnd = min(prevEnd, end);
                out += 1;
            }
        }

        return out;
    }
};
// @lc code=end

