/*
 * @lc app=leetcode id=918 lang=cpp
 *
 * [918] Maximum Sum Circular Subarray
 */

#include <bits/stdc++.h>
using namespace std;
 
// @lc code=start
class Solution {
public:
    // int maxSubarraySumCircular(vector<int>& nums) {
    //     const int n = nums.size();

    //     int globalMax {0};
    //     int curMax {0};
    //     int i {0};
    //     int chainStartIdx {0};
    //     while (i - chainStartIdx < n && i < 2 * n) {
    //         int tempMax = curMax + nums[i % n];
    //         cout << i << " " << tempMax << " " << nums[i % n] << endl;
    //         if (tempMax < nums[i % n]) {
    //             chainStartIdx = i;
    //         }
    //         curMax = max(tempMax, nums[i % n]);
    //         globalMax = max(globalMax, curMax);
    //         ++i;
    //     }

    //     return globalMax;
    // }
    int maxSubarraySumCircular(vector<int>& nums) {
        int globalMax {nums[0]};
        int curMax {nums[0]};
        int globalMin {nums[0]};
        int curMin {nums[0]};
        int total {nums[0]};
        for (int i {1}; i < nums.size(); ++i) {
            const int n {nums[i]};
            total += n;
            curMax = max(curMax + n, n);
            globalMax = max(globalMax, curMax);
            curMin = min(curMin + n, n);
            globalMin = min(globalMin, curMin);
        }
        if (total != globalMin) {
            globalMax = max(globalMax, total - globalMin);
        }
        return globalMax;
    }
    // This idea below didn't work :/
    // int maxSubarraySumCircular(vector<int>& nums) {
    //     const int n = nums.size();
    //     vector<int> chains;

    //     int chainSum {0};
    //     int startIdx {0};
    //     while (nums[(startIdx + 2*n - 1) % n] >= 0 && startIdx > -n) --startIdx;
    //     if (startIdx <= -n) {
    //         // All positive numbers
    //         return accumulate(nums.begin(), nums.end(), 0);
    //     };
    //     while (nums[(startIdx + n) % n] < 0 && startIdx < n) ++startIdx;
    //     if (startIdx >= n) {
    //         // All negative numbers
    //         int highest {nums[0]};
    //         for (int n : nums) highest = max(highest, n);
    //         return highest;
    //     };

    //     for (int i {startIdx}; i < startIdx + n; ++i) {
    //         if (nums[(i + n) % n] != 0 && signbit(chainSum) != signbit(nums[(i + n) % n])) {
    //             chains.push_back(chainSum);
    //             chainSum = 0;
    //         }
    //         chainSum += nums[(i + n) % n];
    //     }
    //     chains.push_back(chainSum);

    //     for (int c : chains) cout << c << " ";
    //     cout << endl;

    //     if (chains.size() == 2) return chains[0];

    //     int output {nums[0]};
    //     const int m = chains.size();
    //     // Even i contains positives
    //     // Odd i contains negatives
    //     vector<pair<int, int>> dp(m);
    //     for (int i {0}; i < m; ++++i) {
    //         int tempOutput {chains[i]};
    //         cout << "a" << i << endl;
    //         for (int j {i + 2}; j < i + m; ++++j) {
    //             cout << "b" << j << endl;
    //             if (chains[(j - 1) % m] + chains[j % m] < 0) break;
    //             cout << "j:" << j << "|t:" << tempOutput << "|cp:" << chains[(j - 1) % m] << "|cn:" << chains[j % m] << "|dp:" << dp[j % m].first << endl;
    //             if (dp[j % m].second && dp[j % m].second + m < i + m) {
    //                 tempOutput += chains[(j - 1) % m] + dp[j % m].first;
    //                 break;
    //             } else {
    //                 tempOutput += chains[(j - 1) % m] + chains[j % m];
    //             }
    //         }
    //         cout << i << "|o:" << tempOutput << endl;
    //         dp[i] = {max(dp[i].first, tempOutput), i + m};
    //         output = max(tempOutput, output);
    //     }
        
    //     return output;
    // }
//     int maxSubarraySumCircular(vector<int>& nums) {
//         const int n = nums.size();

//         int output {numeric_limits<int>::min()};
//         int chainCount {0};
//         int posHeadChainTotal {0};

//         int i {0};
//         while (nums[(i + 2 * n - 1) % n] >= 0 && i > -n) --i;
//         while (nums[(i + n) % n] < 0 && i < n) ++i;
//         if (i >= n) i -= n;
//         if (i <= -n) i += n;
//         cout << i << endl;
//         while (i < n) {
//             bool isChainEmpty {true};
//             int chainTotal {0};
//             int chainStart {i};
//             int negChainTotal {0};
//             bool countingNegs {false};
            
//             while (true) {
//                 // For handling cases of negative number only inputs
//                 output = max(output, nums[(i + n) % n]);
// 
//                 if (i >= (chainStart + n)) break;

//                 if (nums[(i + n) % n] <= 0) {
//                     if (!countingNegs && posHeadChainTotal > 0) {
//                         cout << posHeadChainTotal << " > " << negChainTotal << endl;
//                         if (posHeadChainTotal + negChainTotal < 0) break;
//                         cout << "continue" << endl;
//                         chainTotal += posHeadChainTotal + negChainTotal;
//                         isChainEmpty = false;
//                         negChainTotal = 0;
//                         posHeadChainTotal = 0;
//                     }
                    
//                     countingNegs = true;
//                     negChainTotal += nums[(i + n) % n];
//                 } else if (nums[(i + n) % n] > 0) {
//                     if (nums[(i + n - 1) % n] < 0 && chainTotal == 0) chainStart = i;
//                     countingNegs = false;
//                     posHeadChainTotal += nums[(i + n) % n];
//                 }
//                 cout << i << "|" << chainStart << "|t:" << chainTotal << "|p:" << posHeadChainTotal << "|n:" << negChainTotal << endl;
//                 ++i;
//             }

//             cout << isChainEmpty << " " << chainTotal << endl;
//             if (!isChainEmpty) {
//                 output = max(output, chainTotal);
//                 ++chainCount;
//             } else if (posHeadChainTotal > 0 && negChainTotal == 0) {
//                 output = max(output, posHeadChainTotal);
//             }
//         }

//         return output;
//     }
};
// @lc code=end

