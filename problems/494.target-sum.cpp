/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<int, int> prevDP;
        unordered_map<int, int> currDP;
        prevDP[0] = 1;

        for (int i {0}; i < nums.size(); ++i) {
            currDP.clear();
            for (const auto& [capacity, count] : prevDP) {
                currDP[capacity + nums[i]] += count;
                currDP[capacity - nums[i]] += count;
            }
            swap(prevDP, currDP);
        }

        return prevDP[target];
    }
};
// class Solution {
// public:
//     int findTargetSumWays(vector<int>& nums, int target) {
//         // for each k in nums
//         // dp[i][j] = sum each p of dp[each p][j - nums[p]]
//         // dp[i][j] = sum each p of dp[each p][j + nums[p]]
        
//         // dp[i][accumulated]
//         const int offset {1000};
//         vector<vector<int>> dp(nums.size(), vector<int>(offset * 2 + 1));
//         dp[0][offset] = 1;

//         // for (int i = nums.size() - 2; i >= 0; --i) {
//         //     for (int j {target}; j >= 0; --j) {
//         //         // cout << i << " " << j << " " << nums[i] << '\n';
//         //         if (j + nums[i] <= target) dp[i][j + nums[i]] += dp[i + 1][j];
//         //         if (j - nums[i] >= 0) dp[i][j - nums[i]] += dp[i + 1][j];
//         //     }
//         // }

//         for (int i {1}; i < nums.size(); ++i) {
//             for (int j {-offset}; j <= offset; ++j) {
//                 // cout << i << " " << j << " " << nums[i] << '\n';
//                 if (j + nums[i] + offset <= dp.size()) dp[i][j + nums[i] + offset] += dp[i - 1][j + offset];
//                 if (j - nums[i] + offset >= 0) dp[i][j - nums[i] + offset] += dp[i - 1][j + offset];
//             }
//         }

//         for (const auto& row : dp) {
//             for (const int x : row) cout << x << ' ';
//             cout << '\n';
//         }


//         // return dp[0][0];
//         return dp[nums.size() - 1][target + offset];
//     }
// };
// class Solution {
// public:
//     int findTargetSumWays(vector<int>& nums, int target) {
//         return exploreSums(nums, target);
//     }
// private:
//     int exploreSums(vector<int>& nums, int target, int i = 0, int accumulated = 0) {
//         if (i == nums.size()) return accumulated == target;
//         int total {0};
//         total += exploreSums(nums, target, i + 1, accumulated + nums[i]);
//         total += exploreSums(nums, target, i + 1, accumulated - nums[i]);

//         return total;
//     }
// };
// @lc code=end
