/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 * 
 * NOTE: Order of looping in this dp matters, notice how it loops candidates first
 * so that it doesnt go backwards in the candidates to choose in the future.
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> out;
        vector<int> sol;
        dfs(candidates, target, out, sol);

        return out;
    }
private:
    void dfs(
        const vector<int>& candidates,
        const int target,
        vector<vector<int>>& out,
        vector<int>& sol,
        const int candI = 0
    ) {
        if (target == 0) {
            out.push_back(sol);
            return;
        } else if (target < 0) {
            return;
        }
        
        for (int i {candI}; i < candidates.size(); ++i) {
            sol.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], out, sol, i);
            sol.pop_back();
        }
    }
};

// class Solution {
// public:
//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         const int n = candidates.size();
//         vector<vector<vector<int>>> dp(target + 1);
//         dp[0] = {{}};

//         for (const int n : candidates) {
//             for (int cap {n}; cap <= target; ++cap) {
//                 for (auto vCopy : dp[cap - n]) {
//                     vCopy.push_back(n);
//                     dp[cap].push_back(vCopy);
//                 }
//             }
//         }

//         cout << "out";
//         return dp[target];
//     }
// };

// class Solution {
// public:
//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         const int n = candidates.size();
//         vector<vector<pair<int, int>>> dp(target + 1);

//         // Map
//         for (const int n : candidates) {
//             for (int cap {n}; cap <= target; ++cap) {
//                 if (dp[cap - n].empty() && cap - n != 0) continue;

//                 dp[cap].push_back({cap - n, n});
//             }
//         }

//         // Build sols
//         vector<vector<int>> out;
//         vector<int> currentSol;
//         dfsBuild(dp, out, currentSol, target);

//         return out;
//     }
// private:
//     void dfsBuild(
//         vector<vector<pair<int, int>>>& nodes,
//         vector<vector<int>>& out,
//         vector<int>& currentSol,
//         const int i
//     ) {
//         if (i == 0) {
//             out.push_back(currentSol);
//         }

//         for (const auto [j, n] : nodes[i]) {
//             currentSol.push_back(n);
//             dfsBuild(nodes, out, currentSol, j);
//             currentSol.pop_back();
//         }
//     }
// };
// @lc code=end

