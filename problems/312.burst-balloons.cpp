/*
 * @lc app=leetcode id=312 lang=cpp
 *
 * [312] Burst Balloons
 * 
 * TODO: Needs to be optimised further in speed somehow?
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        const int n = nums.size();
        
        // Must not be indexed by i + 1 instead
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);

        // Cut dp cache in half, but requires indexing by n - 1 - i instead
        // e.g. dp[i][j] should instead be dp[i][n - 1 - j]
        vector<vector<int>> dp;
        dp.reserve(n);
        for (int s {n}; s >= 1; --s) {
            dp.push_back(vector<int>(s, -1));
        }

        for (int length {0}; length < n; ++length) {
            for (int l {0}; l < n - length; ++l) {
                const int r = l + length;

                for (int i {l}; i <= r; ++i) {
                    // cout << "(" << l << ":" << r << ") i@" << i << " using: " << nums[l] << "," << nums[i + 1] << "," << nums[r + 2] << endl;
                    // nums[i + 1] is the middle chosen value
                    const int chosenSum = nums[l] * nums[i + 1] * nums[r + 2];
    
                    const int lSum = (l <= i - 1) ? dp[l][n - 1 - (i - 1)] : 0;
                    const int rSum = (i + 1 <= r) ? dp[i + 1][n - 1 - r] : 0;

                    // cout << "summing: " << lSum << "," << chosenSum << "," << rSum << endl;

                    dp[l][n - 1 - r] = max(dp[l][n - 1 - r], lSum + chosenSum + rSum);
                }
            }
        }

        return dp[0][0]; // Actually is dp[0][n - 1];
    }
};
// class Solution {
// public:
//     int maxCoins(vector<int>& nums) {
//         const int n = nums.size();
//         vector<vector<int>> dp(n, vector<int>(n, -1));
//         // for (int i {0}; i < n; ++i) {
//         //     dp[i][i] = nums[i];
//         // }

//         nums.insert(nums.begin(), 1);
//         nums.insert(nums.end(), 1);
        
//         for (int i {0}; i < n; ++i) {
//             // i + 1 is the middle (chosen) value
//             dp[i][i] = nums[i] * nums[i + 1] * nums[i + 2];
//         }
        
//         return testEach(nums, dp, 0, n - 1);
//     }
// private:
//     int testEach(const vector<int>& nums, vector<vector<int>>& dp, const int l, const int r) {
//         // cout << l << " " << r << endl;
//         if (dp[l][r] != -1) return dp[l][r];
        
//         for (int i {l}; i <= r; ++i) {
//             // i + 1 is the middle (chosen) value
//             int chosenSum = nums[l] * nums[i + 1] * nums[r + 2];
//             // cout << "(" << l << ":" << r << ") i@" << i << " using: " << nums[i] << "," << nums[i + 1] << "," << nums[i + 2] << endl;

//             const int lSum = (i != l && l <= i - 1) ? testEach(nums, dp, l, i - 1) : 0;
//             const int rSum = (i != r && i + 1 <= r) ? testEach(nums, dp, i + 1, r) : 0;
//             // if (lSum == 0) chosenSum *= nums[i];
//             // if (rSum == 0) chosenSum *= nums[i + 2];

//             // cout << "summing: " << lSum << "," << chosenSum << "," << rSum << endl;
        
//             dp[l][r] = max(dp[l][r], lSum + chosenSum + rSum);
//         }

//         // cout << "l:" << l << " r:" << r << " sum:" << dp[l][r] << endl;

//         return dp[l][r];
//     }
// };
// @lc code=end

