/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        
        vector<vector<int>> output;
        if (n < 4) return output;
        
        sort(nums.begin(), nums.end());

        static const int64_t limit = numeric_limits<int>::max();
        for (int i {0}; i < n - 3; ++i) {
            for (int j {i + 1}; j < n - 2; ++j) {
                int l {j + 1};
                int r {n - 1};
                int64_t subTarget {int64_t(target) - int64_t(nums[i]) - int64_t(nums[j])};
                if (subTarget < -limit || subTarget > limit) continue;

                while (l < r) {
                    int64_t tempSum {int64_t(nums[l]) + int64_t(nums[r])};
                    if (tempSum < subTarget) {
                        ++l;
                    } else if (tempSum > subTarget) {
                        --r;
                    } else {
                        output.push_back({nums[i], nums[j], nums[l], nums[r]});
                        ++l;
                        --r;
                        while (l < r && nums[l - 1] == nums[l]) ++l;
                        while (l < r && nums[r + 1] == nums[r]) --r;
                    }
                }

                while (j < n - 2 && nums[j] == nums[j + 1]) ++j;
            }
            while (i < n - 3 && nums[i] == nums[i + 1]) ++i;
        }
        
        return output;
    }
// Very slop
// public:
//     vector<vector<int>> fourSum(vector<int>& nums, int target) {
//         vector<vector<int>> output;
//         if (nums.size() < 4) return output;
        
//         sort(nums.begin(), nums.end());
//         unordered_map<int, int> containsNum;
//         for (int n : nums) containsNum[n] += 1;

//         // cout << nums.size() << endl;
//         int lastIN {nums[0] - 1};
//         for (int i {0}; i < nums.size() - 3; ++i) {
//             if (nums[i] == lastIN) continue;
//             lastIN = nums[i];

//             int lastJN {nums[i] - 1};
//             for (int j {i + 1}; j < nums.size() - 2; ++j) {
//                 if (nums[j] == lastJN) continue;
//                 lastJN = nums[j];
                
//                 int lastKN {nums[j] - 1};
//                 for (int k {j + 1}; k < nums.size() - 1; ++k) {
//                     if (nums[k] == lastKN) continue;
//                     lastKN = nums[k];
                    
//                     vector<int> sol = {nums[i], nums[j], nums[k]};
//                     // int64_t solSum = accumulate(sol.begin(), sol.end(), 0);
//                     int64_t solSum = (int64_t)nums[i] + (int64_t)nums[j] + (int64_t)nums[k];
//                     static const int64_t limit = numeric_limits<int>::max();
//                     if (-limit > ((int64_t)target - solSum)) continue;
//                     if (limit < ((int64_t)target - solSum)) continue;
                    
//                     int lastN = (int64_t)target - solSum;
//                     // cout << lastN << " " << solSum << " " << target << endl;
//                     if (lastN < nums[k]) continue;
//                     // cout << (containsNum[lastN] > count(sol.begin(), sol.end(), lastN)) <<  " " << count(sol.begin(), sol.end(), lastN) << " " << containsNum[lastN];
//                     if (containsNum[lastN] > 0 && containsNum[lastN] > count(sol.begin(), sol.end(), lastN)) {
//                         sol.push_back(lastN);
//                         output.push_back(sol);
//                     }
//                 }
//             }
//         }

//         return output;
//     }
};
// @lc code=end

