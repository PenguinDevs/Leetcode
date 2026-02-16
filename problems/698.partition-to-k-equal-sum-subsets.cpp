/*
 * @lc app=leetcode id=698 lang=cpp
 *
 * [698] Partition to K Equal Sum Subsets
 * 
 * NOTE: This problem can be decomposed into something trivial
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        const int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % k != 0) return false;
        const int target = total / k;

        sort(nums.rbegin(), nums.rend());
        if (nums[0] > target) return false;

        vector<int> buckets(k, 0);
        return backtrack(nums, buckets, target, 0);
    }
private:
    bool backtrack(vector<int>& nums, vector<int>& buckets, int target, int idx) {
        if (idx == nums.size()) return true;
        for (int i {0}; i < buckets.size(); ++i) {
            if (buckets[i] + nums[idx] > target) continue;
            buckets[i] += nums[idx];
            if (backtrack(nums, buckets, target, idx + 1)) return true;
            buckets[i] -= nums[idx];
            if (buckets[i] == 0) break; // All empty buckets are equivalent
        }
        return false;
    }
};

// class Solution {
// public:
//     bool canPartitionKSubsets(vector<int>& nums, int k) {
//         const int total = accumulate(nums.begin(), nums.end(), 0);
//         if (total % k != 0) return false;
//         const int target = total / k;

//         sort(nums.begin(), nums.end());
//         if (nums.back() > target) return false;

//         vector<int> dp(1 << nums.size(), -1);
//         dp[0] = 0;

//         for (int i {0}; i < (1 << nums.size()); ++i) {
//             if (dp[i] == -1) continue;
//             for (int j {0}; j < nums.size(); ++j) {
//                 if (i & (1 << j)) continue; // Already set
//                 if (dp[i] + nums[j] > target) break;
//                 dp[i | (1 << j)] = (dp[i] + nums[j]) % target;
//             }
//         }

//         return dp[(1 << nums.size()) - 1] == 0;
//     }
// };

// class Solution {
// public:
//     bool canPartitionKSubsets(vector<int>& nums, int k) {
//         const int total = accumulate(nums.begin(), nums.end(), 0);
//         if (total % k != 0) return false;
//         const int target = total / k;

//         vector<int> memo(1 << nums.size(), -1);
//         bitset<16> used;
//         return backtrack(nums, k, target, memo, used, 0);
//     }
// private:
//     bool backtrack(
//         vector<int>& nums,
//         int k,
//         int target,
//         vector<int>& memo,
//         bitset<16>& used,
//         int subsetSum = 0
//     ) {
//         if (memo[used.to_ulong()] != -1) return memo[used.to_ulong()];
        
//         // for (int i {0}; i < 16; ++i) cout << used[i] << " ";
//         // cout << "   ";
//         // cout << subsetSum << " " << target << endl;

//         if (subsetSum > target) {
//             return false;
//         } else if (subsetSum == target) {
//             return backtrack(nums, k, target, memo, used, 0);
//         }

//         bool hasAllUsed {true};
//         for (int i {0}; i < nums.size(); ++i) {
//             if (used[i]) continue;
//             hasAllUsed = false;

//             used[i] = true;
//             if (backtrack(nums, k, target, memo, used, subsetSum + nums[i])) {
//                 memo[used.to_ulong()] = true;
//                 return true;
//             }
//             used[i] = false;
//         }
//         if (hasAllUsed) {
//             memo[used.to_ulong()] = true;
//             return true;
//         }

//         memo[used.to_ulong()] = false;
//         return false;
//     }
// };

// class Solution {
// public:
//     bool canPartitionKSubsets(vector<int>& nums, int k) {
//         const int total = accumulate(nums.begin(), nums.end(), 0);
//         if (total % k != 0) return false;
//         const int target = total / k;

//         cout << target << endl;

//         for (int i {0}; i < k - 1; ++i) {
//             bitset<16> sol;
//             if (!getSubsetSum(nums, total, k, sol)) return false;
//             for (int j {15}; j >= 0; --j) {
//                 cout << sol[j];
//                 if (sol[j]) nums.erase(nums.begin() + j);
//             }
//             cout << endl;
//             --k;
//         }

//         return accumulate(nums.begin(), nums.end(), 0) == target;
//     }

//     // Returns indices of elements included
//     bool getSubsetSum(
//         vector<int>& nums,
//         const int total,
//         const int k,
//         bitset<16>& currentSol,
//         int currentSolTotal = 0,
//         int lookAfter = 0
//     ) {
//         const int target = total / k;
//         if (currentSolTotal > target) {
//             return false;
//         } else if (currentSolTotal == target) {
//             int newTotal {total};
//             for (int i {0}; i < 16; ++i) {
//                 if (currentSol[i]) newTotal -= nums[i];
//             }
//             if (newTotal % (k - 1) != 0) return false;
//             return newTotal / (k - 1) == target;
//         }

//         for (int i {lookAfter}; i < nums.size(); ++i) {
//             currentSol[i] = true;
//             if (getSubsetSum(nums, total, k, currentSol, currentSolTotal + nums[i], i + 1)) {
//                 return true;
//             }
//             currentSol[i] = false;
//         }

//         return false;
//     }
// };
// @lc code=end

