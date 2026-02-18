/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 *
 * NOTE: See the alternative binary search solution which is more interesting
 * and useful to know.
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int largestSum {INT_MIN}, currSum {0};
        for (const int x : nums) {
            currSum += x;
            largestSum = max(largestSum, currSum);
            if (currSum < 0) {
                currSum = 0;
            }
        }

        return largestSum;
    }
};
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         const int n = nums.size();
        
//         vector<int> slidingWindow(n + 1);
//         for (int i {0}; i < n; ++i) {
//             slidingWindow[i + 1] = nums[i] + slidingWindow[i];
//         }

//         int largestSum {slidingWindow[n]};
//         int l {0};
//         int r = n;
//         while (l < r) {
//             cout << l << " " << r << endl;
//             if (slidingWindow[r] - slidingWindow[l + 1] > slidingWindow[r - 1] - slidingWindow[l]) {
//                 ++l;
//             } else {
//                 --r;
//             }

//             largestSum = max(largestSum, slidingWindow[r] - slidingWindow[l]);
//         }

//         if (largestSum == 0) largestSum = *max_element(nums.begin(), nums.end());

//         // for (int i {0}; i < n + 1; ++i) {
//         //     for (int j {i + 1}; j < n + 1; ++j) {
//         //         largestSum = max(largestSum, slidingWindow[j] - slidingWindow[i]);
//         //     }
//         // }

//         return largestSum;
//     }
// };
// @lc code=end

