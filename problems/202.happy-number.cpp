/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int next(int n) {
        int out {0};
        while (n > 0) {
            const int r = n % 10;
            out += r * r;
            n /= 10;
        }

        return out;
    }

    // bool isHappy(int n) {
    //     unordered_set<int> occurences;
    //     while (!occurences.contains(n)) {
    //         occurences.insert(n);
    //         n = next(n);
    //         if (n == 1) return true;
    //     }
    //     return false;
    // }
    bool isHappy(const int n) {
        int slow {n};
        int fast {n};
        do {
            slow = next(slow);
            fast = next(next(fast));
            if (fast == 1 || slow == 1) return true;
        } while (slow != fast);

        return false;
    }
};
// @lc code=end

