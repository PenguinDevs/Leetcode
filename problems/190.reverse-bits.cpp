/*
 * @lc app=leetcode id=190 lang=cpp
 *
 * [190] Reverse Bits
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    // int reverseBits(int n) {
    //     bitset<32> bitRep(n);
        
    //     for (int i {0}; i < 16; ++i) {
    //         bool temp {bitRep[i]};
    //         bitRep[i] = bitRep[32 - i - 1];
    //         bitRep[32 - i - 1] = temp;
    //     }

    //     return (int)bitRep.to_ullong();
    // }
    int reverseBits(int n) {
        int res;

        for (int i {0}; i < 32; ++i) {
            res = (res << 1) | (n & 1);
            n >>= 1;
        }

        return res;
    }
};
// @lc code=end

