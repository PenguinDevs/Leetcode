/*
 * @lc app=leetcode id=997 lang=cpp
 *
 * [997] Find the Town Judge
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> adjacencyList(n + 1);
        for (const auto& edge : trust) {
            const int trusting = edge[0], trusted = edge[1];

            ++adjacencyList[trusted];
            adjacencyList[trusting] = numeric_limits<int>::min();
        }

        for (int i {1}; i < adjacencyList.size(); ++i) {
            if (adjacencyList[i] == n - 1) {
                return i;
            }
        }

        return -1;
    }
};

// class Solution {
// public:
//     int findJudge(int n, vector<vector<int>>& trust) {
//         vector<vector<int>> adjacencyList(1001);
//         vector<bool> trustingList(1001);

//         for (const auto& edge : trust) {
//             const int trusting = edge[0], trusted = edge[1];

//             adjacencyList[trusted].push_back(trusting);
//             trustingList[trusting] = true;
//         }

//         for (int i {1}; i < adjacencyList.size(); ++i) {
//             if (adjacencyList[i].size() == n - 1) {
//                 if (trustingList[i]) return -1;
//                 return i;
//             }
//         }

//         return -1;
//     }
// };
// @lc code=end

