/*
 * @lc app=leetcode id=658 lang=cpp
 *
 * [658] Find K Closest Elements
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        deque<int> kClosest;
        
        int l = lower_bound(arr.begin(), arr.end(), x) - arr.begin() - 1;
        int r = {l + 1};
        
        while (kClosest.size() < k) {
            if (l >= 0 && (r >= arr.size() || abs(arr[l] - x) <= abs(arr[r] - x))) {
                kClosest.push_front(arr[l]);
                --l;
            } else if (r < arr.size()) {
                kClosest.push_back(arr[r]);
                ++r;
            }
        }

        vector<int> out;
        out.reserve(kClosest.size());
        for (const auto x : kClosest) out.push_back(x);

        return out;
    }
};
// @lc code=end

