/*
 * @lc app=leetcode id=2709 lang=cpp
 *
 * [2709] Greatest Common Divisor Traversal
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class DSU {
public:
    vector<int> parent;
    vector<int> size;

    DSU(const int n) : parent(n), size(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    int get_parent(const int x) {
        if (x == parent[x]) return x;
        return parent[x] = get_parent(parent[x]);
    }

    void union_set(int u, int v) {
        int u_parent = get_parent(u);
        int v_parent = get_parent(v);
        
        if (u_parent == v_parent) return;
        if (size[u_parent] > size[v_parent]) swap(u_parent, v_parent); // v > u

        parent[u_parent] = v_parent;
        size[v_parent] += size[u_parent];
    }
};

class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        unordered_map<int, vector<int>> factorToIdx;

        DSU dsu(nums.size());
        for (int i {0}; i < nums.size(); ++i) factor(i, nums[i], factorToIdx, dsu);
    
        // for (const auto& entry : factorToIdx) {
        //     cout << entry.first << " : ";
        //     for (const int x : entry.second) cout << x << ' ';
        //     cout << '\n';
        // }

        // for (int i {0}; i < nums.size(); ++i) cout << dsu.parent[i] << ' ';
        // cout << '\n';
        for (int i {1}; i < nums.size(); ++i) {
            if (dsu.get_parent(i) != dsu.get_parent(i - 1)) return false;
        }
        return true;
    }
private:
    void factor(
        int i,
        int num,
        unordered_map<int, vector<int>>& factorToIdx,
        DSU& dsu
    ) {
        int z = 2;

        while (z * z <= num) {
            if (num % z == 0) {
                if (factorToIdx.count(z)) dsu.union_set(i, factorToIdx[z][0]);
                factorToIdx[z].push_back(i);
                num /= z;
            } else ++z;
        }
        if (num > 1) {
            if (factorToIdx.count(num)) dsu.union_set(i, factorToIdx[num][0]);
            factorToIdx[num].push_back(i);
        }
    }
};
// @lc code=end

