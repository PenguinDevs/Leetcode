/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

#include <bits/stdc++.h>
using namespace std;


// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        
        // NOTE: Not actually O(n^2), but is O(n) or rather, O(2n)
        // since the while loop work is done at most once for each num
        int longest = 0;
        for (int num : numSet) {
            if (!numSet.count(num - 1)) {
                int current = num;
                int streak = 1;
                while (numSet.count(current + 1)) {
                    current++;
                    streak++;
                }
                longest = max(longest, streak);
            }
        }

        return longest;
    }
};

// class DSU {
// public:
//     vector<int> parent;
//     vector<int> size;

//     DSU(int n) {
//         parent = vector<int>(n);
//         iota(parent.begin(), parent.end(), 0);
//         size = vector<int>(n, 1);
//     }

//     int find_set(int target) {
//         if (target == parent[target]) return target;
//         parent[target] = find_set(parent[target]);

//         return parent[target];
//     }

//     void union_set(int v, int u) {
//         int vParent = find_set(v);
//         int uParent = find_set(u);

//         if (size[vParent] < size[uParent]) swap(vParent, uParent);

//         parent[uParent] = parent[vParent];
//         size[vParent] += size[uParent];
//     }
// };

// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         if (nums.size() == 0) return 0;

//         DSU dsu(nums.size());
        
//         // Idx is 1-indexed, 0 is marked as does not exist
//         unordered_map<int, int> valToIdx;

//         for (int i {0}; i < nums.size(); ++i) {
//             const int val = nums[i];
//             if (valToIdx[val] != 0) continue;
//             valToIdx[val] = i + 1;

//             for (const int candidate : {val - 1, val + 1}) {
//                 if (valToIdx[candidate] == 0) continue;
//                 dsu.union_set(valToIdx[candidate] - 1, i);
//             }
//         }

//         return *max_element(dsu.size.begin(), dsu.size.end());
//     }
// };
// @lc code=end

