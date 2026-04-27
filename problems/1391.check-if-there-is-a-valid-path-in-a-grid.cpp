/*
 * @lc app=leetcode id=1391 lang=cpp
 *
 * [1391] Check if There is a Valid Path in a Grid
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    // static constexpr array<array<pair<int, int>, 2>, 6> ROAD_ENDPOINTS = {{
    //     {{{0, 1}, {0, -1}}}, // Street 1
    //     {{{1, 0}, {-1, 0}}}, // Street 2
    //     {{{0, -1}, {-1, 0}}}, // Street 3
    //     {{{0, 1}, {-1, 0}}}, // Street 4
    //     {{{1, 0}, {0, -1}}}, // Street 5
    //     {{{1, 0}, {0, 1}}} // Street 6
    // }};
    static constexpr array<array<bool, 4>, 6> ROAD_ENDPOINTS = {{
        {0, 1, 0, 1}, // Street 1
        {1, 0, 1, 0}, // Street 2
        {0, 0, 1, 1}, // Street 3
        {0, 1, 1, 0}, // Street 4
        {1, 0, 0, 1}, // Street 5
        {1, 1, 0, 0} // Street 6
    }};
    static constexpr pair<int, int> DIRECTIONS[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    bool hasValidPath(vector<vector<int>>& grid) {
        const int n = grid.size();
        const int m = grid[0].size();
        if (n == 1 && m == 1) return true;

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0][0] = true;
        while (!q.empty()) {
            const auto [i, j] = q.front();
            // cout << "visiting " << i << " " << j << '\n';
            q.pop();

            // const auto& currRoadEndpoints = ROAD_ENDPOINTS[grid[i][j] - 1];
            for (const auto [di, dj] : DIRECTIONS) {
                const int ni = i + di, nj = j + dj;
                if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
                if (visited[ni][nj]) continue;
                
                // bool isCompatible {false};
                // for (const auto& road1Endpoint : currRoadEndpoints) {
                //     for (const auto& road2Endpoint : ROAD_ENDPOINTS[grid[ni][nj] - 1]) {
                //         if (
                //             (i != ni && road1Endpoint.first == -road2Endpoint.first) ||
                //             (j != nj && road1Endpoint.second == -road2Endpoint.second)
                //         ) {
                //             isCompatible = true;
                //             break;
                //         }
                //     }
                //     if (isCompatible) break;
                // }
                // if (!isCompatible) continue;
                
                // cout << i << " " << j << '\n';
                // cout << "di" << di << " -> " << ROAD_ENDPOINTS[grid[i][j] - 1][2] << " " << ROAD_ENDPOINTS[grid[ni][nj] - 1][0] << '\n';
                // cout << "dj" << dj << " -> " << ROAD_ENDPOINTS[grid[i][j] - 1][1] << " " << ROAD_ENDPOINTS[grid[ni][nj] - 1][3] << '\n';
                if (di == 1 && (!ROAD_ENDPOINTS[grid[i][j] - 1][2] || !ROAD_ENDPOINTS[grid[ni][nj] - 1][0])) {
                    continue;
                } else if (di == -1 && (!ROAD_ENDPOINTS[grid[i][j] - 1][0] || !ROAD_ENDPOINTS[grid[ni][nj] - 1][2])) {
                    continue;
                } else if (dj == 1 && (!ROAD_ENDPOINTS[grid[i][j] - 1][1] || !ROAD_ENDPOINTS[grid[ni][nj] - 1][3])) {
                    continue;
                } else if (dj == -1 && (!ROAD_ENDPOINTS[grid[i][j] - 1][3] || !ROAD_ENDPOINTS[grid[ni][nj] - 1][1])) {
                    continue;
                }

                // cout << i << " " << j << " is compatible with " << ni << " " << nj << '\n';
                // cout << grid[i][j] << " is compatible with " << grid[ni][nj] << '\n';
                q.push({ni, nj});

                visited[ni][nj] = true;
                if (ni == n - 1 && nj == m - 1) return true;
            }
        }

        return false;
    }
};
// @lc code=end

