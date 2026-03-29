/*
 * @lc app=leetcode id=2939 lang=cpp
 *
 * [2939] Maximum Xor Product
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
// class Solution {
//     static const long long MOD = 1e9 + 7;
// public:
//     int maximumXorProduct(long long a, long long b, int n) {
//         long long mask = (1LL << n) - 1; // x < 2^n
//         long long difference = (a ^ b) & mask;

//         long long afterA {0};
//         long long afterB {0};
//         if (difference == 0) {
//             afterA = mask;
//             afterB = mask;
//         } else {
//             long long highest_bit = 1LL << (63 - __builtin_clzll(difference));
//             afterA = (mask ^ ~difference) | (difference ^ highest_bit);
//             afterB = afterA ^ difference;
//         }

//         return (afterA % MOD) * (afterB % MOD) % (MOD);
//     }
// };
class Solution {
    static const long long MOD = 1e9 + 7;
public:
    int maximumXorProduct(long long a, long long b, int n) {
        long long mask = (1LL << n) - 1;
        long long difference = (a ^ b) & mask;

        long long afterA = (a & ~mask) | (mask & ~difference);
        long long afterB = (b & ~mask) | (mask & ~difference);

        for (int i = n - 1; i >= 0; i--) {
            if (!((difference >> i) & 1)) continue;
            if (afterA <= afterB)
                afterA |= (1LL << i);
            else
                afterB |= (1LL << i);
        }

        return (afterA % MOD) * (afterB % MOD) % MOD;
    }
};
// @lc code=end

