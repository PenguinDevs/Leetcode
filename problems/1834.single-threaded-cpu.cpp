/*
 * @lc app=leetcode id=1834 lang=cpp
 *
 * [1834] Single-Threaded CPU
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> lowestProcessingTimes;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> lowestEnqueueTimes;

        for (int i {0}; i < tasks.size(); ++i) {
            vector<int>& task = tasks[i];
            lowestEnqueueTimes.push({task[0], i});
        }

        vector<int> processingOrder;
        long long time {1};
        while (!lowestProcessingTimes.empty() || !lowestEnqueueTimes.empty()) {
            // cout << time << " has " << lowestProcessingTimes.size() << '\n';
            bool hasAddedProcessingTime {false};
            if (!lowestProcessingTimes.empty()) {
                const int procTimeIdx {lowestProcessingTimes.top().second};
                lowestProcessingTimes.pop();
                processingOrder.push_back(procTimeIdx);
                time += tasks[procTimeIdx][1];
                hasAddedProcessingTime = true;
            }

            while (!lowestEnqueueTimes.empty()) {
                const int enqTimeIdx {lowestEnqueueTimes.top().second};
                const vector<int>& enqTask {tasks[enqTimeIdx]};
                // cout << "found enq task " << enqTask[0] << " " << enqTask[1] << '\n';
                if (enqTask[0] <= time) {
                    lowestEnqueueTimes.pop();
                    lowestProcessingTimes.push({enqTask[1], enqTimeIdx});
                    hasAddedProcessingTime = true;
                } else if (!hasAddedProcessingTime) {
                    // cout << "lowest is " << enqTask[0] << '\n';
                    time = enqTask[0];
                    break;
                } else {
                    break;
                }
            }
        }

        return processingOrder;
    }
};
// @lc code=end

