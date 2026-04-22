/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 * 
 * NOTE: There is a O(1) space sol to this
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        const int n = nums.size();
        vector<int> jumpingStates(n);

        for (int i {0}; i < n; ++i) {
            ++jumpingStates[i];
            --jumpingStates[min(i + nums[i], n - 1)];
        }

        int jumpStateCounter {0};
        for (int i {0}; i < n; ++i) {
            jumpStateCounter += jumpingStates[i];
            // cout << i << " " << jumpStateCounter << '\n';
            if (jumpStateCounter == 0 && i != n - 1) return false;
        }

        return true;
    }
};
// @lc code=end

