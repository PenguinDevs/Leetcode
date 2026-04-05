/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int n = nums.size();

        int forwardProd {1};
        int backwardProd {1};
        vector<int> out(n, 1);
        for (int i {0}; i < nums.size(); ++i) {
            out[i] *= forwardProd;
            out[n - i - 1] *= backwardProd;

            forwardProd *= nums[i];
            backwardProd *= nums[n - i - 1];
        }

        return out;
    }
    // vector<int> productExceptSelf(vector<int>& nums) {
    //     const int n = nums.size();
    //     vector<int> backwardProducts(n + 1);
    //     backwardProducts[n] = 1;

    //     for (int i {n - 1}; i >= 0; --i) {
    //         backwardProducts[i] = nums[i] * backwardProducts[i + 1];
    //     }

    //     vector<int> out(n);
    //     int rollingForwardProduct {1};
    //     for (int i {0}; i < n; ++i) {
    //         out[i] = rollingForwardProduct * backwardProducts[i + 1];
    //         rollingForwardProduct *= nums[i];
    //     }

    //     return out;
    // }
};
// @lc code=end

