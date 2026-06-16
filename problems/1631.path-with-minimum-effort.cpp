/*
 * @lc app=leetcode id=1631 lang=cpp
 *
 * [1631] Path With Minimum Effort
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
struct Neighbour {
    int height;
    int i;
    int j;

    bool operator>(const Neighbour& other) const {
        return height > other.height;
    }

    bool operator<(const Neighbour& other) const {
        return height < other.height;
    }
};

class Solution {
    static constexpr pair<int, int> DIRECTIONS[] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        const int m = heights.size();
        const int n = heights[0].size();
        vector<vector<int>> dists(m, vector<int>(n, INT_MAX));
        dists[0][0] = 0;
        priority_queue<Neighbour, vector<Neighbour>, greater<Neighbour>> q;
        q.push({0, 0, 0});

        while (!q.empty()) {
            const auto top = q.top();
            q.pop();
            const auto& [height, i, j] = top;
            if (height != dists[i][j]) continue;

            for (const auto& [di, dj] : DIRECTIONS) {
                const int ni = i + di, nj = j + dj;
                if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
                const int neighbourHeight = max(height, abs(heights[i][j] - heights[ni][nj]));
                if (dists[ni][nj] > neighbourHeight) {
                    dists[ni][nj] = neighbourHeight;
                    q.push({neighbourHeight, ni, nj});
                }
            }
        }

        return dists[m - 1][n - 1];
    }
};
// @lc code=end

