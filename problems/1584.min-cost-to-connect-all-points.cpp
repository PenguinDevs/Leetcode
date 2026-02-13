/*
 * @lc app=leetcode id=1584 lang=cpp
 *
 * [1584] Min Cost to Connect All Points
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        const int n = points.size();
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> candidates;
        candidates.push({0, 0});
        
        vector<bool> visited(n);
        vector<int> costs(n, numeric_limits<int>::max());
        costs[0] = 0;
        
        int visitedCount {0};
        while (!candidates.empty() && visitedCount < n) {
            const auto [currCost, curr] = candidates.top();
            candidates.pop();
            if (visited[curr]) continue;
            visited[curr] = true;
            ++visitedCount;

            // cout << curr << endl;

            for (int i {0}; i < n; ++i) {
                if (i == curr) continue;
                if (visited[i]) continue;
                const int cost = manhattan(points[curr], points[i]);
                if (cost < costs[i]) {
                    costs[i] = cost;
                    candidates.push({cost, i});
                }
            }
        }

        // for (const int x : costs) cout << x << " ";
        // cout << endl;

        return accumulate(costs.begin(), costs.end(), 0);
    }
private:
    int manhattan(vector<int>& u, vector<int>& v) {
        return abs(u[0] - v[0]) + abs(u[1] - v[1]);
    }
};
// @lc code=end

