/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> out;
        vector<int> currentSol;
        dfs(out, currentSol, nums);
        return out;
    }
private:
    void dfs(
        vector<vector<int>>& out,
        vector<int>& currentSol,
        vector<int>& nums
    ) {
        if (currentSol.size() >= nums.size()) {
            out.push_back(currentSol);
            return;
        }

        for (int i {0}; i < nums.size(); ++i) {
            if (nums[i] == -11) continue;
            const int val {nums[i]};
            nums[i] = -11;
            currentSol.push_back(val);
            dfs(out, currentSol, nums);
            currentSol.pop_back();
            nums[i] = val;
        }
    }
};
// @lc code=end

