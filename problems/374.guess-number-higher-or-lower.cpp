/*
 * @lc app=leetcode id=374 lang=cpp
 *
 * [374] Guess Number Higher or Lower
 */

#include <bits/stdc++.h>
using namespace std;

int guess(int num);

// @lc code=start
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        unsigned int l = 1;
        unsigned int r = n;

        while (l < r) {
            const unsigned int m = (l + r) / 2;
            
            // cout << l << " " << r << " " << m << endl;

            if (guess(m) > 0) {
                // Guess is low
                l = m + 1;
            } else if (guess(m) < 0) {
                // Guess is high
                r = m;
            } else return m;
        }

        return l;
    }
};
// @lc code=end

