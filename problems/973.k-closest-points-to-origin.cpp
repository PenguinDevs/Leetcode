/*
 * @lc app=leetcode id=973 lang=cpp
 *
 * [973] K Closest Points to Origin
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
// private:
//     bool posComparator(const vector<int>& pA, const vector<int>& pB) {
//         return pA[0] * pA[0] + pA[1] * pA[1] < pB[0] * pB[0] + pB[1] * pB[1];
//     }
//     int partition(vector<vector<int>>& points, int l, int r) {
//         vector<int> pivot = points[r - 1];
//         int partitionIndex {l};
        
//         for (int i {l}; i < r; ++i) {
//             if (posComparator(points[i], pivot)) {
//                 // cout << "swap" << endl;
//                 swap(points[i], points[partitionIndex]);
//                 ++partitionIndex;
//             }
//         }
//         swap(points[partitionIndex], points[r - 1]);

//         return partitionIndex;
//     }
//     void quickSelect(vector<vector<int>>& points, int k, int l, int r) {
//         // // cout << l << " " << r << endl;
//         // if (r <= l) return;
        
//         // int mid {partition(points, l, r)};
//         // // cout << mid << endl;
//         // if (mid == k) {
//         //     return;
//         // } else if (mid > k) {
//         //     return quickSelect(points, k, l, mid);
//         // } else if (mid < k) {
//         //     return quickSelect(points, k, mid + 1, r);
//         // }

//         while (r > l) {
//             int mid(partition(points, l, r));
//             if (mid == k) {
//                 return;
//             } else if (mid > k) {
//                 r = mid;
//                 return quickSelect(points, k, l, mid);
//             } else if (mid < k) {
//                 l = mid + 1;
//                 return quickSelect(points, k, mid + 1, r);
//             }
//         }
//     }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        static const auto posComparator = [](const vector<int>& pA, const vector<int>& pB) {
            return pow(pA[0], 2) + pow(pA[1], 2) < pow(pB[0], 2) + pow(pB[1], 2);
        };
        nth_element(points.begin(), points.begin() + k, points.end(), posComparator); // Basically the solution here

        // Actually runs in O(n) average case
        // quickSelect(points, k, 0, points.size());

        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
    // vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    //     vector<vector<int>> heapq;

    //     static const auto posComparator = [](const vector<int>& pA, const vector<int>& pB) {
    //         return pow(pA[0], 2) + pow(pA[1], 2) < pow(pB[0], 2) + pow(pB[1], 2);
    //     };

    //     for (int i {0}; i < points.size(); ++i) {
    //         heapq.push_back(points[i]);
    //         push_heap(heapq.begin(), heapq.end(), posComparator);

    //         if (heapq.size() > k) {
    //             pop_heap(heapq.begin(), heapq.end(), posComparator);
    //             heapq.pop_back();
    //         }
    //     }

    //     return heapq;
    // }
    // vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    //     static const auto posComparator = [](const vector<int>& pA, const vector<int>& pB) {
    //         return pow(pA[0], 2) + pow(pA[1], 2) > pow(pB[0], 2) + pow(pB[1], 2);
    //     };
        
    //     make_heap(points.begin(), points.end(), posComparator);

    //     vector<vector<int>> output;
    //     for (int i {0}; i < k; ++i) {
    //         pop_heap(points.begin(), points.end(), posComparator);
    //         output.push_back(points.back());
    //         points.pop_back();
    //     }

    //     return output;
    // }
    // vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    //     vector<vector<int>> heapq;

    //     static const auto posComparator = [](const vector<int>& pA, const vector<int>& pB) {
    //         return pow(pA[0], 2) + pow(pA[1], 2) < pow(pB[0], 2) + pow(pB[1], 2);
    //     };

    //     for (int i {0}; i < points.size(); ++i) {
    //         heapq.push_back(points[i]);
    //         push_heap(heapq.begin(), heapq.end(), posComparator);
    //     }

    //     sort_heap(heapq.begin(), heapq.end(), posComparator);
    //     for (int i = points.size() - 1; i >= k; --i) {
    //         heapq.pop_back();
    //     }

    //     return heapq;
    // }
};
// @lc code=end

