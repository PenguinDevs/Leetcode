/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> out;
        vector<int> currSol;
        buildSols(out, currSol, n, k);
        return out;
    }
private:
    void buildSols(
        vector<vector<int>>& out,
        vector<int>& currSol,
        int n,
        int k,
        int i = 1
    ) {
        if (currSol.size() == k) {
            out.push_back(currSol);
            return;
        }

        for (int x {i}; x <= n; ++x) {
            currSol.push_back(x);
            buildSols(out, currSol, n, k, x + 1);
            currSol.pop_back();
        }
    }
};
// @lc code=end

