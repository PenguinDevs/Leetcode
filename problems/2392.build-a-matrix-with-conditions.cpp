/*
 * @lc app=leetcode id=2392 lang=cpp
 *
 * [2392] Build a Matrix With Conditions
 * 
 * NOTE: Another problem solved by topsort, just consider top sorting!!!
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    class HasCycleException : public exception {};

    vector<vector<int>> buildMatrix(const int k, const vector<vector<int>>& rowConditions, const vector<vector<int>>& colConditions) {
        vector<vector<int>> rowAdjacency = getAdjacencyList(k, rowConditions);
        vector<int> rowIndegree = getIndegree(rowAdjacency);

        vector<vector<int>> colAdjacency = getAdjacencyList(k, colConditions);
        vector<int> colIndegree = getIndegree(colAdjacency);
        
        vector<int> rowTopSort, colTopSort;
        try {
            rowTopSort = topSort(rowIndegree, rowAdjacency);
            colTopSort = topSort(colIndegree, colAdjacency);
        } catch (const HasCycleException& err) {
            return {};
        }

        vector<int> colToIdx(colTopSort.size());
        for (int i {0}; i < colTopSort.size(); ++i) {
            colToIdx[colTopSort[i]] = i;
        }

        vector<vector<int>> matrix(k, vector<int>(k));

        // for (const int n : rowTopSort) cout << n << " ";
        // cout << endl;

        for (int i {0}; i < rowTopSort.size(); ++i) {
            const int n = rowTopSort[i];
            const int j = colToIdx[n];

            // cout << i << " " << j << " " << k << endl;

            matrix[i][j] = n + 1; // Since it is 0-indexed
        }

        return matrix;
    }
private:
    vector<vector<int>> getAdjacencyList(const int k, const vector<vector<int>>& conditions) {
        vector<vector<int>> adjacencyList(k);
        for (int i {0}; i < conditions.size(); ++i) {
            const int u = conditions[i][0], v = conditions[i][1]; // u > v
            adjacencyList[u - 1].push_back(v - 1);
        }

        return adjacencyList;
    }

    vector<int> getIndegree(const vector<vector<int>>& adjacencyList) {
        vector<int> indegree(adjacencyList.size());

        for (int i {0}; i < adjacencyList.size(); ++i) {
            for (const int v : adjacencyList[i]) {
                ++indegree[v];
            }
        }

        return indegree;
    }

    vector<int> get0Indegree(const vector<int>& indegree) {
        vector<int> out;

        for (int i {0}; i < indegree.size(); ++i) {
            if (indegree[i] == 0) out.push_back(i);
        }

        return out;
    }

    vector<int> topSort(vector<int> indegree, vector<vector<int>>& adjacencyList) {
        queue<int> bfs;
        for (const int u : get0Indegree(indegree)) bfs.push(u);

        vector<int> topSort;
        while (!bfs.empty()) {
            const int u = bfs.front();
            bfs.pop();
            topSort.push_back(u);

            for (const int v : adjacencyList[u]) {
                --indegree[v];
                if (indegree[v] == 0) bfs.push(v);
            }
        }

        if (topSort.size() < indegree.size()) {
            throw HasCycleException();
        }

        return topSort;
    }
};

// class Solution {
// public:
//     vector<vector<int>> buildMatrix(const int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
//         vector<int> rows = getSequence(k, rowConditions);
//         vector<int> cols = getSequence(k, colConditions);
//         vector<int> numToCol(k);
//         for (int i {0}; i < cols.size(); ++i) {
//             numToCol[cols[i]] = i;
//         }

//         vector<vector<int>> matrix;
//         for (int i {0}; i < rows.size(); ++i) {
//             const int j = numToCol[rows[i]];
//             matrix[i][j] = rows[i] + 1; // Since 0-indexed
//         }

//         return matrix;
//     }
// private:
//     vector<int> getSequence(const int k, vector<vector<int>>& conditions) {
//         vector<int> adjacencyVertex(k, -1);
//         for (int i {0}; i < k; ++i) {
//             const int u = conditions[i][0], v = conditions[i][1];
//             adjacencyVertex[u - 1] = v - 1;
//         }

//         vector<bool> traversable(k);
//         for (int i {0}; i < k; ++i) {
//             traversable[i] = adjacencyVertex[i] != -1;
//         }
        
//         int curIdx{-1};
//         for (int i {0}; i < k; ++i) {
//             if (!traversable[i]) {
//                 curIdx = i;
//                 break;
//             }
//         }
        
//         vector<int> out;
//         out.reserve(k);
//         while (curIdx != -1) {
//             out.push_back(traversable[curIdx]);
//             curIdx = traversable[curIdx];
//         }

//         return out;
//     }
// };
// @lc code=end

