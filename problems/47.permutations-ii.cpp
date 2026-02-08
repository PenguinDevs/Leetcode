/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
    static const int offset = 10;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> freq(20);
        vector<int> unique_nums;
        for (const int n : nums) {
            if (freq[n + offset] == 0) {
                unique_nums.push_back(n);
            }
            ++freq[n + offset];
        }

        vector<int> currentSol;
        vector<vector<int>> sols;
        getAllCombinations(nums.size(), freq, unique_nums, currentSol, sols);

        return sols;
    }
private:
    void getAllCombinations(
        const int maxLength,
        vector<int>& freq,
        vector<int>& unique_nums,
        vector<int>& currentSol,
        vector<vector<int>>& sols
    ) {
        const int i = currentSol.size();
        if (i >= maxLength) {
            sols.push_back(currentSol);
            return;
        }

        for (const int n : unique_nums) {
            if (freq[n + offset] == 0) continue;
            --freq[n + offset];
            currentSol.push_back(n);

            getAllCombinations(maxLength, freq, unique_nums, currentSol, sols);

            currentSol.pop_back();
            ++freq[n + offset];
        }
    }
};
// @lc code=end

