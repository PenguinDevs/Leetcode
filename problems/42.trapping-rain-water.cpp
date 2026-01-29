/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int l {0}, r = height.size() - 1;
        int lMax {height[l]}, rMax {height[r]};

        int water {0};
        while (l < r) {
            if (lMax < rMax) {
                ++l; // Can skip first index since water impossible
                lMax = max(lMax, height[l]);
                water += lMax - height[l];
            } else {
                --r; // Likewise
                rMax = max(rMax, height[r]);
                water += rMax - height[r];
            }
        }

        return water;
    }
};
// class Solution {
// public:
//     int trap(vector<int>& height) {
//         vector<int> waterHeights(height.size(), numeric_limits<int>::max());

//         fillWaterHeights(height, waterHeights);
//         reverse(height.begin(), height.end());
//         reverse(waterHeights.begin(), waterHeights.end());
//         fillWaterHeights(height, waterHeights);

//         // reverse(height.begin(), height.end());
//         // reverse(waterHeights.begin(), waterHeights.end());
//         // for (const int x : waterHeights) cout << x << " ";
//         // cout << endl;

//         return accumulate(waterHeights.begin(), waterHeights.end(), 0) - accumulate(height.begin(), height.end(), 0);
//     }
// private:
//     void fillWaterHeights(vector<int>& heights, vector<int>& waterHeights) {
//         int currWaterHeight {0};
//         for (int i {0}; i < heights.size(); ++i) {
//             currWaterHeight = max(currWaterHeight, heights[i]);
//             waterHeights[i] = min(waterHeights[i], currWaterHeight);
//             // cout << currWaterHeight << " ";
//         }
//         // cout << endl;
//     }
// };
// @lc code=end

