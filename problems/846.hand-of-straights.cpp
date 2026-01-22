/*
 * @lc app=leetcode id=846 lang=cpp
 *
 * [846] Hand of Straights
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
// class Solution {
// public:
//     bool isNStraightHand(vector<int>& hand, int groupSize) {
//         if (hand.size() % groupSize != 0) return false;

//         map<int, int> freq;
//         for (const int h : hand) ++freq[h];

//         for (const int origH : hand) {
//             // if (!freq[h]) continue;
//             int h = origH;

//             while (freq[h - 1]) {
//                 --h;
//             }

//             while (h <= origH) {
//                 while (freq[h]) { // In case of duplicate
//                     bool isHand {true};
//                     for (int hNext {h}; hNext < h + groupSize; ++hNext) {
//                         if (!freq[hNext]) {
//                             isHand = false;
//                             break;
//                         };
//                     }
        
//                     if (!isHand) { break; };
        
//                     for (int hNext {h}; hNext < h + groupSize; ++hNext) {
//                         --freq[hNext];
//                     }
//                 }

//                 ++h;
//             }
//         }

//         return !any_of(freq.begin(), freq.end(), [](pair<const int, int> entry) {
//             return entry.second;
//         });
//     }
// };
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        map<int, int> freq;
        for (const int h : hand) ++freq[h];

        for (const auto& [start, count] : freq) {
            while (count > 0) {
                for (int i = 0; i < groupSize; ++i) {
                    if (--freq[start + i] < 0) return false;
                }
            }
        }
        return true;
    }
};
// struct Pointer {
//     int samePartIdx;
//     int handIdx;
// };

// class Solution {
// public:
//     bool isNStraightHand(vector<int>& hand, int groupSize) {
//         if (hand.size() <= 1) return true;

//         sort(hand.begin(), hand.end());

//         vector<int> samePartition;
//         int lastNo {-1};
//         for (int i {0}; i < hand.size(); ++i) {
//             if (hand[i] != lastNo) {
//                 samePartition.push_back(i + 1);
//                 lastNo = hand[i];
//             } else {
//                 samePartition.back() = i + 1;
//             }
//         }

//         for (int i {0}; i < samePartition.size(); ++i) {
//             cout << i << ":" << samePartition[i] << " ";
//         }
//         cout << endl;

//         vector<bool> marked(hand.size());
    
//         vector<Pointer> pointers(groupSize);
//         for (int i {0}; i < groupSize; ++i) pointers[i] = {i, i > 0 ? samePartition[i - 1] : 0};
    
//         while (pointers.back().handIdx < hand.size()) {
//             for (const Pointer& p : pointers) cout << "p" << p.handIdx << " ";
//             cout << endl;

//             bool isHand {true};
//             for (int i {0}; i < pointers.size() - 1; ++i) {
//                 if (hand[pointers[i].handIdx] + 1 != hand[pointers[i + 1].handIdx]) {
//                     isHand = false;
//                 } else if (marked[pointers[i].handIdx]) {
//                     isHand = false;
//                 }
//             }

//             if (isHand) {
//                 for (int i {0}; i < pointers.size(); ++i) {
//                     marked[pointers[i].handIdx] = true;
//                     if (pointers[i].samePartIdx > 0) ++samePartition[pointers[i].samePartIdx - 1];
//                 }
//             }

//             for (int i = pointers.size() - 1; i >= 0; --i) {
//                 Pointer& p = pointers[i];
//                 if (i == pointers.size() - 1 && p.samePartIdx == samePartition.size() - 1) {
//                     // Right pointer and on the last number type
//                     ++p.handIdx;
//                 } else if (i + 1 < pointers.size() && p.samePartIdx + 1 == pointers[i + 1].samePartIdx) {
//                     // Other pointers where the directly right partition is occupied
//                     ++p.handIdx;
//                 } else {
//                     p.handIdx = samePartition[p.samePartIdx];
//                     cout << pointers.back().handIdx << " " << pointers.back().samePartIdx << endl;
//                     ++p.samePartIdx;
//                 }
//             }

//         }

//         for (const int m : marked) cout << m << " ";

//         return !any_of(marked.begin(), marked.end(), [](const bool m) { return !m; });
//     }
// };
// @lc code=end

