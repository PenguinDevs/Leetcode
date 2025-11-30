/*
 * @lc app=leetcode id=778 lang=cpp
 *
 * [778] Swim in Rising Water
 * 
 * NOTE: Use static array for 4 directional movement
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        const int n = grid.size();

        using Node = pair<int, array<int, 2>>;
        priority_queue<Node, vector<Node>, greater<Node>> candidates;
        candidates.push({grid[0][0], {0, 0}});
        vector<vector<bool>> visited(n, vector<bool>(n));
        visited[0][0] = true;

        int maxT {0};
        static constexpr array<array<int, 2>, 4> directions = {{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};
        while (!candidates.empty()) {
            const auto [t, pos] = candidates.top();
            
            maxT = max(maxT, t);
            // cout << t << " " << maxT << endl;
            
            // Reached the bottom right most tile
            if (pos[0] == n - 1 && pos[1] == n - 1) break;
            
            candidates.pop();
            
            for (const auto& [di, dj] : directions) {
                int i {pos[0] + di};
                int j {pos[1] + dj};
                
                if (i < 0 || i >= n || j < 0 || j >= n) continue;
                if (visited[i][j]) continue;
                visited[i][j] = true;
                
                candidates.push({grid[i][j], {i, j}});
            }
        }

        return maxT;
    }
};
// class Solution {
// public:
//     int swimInWater(vector<vector<int>>& grid) {
//         const int n = grid.size();

//         vector<pair<int, array<int, 2>>> candidates;
//         candidates.push_back({-grid[0][0], {0, 0}});
//         vector<vector<bool>> visited(n, vector<bool>(n));

//         int t {0};
//         while (!candidates.empty()) {
//             pop_heap(candidates.begin(), candidates.end());
//             auto [negT, pos] = candidates.back();
            
//             t = max(t, -negT);
//             // cout << -negT << " " << t << endl;

//             // Reached the bottom right most tile
//             if (pos[0] == n - 1 && pos[1] == n - 1) break;

//             candidates.pop_back();
//             visited[pos[0]][pos[1]] = true;

//             checkNeighbour(n, pos[0] - 1, pos[1], grid, visited, candidates);
//             checkNeighbour(n, pos[0] + 1, pos[1], grid, visited, candidates);
//             checkNeighbour(n, pos[0], pos[1] - 1, grid, visited, candidates);
//             checkNeighbour(n, pos[0], pos[1] + 1, grid, visited, candidates);
//         }

//         return t;
//     }
// private:
//     void checkNeighbour(
//         int n,
//         int i,
//         int j,
//         vector<vector<int>>& grid,
//         vector<vector<bool>>& visited,
//         vector<pair<int, array<int, 2>>>& candidates
//     ) {
//         if (i < 0 || i >= n || j < 0 || j >= n) return;
//         if (visited[i][j]) return;
        
//         candidates.push_back({-grid[i][j], {i, j}});
//         push_heap(candidates.begin(), candidates.end());
//     }
// };
// @lc code=end

