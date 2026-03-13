/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> currentSol;
        vector<vector<int>> out;
        
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, currentSol, out);

        return out;
    }
private:
    void dfs(
        vector<int>& candidates,
        int target,
        vector<int>& currentSol,
        vector<vector<int>>& out,
        int i = 0,
        int sum = 0
    ) {
        if (sum > target) return;
        if (sum == target) {
            out.push_back(currentSol);
            return;
        }
        if (i >= candidates.size()) return;
        
        currentSol.push_back(candidates[i]);
        dfs(candidates, target, currentSol, out, i + 1, sum + candidates[i]);
        currentSol.pop_back();

        while (i + 1 < candidates.size() && candidates[i] == candidates[i + 1]) ++i;
        dfs(candidates, target, currentSol, out, i + 1, sum);
    }
};
// @lc code=end

