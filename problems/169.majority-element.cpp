/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         map<int, int> count;

//         int threshold = nums.size() / 2;

//         // Won't ever remain as 0 assuming majority always exists.
//         int majority {0};
//         for (auto x : nums) {
//             count[x] += 1;

//             if (count[x] > threshold) {
//                 majority = x;
//                 break;
//             }
//         }

//         return majority;
//     }

public:
    int majorityElement(vector<int>& nums) {
        int current {0};
        int count {0};

        for (auto x : nums) {
            if (count == 0) current = x;
            count += current == x ? 1 : -1;
        }

        return current;
    }

};
// @lc code=end

