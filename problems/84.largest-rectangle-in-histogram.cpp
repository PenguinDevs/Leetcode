/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> heights_stack;
        int maxArea {0};

        heights.push_back(0); // Smallest height to trigger the area calculation.

        for (int i {0}; i < heights.size(); ++i) {
            const int h {heights[i]};
            int leftMostI {i};

            while (!heights_stack.empty() && heights_stack.top().second > h) {
                auto [prevI, prevHeight] = heights_stack.top();
                heights_stack.pop();
                maxArea = max(maxArea, (i - prevI) * prevHeight);
                leftMostI = prevI;
            }

            heights_stack.push({leftMostI, h});
        }

        return maxArea;
    }
};

// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         stack<pair<int, int>> heights_stack;
//         heights_stack.push({0, heights[0]});
        
//         int maxArea = {0};
//         heights.push_back(0); // Smallest height to trigger the area calculation.
//         for (int i {1}; i < heights.size(); ++i) {
//             if (!heights_stack.empty()) {
//                 auto [prevI, prevHeight] = heights_stack.top();

//                 if (prevHeight > heights[i]) {
//                     while (!heights_stack.empty() && prevHeight > heights[i]) {
//                         maxArea = max(maxArea, prevHeight * (i - prevI));
//                         // cout << prevHeight << " " << i << " " << prevI << endl;
//                         // cout << "new max area: " << maxArea << endl;
//                         heights_stack.pop();
                        
//                         if (!heights_stack.empty()) {
//                             auto topPair = heights_stack.top();
//                             if (topPair.second <= heights[i]) break;
//                             prevI = topPair.first;
//                             prevHeight = topPair.second;
//                         }
//                     }
//                     heights_stack.push({prevI, heights[i]});
//                 } else {
//                     heights_stack.push({i, heights[i]});
//                 }
//             } else {
//                 heights_stack.push({i, heights[i]});
//             }
//         }

//         return maxArea;
//     }
// };
// @lc code=end

