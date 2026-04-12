/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;

        int prev = 2;
        int prevPrev = 1;

        for (int i {3}; i <= n; ++i) {
            const int oldPrev = prev;
            prev = prevPrev + prev;
            prevPrev = oldPrev;
        }

        return prev;
    }
};
// @lc code=end

