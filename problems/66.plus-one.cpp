/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        digits[digits.size() - 1] += 1;

        for (int i = digits.size() - 1; i >= 0; --i) {
            if (digits[i] > 9) {
                if (i == 0) {
                    digits[i] -= 10;
                    digits.insert(digits.begin(), 1);
                } else {
                    ++digits[i - 1];
                    digits[i] -= 10;
                }
            } else {
                break;
            }
        }

        return digits;
    }
};
// @lc code=end

