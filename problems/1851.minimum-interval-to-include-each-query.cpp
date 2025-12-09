/*
 * @lc app=leetcode id=1851 lang=cpp
 *
 * [1851] Minimum Interval to Include Each Query
 * 
 * NOTE: Alternative method also exists
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int> queriesSorted = queries;
        sort(queriesSorted.begin(), queriesSorted.end());
        sort(intervals.begin(), intervals.end());

        map<int, int> result;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        auto nextInterval = intervals.begin();
        for (const int q : queriesSorted) {
            // cout << (nextInterval != intervals.end()) << endl;
            while (nextInterval != intervals.end() && (*nextInterval)[0] <= q) {
                const vector<int>& interval = *nextInterval;
                const int gap = interval[1] - interval[0] + 1;
                // cout << "calculated gap of " << gap << " at end pos: " << interval[1] << endl;
                pq.push({gap, interval[1]});
                ++nextInterval;
            }

            if (pq.size() == 0) {
                result[q] = -1;
                continue;
            }

            auto minEntry = pq.top();
            // cout << minEntry.first << " @ " << minEntry.second << " when testing with q" << q << endl;
            while (minEntry.second < q) {
                if (pq.size() > 0) {
                    pq.pop();
                    minEntry = pq.top();
                } else {
                    minEntry = {-1, -1};
                    break;
                }
            }

            result[q] = minEntry.first;
        }

        vector<int> output;
        for (const int q : queries) {
            output.push_back(result[q]);
        }

        return output;
    }
};
// Nah I ain't that goated :(
// class Solution {
// public:
//     vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
//         map<int, vector<int>> upperBounds;
//         vector<int> lowerBounds;
//         lowerBounds.reserve(intervals.size());
        
//         for (const vector<int>& inter : intervals) {
//             int l {inter[0]};
//             int r {inter[1]};

//             lowerBounds.push_back(l);
//             push_heap(lowerBounds.begin(), lowerBounds.end());
//             auto& possibleUpperBounds = upperBounds[l];
//             possibleUpperBounds.push_back(r);
//             push_heap(possibleUpperBounds.begin(), possibleUpperBounds.end());
//         }

//         sort_heap(lowerBounds.begin(), lowerBounds.end());
//         for (auto& [_, interUpperBounds] : upperBounds) {
//             sort_heap(interUpperBounds.begin(), interUpperBounds.end());
//         }

//         vector<int> output;
//         for (const int q : queries) {
//             auto lowerBound = lower_bound(lowerBounds.begin(), lowerBounds.end(), q);
//             if (lowerBound == lowerBounds.end() || *lowerBound != q) {
//                 if (lowerBound == lowerBounds.begin()) {
//                     output.push_back(-1);
//                     continue;
//                 } else {
//                     --lowerBound;
//                 }
//             }

//             const auto& possibleUpperBounds = upperBounds[*lowerBound];
//             if (*--possibleUpperBounds.end() < q) {
//                 output.push_back(-1);
//                 continue;
//             }

//             const auto upperBound = lower_bound(possibleUpperBounds.begin(), possibleUpperBounds.end(), q);
//             output.push_back(*upperBound - *lowerBound + 1);
//         }

//         return output;
//     }
// };
// @lc code=end

