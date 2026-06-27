/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> out;
        deque<int> q;

        for (int i {0}; i < nums.size(); ++i) {
            while (!q.empty() && q.front() <= i - k) {
                q.pop_front();
            }
            while (!q.empty() && nums[q.back()] < nums[i]) {
                q.pop_back();
            }
            q.push_back(i);
            // if (i + 1 >= k) {
            //     int max {INT_MIN};
            //     for (const int i : q) {
            //         if (nums[i] > max) max = nums[i];
            //     }
            //     out.push_back(max);
            // }
            if (i + 1 >= k) out.push_back(nums[q.front()]);
        }

        return out;
    }
};

// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         vector<int> out;
//         priority_queue<pair<int, int>> pq;

//         for (int i {0}; i < k - 1; ++i) {
//             pq.push({nums[i], i});
//         }

//         for (int i {k - 1}; i < nums.size(); ++i) {
//             const int x = nums[i];

//             pq.push({x, i});

//             // Can't be empty, k >= 1
//             // while (!pq.empty() && pq.top().second < i - k) {
//             while (pq.top().second <= i - k) {
//                 pq.pop();
//             }
//             out.push_back(pq.top().first);
//         }

//         return out;
//     }
// };
// @lc code=end

