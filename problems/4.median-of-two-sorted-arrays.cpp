/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

#include <bits/stdc++.h>
using namespace std;

// [1, 2, 11] [5, 6, 7, 8, 9, 10]

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);

        const int n1 = nums1.size();
        const int n2 = nums2.size();
        const int total = n1 + n2;
        const bool isOdd = (total % 2 == 1);
        const int half = (total + 1) / 2;

        int left = 0;
        int right = n1;
        while (left <= right) {
            const int i = left + (right - left) / 2;
            const int j = half - i;

            const int leftMax1 = (i == 0) ? INT_MIN : nums1[i - 1];
            const int rightMin1 = (i == n1) ? INT_MAX : nums1[i];
            const int leftMax2 = (j == 0) ? INT_MIN : nums2[j - 1];
            const int rightMin2 = (j == n2) ? INT_MAX : nums2[j];

            if (leftMax1 <= rightMin2 && leftMax2 <= rightMin1) {
                if (isOdd) return static_cast<double>(max(leftMax1, leftMax2));
                const double a = static_cast<double>(max(leftMax1, leftMax2));
                const double b = static_cast<double>(min(rightMin1, rightMin2));
                return (a + b) / 2.0;
            } else if (leftMax1 > rightMin2) {
                right = i - 1;
            } else {
                left = i + 1;
            }
        }

        return -1.0;
    }
};
// @lc code=end

