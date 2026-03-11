/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;

        long long r = x;
        while (r > x / r) {
            r = (r + x / r) / 2;
        }

        return static_cast<int>(r);
    }
};
// @lc code=end

