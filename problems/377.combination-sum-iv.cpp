/*
 * @lc app=leetcode id=377 lang=cpp
 *
 * [377] Combination Sum IV
 *
 * // NOTE: Just because there are two nested loops, does not mean you need a 2D
 * dp matrix.
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
// class Solution {
// public:
//     int combinationSum4(vector<int>& nums, int target) {
//         vector<unsigned int> memo(target + 1, -1);
//         return combinationSum4Aux(0, nums, target, memo);
//     }
// private:
//     int combinationSum4Aux(
//         int current,
//         vector<int>& nums,
//         int target,
//         vector<unsigned int>& memo
//     ) {
//         if (current == target) return 1;
        
//         int total {0};
//         for (auto n : nums) {
//             unsigned int newValue = current + n;
//             if (target < newValue) continue;
//             if (memo[newValue] != -1) {
//                 total += memo[newValue];
//             } else {
//                 total += combinationSum4Aux(newValue, nums, target, memo);
//             }
//         }
//         memo[current] = total;

//         return total;
//     }
// };
// class Solution {
// public:
//     int combinationSum4(vector<int>& nums, int target) {
//         vector<unsigned int> memo(target + 1, -1);
//         return combinationSum4Aux(target, nums, target, memo);
//     }
// private:
//     int combinationSum4Aux(
//         int current,
//         vector<int>& nums,
//         int target,
//         vector<unsigned int>& memo
//     ) {
//         if (current == 0) return 1;
        
//         unsigned int total {0};
//         for (auto n : nums) {
//             if (n > current) continue; // i.e. n - i < 0 out of index
//             if (memo[current - n] != -1) {
//                 total += memo[current - n];
//             } else {
//                 total += combinationSum4Aux(current - n, nums, target, memo);
//             }
//         }
//         memo[current] = total;

//         return total;
//     }
// };
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int size = nums.size();
        // By tabulation
        // First dimension i is capacity to target
        // Second dimension j is jth element of nums
        vector<unsigned int> dp(target, 0);
        
        for (int i {target}; i >= 0; --i) {
            for (int j {0}; j < size; ++j) {
                int n = nums[j];
                // Impossible combination element
                if (nums[j] > target) continue;
                if (n > i) continue; // i.e. n - i < 0 out of index
                unsigned int newValue = i - n;

                if (i == target) {
                    // cout << "initialising" << i << " " << n << endl;
                    dp[newValue] += 1;
                } else {
                    // if (i < 990) cout << "new biz" << newValue << " " << i << " " << n << endl;
                    dp[newValue] += dp[i];
                }
            }
        }

        return dp[0];
    }
};
// class Solution {
// public:
//     int combinationSum4(vector<int>& nums, int target) {
//         int size = nums.size();
//         // By tabulation
//         // First dimension i is capacity to target
//         // Second dimension j is jth element of nums
//         vector<vector<unsigned int>> dp(target, vector<unsigned int>(size));
        
//         for (int i {target}; i >= 0; --i) {
//             for (int j {0}; j < size; ++j) {
//                 int n = nums[j];
//                 // Impossible combination element
//                 if (nums[j] > target) continue;
//                 if (n > i) continue; // i.e. n - i < 0 out of index
//                 unsigned int newValue = i - n;

//                 if (i == target) {
//                     // cout << "initialising" << i << " " << n << endl;
//                     dp[newValue][j] = 1;
//                 } else {
//                     // if (i < 990) cout << "new biz" << newValue << " " << i << " " << n << endl;
//                     dp[newValue][j] += accumulate(dp[i].begin(), dp[i].end(), 0);
//                 }
//             }
//         }

//         return accumulate(dp[0].begin(), dp[0].end(), 0);
//     }
// };
// @lc code=end

