/*
 * @lc app=leetcode id=191 lang=cpp
 *
 * [191] Number of 1 Bits
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int hammingWeight(int n) {
        bitset<32> bits(n);
        int count {0};
        for (int i {0}; i < 32; ++i) if (bits[i]) ++count;
        return count;
    }
};
// @lc code=end

