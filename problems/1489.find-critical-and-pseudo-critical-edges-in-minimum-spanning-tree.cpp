/*
 * @lc app=leetcode id=1489 lang=cpp
 *
 * [1489] Find Critical and Pseudo-Critical Edges in Minimum Spanning Tree
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class DSU {
    vector<int> parent;
    vector<int> size;

public:
    DSU(const int n) : parent(n), size(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    int get_parent(const int x) {
        if (x == parent[x]) return x;
        return parent[x] = get_parent(parent[x]);
    }

    void union_set(int u, int v) {
        if (u == v) return;
        if (size[u] > size[v]) swap(u, v); // v > u

        const int u_parent = get_parent(u);
        const int v_parent = get_parent(v);

        parent[u_parent] = v_parent;
        size[v_parent] += size[u_parent];
    }

    bool is_mutual(const int u, const int v) {
        return get_parent(u) == get_parent(v);
    }
};

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(const int n, vector<vector<int>>& edges) {
        for (int edgeIdx {0}; edgeIdx < edges.size(); ++edgeIdx)
            edges[edgeIdx].push_back(edgeIdx);

        sort(
            edges.begin(),
            edges.end(),
            [](vector<int>& x, vector<int>& y) {
                return x[2] < y[2];
            }
        );

        vector<int> critical;
        vector<int> pseudoCritical;

        const int minCost = primsMST(n, edges, -1, false);
        for (const vector<int>& edge : edges) {
        // for (int edgeIdx {0}; edgeIdx < edges.size(); ++edgeIdx) {
            const int edgeIdx {edge[3]};
            // cout << edgeIdx << " " << primsMST(n, edges, edgeIdx, true) << '\n';
            if (minCost < primsMST(n, edges, edgeIdx, false)) {
                critical.push_back(edgeIdx);
            } else if (minCost == primsMST(n, edges, edgeIdx, true)) {
                pseudoCritical.push_back(edgeIdx);
            }
        }

        vector<vector<int>> out(2);
        out[0] = critical;
        out[1] = pseudoCritical;

        return out;
    }
private:
    int primsMST(
        const int n,
        const vector<vector<int>>& edges,
        const int edgeIdxSubject,
        const bool include
    ) {
        DSU dsu(n);
        int cost {0};

        if (include) {
            for (const vector<int>& edge : edges) {
                if (edgeIdxSubject != edge[3]) continue;
                const int u = edge[0], v = edge[1], w = edge[2];
                dsu.union_set(u, v);
                cost += w;
                break;
            }
        }

        for (const vector<int>& edge : edges) {
        // for (int edgeIdx {0}; edgeIdx < edges.size(); ++edgeIdx) {
            if (edgeIdxSubject == edge[3]) continue;
            // const vector<int>& edge = edges[edgeIdx];
            const int u = edge[0], v = edge[1], w = edge[2];
            // if (excludeEdgeIdx == u || excludeEdgeIdx == v) continue;
            if (dsu.is_mutual(u, v)) continue;

            dsu.union_set(u, v);
            cost += w;
        }

        const int singleGroupIdx = dsu.get_parent(0);
        for (int i {0}; i < n; ++i) {
            if (singleGroupIdx != dsu.get_parent(i)) {
                return numeric_limits<int>::max();
            }
        }

        return cost;
    }
};
// @lc code=end

