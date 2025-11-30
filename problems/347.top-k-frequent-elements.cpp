/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        for (int n : nums) {
            freq[n] += 1;
        }

        vector<pair<int, int>> sorted_freq;
        for (auto [n, count] : freq) {
            sorted_freq.push_back({count, n});
        }
        sort(sorted_freq.begin(), sorted_freq.end(), greater<pair<int, int>>());

        vector<int> output;
        auto nPointer = sorted_freq.begin();
        for (int i {0}; i < k; ++i) {
            auto [count, n] = *nPointer;
            output.push_back(n);
            nPointer++;
        }

        return output;
    }
};
// @lc code=end

