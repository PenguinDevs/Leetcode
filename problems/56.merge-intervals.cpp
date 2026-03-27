/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> mergedIntervals;
        mergedIntervals.push_back(intervals[0]);

        for (int i {1}; i < intervals.size(); ++i) {
            const vector<int>& interval = intervals[i];

            if (mergedIntervals.back()[1] >= interval[0]) {
                mergedIntervals.back()[1] = interval[1];
            } else {
                mergedIntervals.push_back(interval);
            }
        }

        return mergedIntervals;
    }
};
// class Solution {
// public:
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
//         vector<pair<int, bool>> intervalOpenCloses;
//         for (const vector<int>& interval : intervals) {
//             intervalOpenCloses.push_back({interval[0], false});
//             intervalOpenCloses.push_back({interval[1], true});
//         }
//         sort(intervalOpenCloses.begin(), intervalOpenCloses.end());

//         int intervalStart {-1};
//         int intervalLayers {0};
//         int previousIntervalEnd {-1};
//         vector<vector<int>> mergedIntervals;
//         for (const auto& [time, closing] : intervalOpenCloses) {
//             // cout << time << " " << !closing << '\n';
//             if (!closing) {
//                 if (intervalLayers == 0) {
//                     if (previousIntervalEnd == time) {
//                         mergedIntervals.pop_back();
//                     } else {
//                         intervalStart = time;
//                     }
//                 }
    
//                 ++intervalLayers;
//             } else {
//                 --intervalLayers;

//                 if (intervalLayers == 0) {
//                     mergedIntervals.push_back({intervalStart, time});
//                     previousIntervalEnd = time;
//                 }
//             }
//         }

//         return mergedIntervals;
//     }
// };
// @lc code=end

