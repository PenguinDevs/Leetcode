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
        stack<int> heightsStack;
        int maxArea {0};

        heights.push_back(0); // Smallest height to trigger the area calculation.

        for (int i {0}; i < heights.size(); ++i) {
            const int h {heights[i]};
            while (!heightsStack.empty() && heights[heightsStack.top()] > h) {
                const int prevI = heightsStack.top();
                const int prevHeight = heights[prevI];
                heightsStack.pop();
                maxArea = max(
                    maxArea,
                    heightsStack.empty() ? i * prevHeight : (i - heightsStack.top() - 1) * prevHeight
                );
            }

            heightsStack.push(i);
        }

        return maxArea;
    }
};

// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         stack<pair<int, int>> heightsStack;
//         int maxArea {0};

//         heights.push_back(0); // Smallest height to trigger the area calculation.

//         for (int i {0}; i < heights.size(); ++i) {
//             const int h {heights[i]};
//             int leftMostI {i};

//             while (!heightsStack.empty() && heightsStack.top().second > h) {
//                 auto [prevI, prevHeight] = heightsStack.top();
//                 heightsStack.pop();
//                 maxArea = max(maxArea, (i - prevI) * prevHeight);
//                 leftMostI = prevI;
//             }

//             heightsStack.push({leftMostI, h});
//         }

//         return maxArea;
//     }
// };

// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         stack<pair<int, int>> heightsStack;
//         heightsStack.push({0, heights[0]});
        
//         int maxArea = {0};
//         heights.push_back(0); // Smallest height to trigger the area calculation.
//         for (int i {1}; i < heights.size(); ++i) {
//             if (!heightsStack.empty()) {
//                 auto [prevI, prevHeight] = heightsStack.top();

//                 if (prevHeight > heights[i]) {
//                     while (!heightsStack.empty() && prevHeight > heights[i]) {
//                         maxArea = max(maxArea, prevHeight * (i - prevI));
//                         // cout << prevHeight << " " << i << " " << prevI << endl;
//                         // cout << "new max area: " << maxArea << endl;
//                         heightsStack.pop();
                        
//                         if (!heightsStack.empty()) {
//                             auto topPair = heightsStack.top();
//                             if (topPair.second <= heights[i]) break;
//                             prevI = topPair.first;
//                             prevHeight = topPair.second;
//                         }
//                     }
//                     heightsStack.push({prevI, heights[i]});
//                 } else {
//                     heightsStack.push({i, heights[i]});
//                 }
//             } else {
//                 heightsStack.push({i, heights[i]});
//             }
//         }

//         return maxArea;
//     }
// };
// @lc code=end

