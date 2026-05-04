/*
 * @lc app=leetcode id=743 lang=cpp
 *
 * [743] Network Delay Time
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> adjacency(n);
        vector<vector<int>> weights(n, vector<int>(n, INT_MAX));
        
        for (const vector<int>& edge : times) {
            adjacency[edge[0] - 1].push_back(edge[1] - 1);
            weights[edge[0] - 1][edge[1] - 1] = edge[2];
        }

        vector<int> dists(n, INT_MAX);
        priority_queue<pair<int, int>> pq;
        dists[k - 1] = 0;
        pq.push({0, k - 1});
        while (!pq.empty()) {
            const auto [dist, curr] = pq.top();
            pq.pop();

            for (const auto neighbour : adjacency[curr]) {
                if (dist + weights[curr][neighbour] < dists[neighbour]) {
                    dists[neighbour] = dist + weights[curr][neighbour];
                    pq.push({dists[neighbour], neighbour});
                }
            }
        }

        const int maxFound {*max_element(dists.begin(), dists.end())};
        return maxFound == INT_MAX ? -1 : maxFound;
    }
};
// @lc code=end

