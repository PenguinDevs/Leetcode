/*
 * @lc app=leetcode id=371 lang=cpp
 *
 * [371] Sum of Two Integers
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int getSum(int a, int b) {
        bitset<32> aMask(a);
        bitset<32> bMask(b);
        bitset<32> result;
        bool carry = false;
        
        for (int i = 0; i < 32; ++i) {
            bool a_bit = aMask[i];
            bool b_bit = bMask[i];
            bool sum_bit = a_bit ^ b_bit ^ carry;
            carry = (a_bit & b_bit) | ((a_bit ^ b_bit) & carry);
            result[i] = sum_bit;
        }

        return result.to_ulong();
    }
};
// @lc code=end

