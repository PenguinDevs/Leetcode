/*
 * @lc app=leetcode id=201 lang=cpp
 *
 * [201] Bitwise AND of Numbers Range
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if (left == right) return left;

        bitset<32> bsLeft(left);
        bitset<32> bsRight(right);

        int hbsLeft {0};
        for (int i {32 - 1}; i >= 0; --i) { if (bsLeft[i]) { hbsLeft = i; break; } };
        int hbsRight {0};
        for (int i {32 - 1}; i >= 0; --i) { if (bsRight[i]) { hbsRight = i; break; } };

        if (hbsLeft == 0) return 0;
        if (hbsLeft != hbsRight) return 0;

        bitset<32> bsAnd = bsLeft & bsRight;
        int bitStartAnd {-1};
        int bitEndAnd {-1};
        for (int i {32 - 1}; i >= 0; --i) {
            if (bitStartAnd == -1) {
                if (bsAnd[i]) bitStartAnd = i;
            } else {
                if (bsLeft[i] != bsRight[i]) {
                    bitEndAnd = i + 1;
                    break;
                }
            }
        }

        bitset<32> output;
        // cout << bitStartAnd << "|" << bitEndAnd;
        for (int i {bitEndAnd}; i <= bitStartAnd; ++i) {
            output[i] = bsLeft[i];
        }
        // bitset<32> output = bsLeft & ~(bsLeft ^ bsRight);

        return output.to_ulong();
    }
};
// @lc code=end

