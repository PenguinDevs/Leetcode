/*
 * @lc app=leetcode id=978 lang=cpp
 *
 * [978] Longest Turbulent Subarray
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int longestTurbulence {0};
        int smallerCount {0};
        int largerCount {0};

        for (int i {0}; i < arr.size() - 1; ++i) {
            smallerCount = arr[i] < arr[i + 1] ? smallerCount + 1 : 0;
            largerCount = arr[i] > arr[i + 1] ? largerCount + 1 : 0;
            
            longestTurbulence = max(longestTurbulence, max(smallerCount, largerCount));
            swap(smallerCount, largerCount);
        }

        return longestTurbulence + 1;
    }
};
// class Solution {
// public:
//     int maxTurbulenceSize(vector<int>& arr) {
//         if (arr.size() == 1) return 1;

//         int longestTurbulence {0};
//         int turbulence {0};
//         int wasGreater {!(arr[0] < arr[1])};
//         for (int i {0}; i < arr.size(); ++i) {
//             const int x {arr[i]};
//             const int prevVal {i > 0 ? arr[i - 1] : -1};
//             // cout << wasGreater << " " << prevVal << " " << x << '\n';
//             if (i == 0 || (!wasGreater && prevVal > x) || (wasGreater && prevVal < x)) {
//                 longestTurbulence = max(longestTurbulence, ++turbulence);
//                 wasGreater = !wasGreater;
//             } else {
//                 // cout << "turbulence ended at " << x << " with " << turbulence << '\n';
//                 turbulence = 1;
//                 if ((arr[i - 1] < arr[i] && arr[i] > arr[i + 1]) || (arr[i - 1] > arr[i] && arr[i] < arr[i + 1])) ++turbulence;
//                 wasGreater = i < arr.size() - 1 ? x < arr[i + 1] : false;
//             }
//         }

//         return longestTurbulence;
//     }
// };
// @lc code=end

