/*
 * @lc app=leetcode id=763 lang=cpp
 *
 * [763] Partition Labels
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> endpoints(26);
        for (int i {0}; i < s.size(); ++i) endpoints[s[i] - 'a'] = i;

        vector<int> partitionSizes;
        int lastPartitionMark {-1};
        int maxPartitionEndpoint {0};

        vector<int> maxEndpointToReach();
        for (int i {0}; i < s.size(); ++i) {
            const char c = s[i];
            maxPartitionEndpoint = max(maxPartitionEndpoint, endpoints[c - 'a']);

            if (i == maxPartitionEndpoint) {
                partitionSizes.push_back(i - lastPartitionMark);
                lastPartitionMark = i;
            }
        }

        return partitionSizes;
    }
};

// class Solution {
// public:
//     vector<int> partitionLabels(string s) {
//         vector<int> charCount(26);
//         for (const char c : s) {
//             ++charCount[c - 'a'];
//         }

//         vector<int> partitionSizes;
//         int lastPartitionMark {-1};

//         vector<int> charTally(26);
//         for (int i {0}; i < s.size(); ++i) {
//             const char c = s[i];
//             const int cI = c - 'a';
//             if (charTally[cI] == 0) {
//                 charTally[cI] = charCount[cI];
//             }
//             --charTally[cI];

//             if (all_of(charTally.begin(), charTally.end(), [](int v) { return v == 0; })) {
//                 partitionSizes.push_back(i - lastPartitionMark);
//                 lastPartitionMark = i;
//             }
//         }

//         return partitionSizes;
//     }
// };
// @lc code=end

