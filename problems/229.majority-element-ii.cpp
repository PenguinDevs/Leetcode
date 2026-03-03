/*
 * @lc app=leetcode id=229 lang=cpp
 *
 * [229] Majority Element II
 */

#include <bits/stdc++.h>
using namespace std;

// [1,1,1,2,3,7,8,1,6,9]
// [1,1,1,2,3,7,8,6,1,9]

// @lc code=start
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        const int n = nums.size();

        int num1 = -1, num2 = -1;
        int count1 = 0, count2 = 0;

        for (const int x : nums) {
            if (count1 > 0 && x == num1) {
                ++count1;
            } else if (count2 > 0 && x == num2) {
                ++count2;
            } else if (count1 == 0) {
                num1 = x;
                ++count1;
            } else if (count2 == 0) {
                num2 = x;
                ++count2;
            } else {
                --count1;
                --count2;
            }
        }

        vector<int> result;
        result.reserve(2);

        int freq1 = 0, freq2 = 0;
        for (const int x : nums) {
            if (x == num1) ++freq1;
            else if (x == num2) ++freq2;
        }

        if (freq1 > n / 3) result.push_back(num1);
        if (freq2 > n / 3) result.push_back(num2);

        return result;
    }
};
// class Solution {
// public:
//     vector<int> majorityElement(vector<int>& nums) {
//         const int n = nums.size();
//         vector<int> out;
//         unordered_map<int, int> freq;

//         for (const int x : nums) {
//             if (freq[x] == -1) continue;
            
//             freq[x] += 1;
//             if (freq[x] > n / 3) {
//                 out.push_back(x);
//                 freq[x] = -1;
//             }
//         }

//         return out;
//     }
// };
// @lc code=end

