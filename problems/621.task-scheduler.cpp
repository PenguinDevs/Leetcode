/*
 * @lc app=leetcode id=621 lang=cpp
 *
 * [621] Task Scheduler
 */

#include <bits/stdc++.h>
#include <ranges>
using namespace std;

// @lc code=start
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (char t : tasks) {
            freq[t - 'A']++;
        }
        
        priority_queue<int> pq;
        for (int f : freq) {
            if (f > 0) {
                pq.push(f);
            }
        }
        
        int time {0};
        while (!pq.empty()) {
            vector<int> temp;
            
            // stuff in the most frequent tasks first for each
            // int idling {0};
            for (int i = 0; i < n + 1; ++i) {
                if (!pq.empty()) {
                    int f = pq.top();
                    pq.pop();
                    f--;
                    temp.push_back(f);
                } else {
                    // all done atp
                    // idling += n - i + 1;
                    break;
                }
            }
        
            for (int f : temp) {
                if (f > 0) {
                    pq.push(f);
                }
            }
        
            // Don't include the trailing idling time if final
            // time += pq.empty() ? temp.size() : temp.size() + idling;
            time += pq.empty() ? temp.size() : n + 1;
        }
        
        return time;
    }
};
// @lc code=end

