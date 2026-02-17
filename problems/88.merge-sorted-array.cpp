/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums1Copy = nums1;
        nums1Copy.push_back(numeric_limits<int>::max());
        nums2.push_back(numeric_limits<int>::max());
        auto nums1P = nums1Copy.begin();
        auto nums2P = nums2.begin();

        int nums1Idx {0};
        int nums2Idx {0};
        while (nums1Idx < m || nums2Idx < n) {
            if (nums1Idx == m) {
                nums1[nums2Idx + nums1Idx] = *nums2P;
                ++nums2P;
            } else if (nums2Idx == n) {
                nums1[nums2Idx + nums1Idx] = *nums1P;
                ++nums1P;
            } else {
                if (*nums1P < *nums2P) {
                    nums1[nums2Idx + nums1Idx] = *nums1P;
                    ++nums1P;
                } else {
                    nums1[nums2Idx + nums1Idx] = *nums2P;
                    ++nums2P;
                }
            }

            nums1Idx = nums1P - nums1Copy.begin();
            nums2Idx = nums2P - nums2.begin();
        };
    }
};
// @lc code=end

