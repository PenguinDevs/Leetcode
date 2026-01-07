/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input Array Is Sorted
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l {0};
        int r = numbers.size() - 1;

        while (l < r) {
            if (numbers[l] + numbers[r] > target) {
                --r;
            } else if (numbers[l] + numbers[r] < target) {
                ++l;
            } else {
                return {l + 1, r + 1};
            }
        }

        return {-1, -1};
    }
    // vector<int> twoSum(vector<int>& numbers, int target) {
    //     for (int i {0}; i < numbers.size(); ++i) {
    //         int l {i + 1};
    //         int r = numbers.size() - 1;

    //         const int subTarget {target - numbers[i]};

    //         while (l <= r) {
    //             int j {(l + r) / 2};
    //             // cout << "l:" << l << " r:" << r << " " << j << endl;
    //             if (numbers[j] > subTarget) {
    //                 r = j - 1;
    //             } else if (numbers[j] < subTarget) {
    //                 l = j + 1;
    //             } else {
    //                 return {i + 1, j + 1};
    //             }
    //         }

    //         // cout << "NEXT" << endl;
    //     }

    //     return {-1, -1};
    // }
};
// @lc code=end

