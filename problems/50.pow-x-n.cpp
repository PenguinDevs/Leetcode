/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    double myPow(double x, int n) {
        const bool isNeg {n < 0};
        double pow = 1;
        while(n != 0){
            if((n % 2) != 0) pow *= x;

            x *= x;
            n /= 2;
        }

        return !isNeg ? pow : 1 / pow;
    }
};
// @lc code=end

