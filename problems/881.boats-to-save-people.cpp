/*
 * @lc app=leetcode id=881 lang=cpp
 *
 * [881] Boats to Save People
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());

        int boats {0};
        int l {0};
        int r = people.size() - 1;
        while (l <= r) {
            if (r - l == 0) {
                boats += 1;
                break;
            }

            const int heaviest = people[r];
            const int lightest = people[l];

            r -= 1;
            if (heaviest + lightest <= limit) {
                l += 1;
            }

            boats += 1;
        }

        return boats;
    }
};
// class Solution {
// public:
//     int numRescueBoats(vector<int>& people, int limit) {
//         sort(people.begin(), people.end());
//         deque<int> weights;
//         for (const int x : people) weights.push_back(x);

//         int boats {0};
//         while (!weights.empty()) {
//             if (weights.size() == 1) {
//                 boats += 1;
//                 break;
//             }

//             const int heaviest = weights.back();
//             const int lightest = weights.front();

//             weights.pop_back();
//             if (heaviest + lightest <= limit) {
//                 weights.pop_front();
//             }

//             boats += 1;
//         }

//         return boats;
//     }
// };
// @lc code=end

