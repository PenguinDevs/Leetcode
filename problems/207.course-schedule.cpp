/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjacencyList(numCourses);
        vector<int> indegree(numCourses);
        for (const auto& prereq : prerequisites) {
            const int preUnit = prereq[0], unit = prereq[1];
            adjacencyList[preUnit].push_back(unit);
            ++indegree[unit];
        }

        queue<int> q;
        for (int node {0}; node < numCourses; ++node) {
            if (indegree[node] == 0) q.push(node);
        }

        while (!q.empty()) {
            const int curr = q.front();
            q.pop();
            for (const int neighbour : adjacencyList[curr]) {
                --indegree[neighbour];
                if (indegree[neighbour] == 0) q.push(neighbour);
            }
        }

        for (int node {0}; node < numCourses; ++node) {
            if (indegree[node] != 0) return false;
        }

        return true;
    }
};
// @lc code=end

