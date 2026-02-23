/*
 * @lc app=leetcode id=3133 lang=cpp
 *
 * [3133] Minimum Array End
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    long long minEnd(int n, long long x) {
        --n; // Include the first number as x

        int prevEmptyIdx {-1};
        for (int i {0}; i < floor(log2(n) + 1); ++i) {
            while (x & (1LL << (++prevEmptyIdx)));
            const bool bit = (n & (1LL << i)) != 0;
            if (bit) x |= (1LL << prevEmptyIdx);

            // for (int i {0}; i < 32; ++i) cout << ((x & (1LL << i)) != 0);
            // cout << '\n';
        }


        return x;
    }
};
// class Solution {
// public:
//     long long minEnd(int n, int x) {
//         bitset<32> minNum(x);

//         --n; // Include the first number as x

//         int prevEmptyIdx {-1};
//         for (int i {0}; i < floor(log2(n) + 1); ++i) {
//             while (minNum[++prevEmptyIdx] == 1);
//             minNum[prevEmptyIdx] = n & (1 << i);
//         }

//         for (int i {0}; i < 32; ++i) cout << minNum[i];
//         cout << '\n';

//         return minNum.to_ullong();
//     }
// };
// @lc code=end

