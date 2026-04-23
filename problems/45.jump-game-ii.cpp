/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 * 
 * NOTE: Idea of a greedy window is interesting
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        int res {0};
        int l {0};
        int r {1};

        while (r < nums.size()) { // Exclude last position jump
            int furthest {0};
            for (int i {l}; i < r; ++i) {
                furthest = max(furthest, i + nums[i]);
            }
            // cout << l << " " << r << " " << furthest << '\n';
            l = r;
            r = furthest + 1;
            ++res;
        }

        return res;
    }
};
// @lc code=end

