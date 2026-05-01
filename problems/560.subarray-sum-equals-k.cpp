/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        const int n = nums.size();

        unordered_map<int, int> prefixSum;
        ++prefixSum[0];
        
        int total {0};
        int prevSum {0};
        for (int i {0}; i < n; ++i) {
            prevSum += nums[i];
            total += prefixSum[prevSum - k];
            prefixSum[prevSum] += 1;
        }

        return total;
    }
};
// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         const int n = nums.size();
        
//         vector<int> prefixSum(n + 1);
//         for (int i {1}; i <= n; ++i) prefixSum[i] += prefixSum[i - 1] + nums[i];

//         int total {0};
//         int r {0};
//         for (int l {0}; l <= n; ++l) {
//             while (int sum = prefixSum[r++] - prefixSum[l] < k) {
                
//             };
//         }

//         return total;
//     }
// };
// @lc code=end

