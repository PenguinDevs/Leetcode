/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l {0};
        int r = height.size() - 1;

        int largestArea {(r - l) * min(height[l], height[r])};
        while (l < r) {
            if (height[l] < height[r]) {
                ++l;
            } else {
                --r;
            }

            largestArea = max(largestArea, (r - l) * min(height[l], height[r]));
        }

        return largestArea;
    }

    // int maxArea(vector<int>& height) {
    //     vector<pair<int, int>> rects(height.size());
    //     for (int i {0}; i < height.size(); ++i) {
    //         rects[i] = {height[i], i};
    //     }
    //     sort(rects.begin(), rects.end(), greater<pair<int, int>>());

    //     int l {rects[0].second};
    //     int r {rects[1].second};
    //     if (l > r) swap(l, r);
    //     int largestArea {(r - l) * min(height[l], height[r])};

    //     for (const auto& [h, i] : rects) {
    //         if (i < l) {
    //             l = i;
    //         } else if (i > r) {
    //             r = i;
    //         } else continue;

    //         largestArea = max(largestArea, (r - l) * min(height[l], height[r]));
    //         // cout << l << " " << r << " " << min(height[l], height[r]) << endl;
    //     }

    //     return largestArea;
    // }
};
// @lc code=end

