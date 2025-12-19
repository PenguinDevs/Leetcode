/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);
        // ans[0] = 0 is first answer
        for (int i {1}; i <= n; ++i) {
            // Unset the highest bit
            // cout << "got " << (int)floor(log2(i)) << " @ " << i << endl;
            ans[i] = 1 + ans[i ^ (1 << (int)floor(log2(i)))];
        }
        
        return ans;
    }
};
// @lc code=end

