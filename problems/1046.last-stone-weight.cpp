/*
 * @lc app=leetcode id=1046 lang=cpp
 *
 * [1046] Last Stone Weight
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    // int lastStoneWeight(vector<int>& stones) {
    //     sort(stones.begin(), stones.end());

    //     while (stones.size() > 1) {
    //         int y = stones.back();
    //         stones.pop_back();
    //         int x = stones.back();
    //         stones.pop_back();


    //         if (x != y) {
    //             binaryInsert(stones, y - x);
    //         }
    //     }

    //     if (stones.size() > 0) {
    //         return stones[0];
    //     } else {
    //         return 0;
    //     }
    // }
    int lastStoneWeight(vector<int>& stones) {
        make_heap(stones.begin(), stones.end());

        while (stones.size() > 1) {
            pop_heap(stones.begin(), stones.end());
            int y = stones.back();
            stones.pop_back();

            pop_heap(stones.begin(), stones.end());
            int x = stones.back();
            stones.pop_back();

            if (x != y) {
                stones.push_back(y - x);
                push_heap(stones.begin(), stones.end());
            }
        }

        if (stones.size() > 0) {
            return stones[0];
        } else {
            return 0;
        }
    }
// private:
//     vector<int>& binaryInsert(vector<int>& sorted, int item) {
//         int low = 0;
//         int high = sorted.size();

//         int mid {0};
//         while (low < high) {
//             mid = (high + low) / 2;

//             if (item < sorted[mid]) {
//                 high = mid;
//             } else if (item > sorted[mid]) {
//                 low = mid + 1;
//             } else {
//                 break;
//             }
//         }

//         mid = (high + low) / 2;
//         sorted.insert(sorted.begin() + mid, item);
        
//         return sorted;
//     }
};
// @lc code=end

