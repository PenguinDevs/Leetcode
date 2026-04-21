/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> roots(numCourses, true);
        vector<vector<int>> adjacency(numCourses);

        for (const auto& pair : prerequisites) {
            adjacency[pair[1]].push_back(pair[0]);
            roots[pair[0]] = false;
        }

        vector<int>visited(numCourses);
        vector<int> topSorted;
        for (int i {0}; i < numCourses; ++i) {
            if (!roots[i]) continue;
            if (!topsortDfs(adjacency, visited, topSorted, i)) return {};
        }

        for (int i {0}; i < numCourses; ++i) {
            if (visited[i] == 0) return {};
        }

        reverse(topSorted.begin(), topSorted.end());
        return topSorted;
    }
private:
    bool topsortDfs(vector<vector<int>>& adjacency, vector<int>& visited, vector<int>& topSorted, int curr) {
        visited[curr] = 1;
        for (const int neighbour : adjacency[curr]) {
            if (visited[neighbour] == 1) return false;
            if (visited[neighbour] == 2) continue;
            if (!topsortDfs(adjacency, visited, topSorted, neighbour)) return false;
        }
        visited[curr] = 2;
        
        topSorted.push_back(curr);
        return true;
    }
};
// @lc code=end

