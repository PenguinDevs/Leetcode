/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        unordered_map<int, int> tally;
        for (const int x : nums) {
            ++tally[x];
        }

        vector<int> tallyKeys;
        for (const auto& [x, _] : tally) tallyKeys.push_back(x);

        vector<vector<int>> out;
        vector<int> currSol;
        buildSols(out, tally, tallyKeys, currSol);

        return out;
    }
private:
    void buildSols(
        vector<vector<int>>& out,
        unordered_map<int, int>& tally,
        vector<int>& tallyKeys,
        vector<int>& currSol,
        int tallyIdx = 0
    ) {
        if (tallyIdx >= tallyKeys.size()) {
            out.push_back(currSol);
            return;
        }

        const int x = tallyKeys[tallyIdx];
        for (int count {0}; count <= tally[x]; ++count) {
            // cout << tallyIdx << " " << x << " " << count << '\n';
            buildSols(out, tally, tallyKeys, currSol, tallyIdx + 1);
            currSol.push_back(x);
        }
        for (int count {0}; count <= tally[x]; ++count) currSol.pop_back();
    }
};
// @lc code=end

