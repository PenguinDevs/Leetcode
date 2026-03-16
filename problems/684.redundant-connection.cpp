/*
 * @lc app=leetcode id=684 lang=cpp
 *
 * [684] Redundant Connection
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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        const int n = edges.size();
        
        DSU dsu(n + 1);

        int lastRedundantEdge {-1};
        for (int i {0}; i < n; ++i) {
            vector<int>& edge = edges[i];
            const int u = edge[0], v = edge[1];
            if (dsu.is_mutual(u, v)) {
                lastRedundantEdge = i;
            } else {
                dsu.union_set(u, v);
            }
        }

        return edges[lastRedundantEdge];
    }
};
// @lc code=end

