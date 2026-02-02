/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 * 
 * NOTE: Took many attempts, too many edges, and the current code
 * could definitely be a lot cleaner than what it is now
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.empty()) return {newInterval};
        
        auto startingInterval = lower_bound(intervals.begin(), intervals.end(), newInterval);
        bool mergedWithPrev = false;
        if (startingInterval != intervals.begin() && newInterval[0] <= (*(startingInterval - 1))[1]) {
            mergedWithPrev = true;
            --startingInterval;
        } else if (startingInterval != intervals.end()) {
            // (*startingInterval)[0] = newInterval[0];
        }

        auto endingInterval = upper_bound(intervals.begin(), intervals.end(), newInterval[1], 
        [](int val, const vector<int>& interv) {
            return val < interv[0];
        });

        if (startingInterval == endingInterval) {
            intervals.insert(startingInterval, newInterval);
        } else {
            (*startingInterval)[0] = min((*startingInterval)[0], newInterval[0]);

            if (startingInterval + 1 == endingInterval) {
                (*startingInterval)[1] = max((*startingInterval)[1], newInterval[1]);
            } else {
                int mergedStart = (*startingInterval)[0];
                int mergedEnd = max((*(endingInterval - 1))[1], newInterval[1]);

                intervals.erase(startingInterval, endingInterval);
                
                intervals.insert(startingInterval, {mergedStart, mergedEnd});
            }
        }

        return intervals;
    }
};
// @lc code=end

