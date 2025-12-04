/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int output {nums[0]};
        int forwardProduct {1};
        int backwardProduct {1};

        for (int i {0}; i < nums.size(); ++i) {
            forwardProduct = nums[i] * (forwardProduct != 0 ? forwardProduct : 1);
            backwardProduct = nums[nums.size() - 1 - i] * (backwardProduct != 0 ? backwardProduct : 1);

            output = max(max(forwardProduct, backwardProduct), output);
        }

        return output;
    }
};
// @lc code=end

