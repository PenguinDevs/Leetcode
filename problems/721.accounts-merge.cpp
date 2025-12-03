/*
 * @lc app=leetcode id=721 lang=cpp
 *
 * [721] Accounts Merge
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class DSU {
public:
    vector<int> parent;
    vector<int> rank;
    
    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        rank.resize(n, 1);
    }

    int findParent(int u) {
        int cur {u};
        while (cur != parent[cur]) {
            // Try to flatten set as we traverse.
            parent[cur] = parent[parent[cur]];
            cur = parent[cur];
        }
        
        return cur;
    }

    bool unionSets(int u, int v) {
        int uParent {findParent(u)};
        int vParent {findParent(v)};
        if (uParent == vParent) {
            return false;
        }

        if (rank[vParent] > rank[uParent]) swap(uParent, vParent);

        parent[vParent] = uParent;
        rank[uParent] += parent[vParent];

        return true;
    }

    void flatten() {
        for (int i {0}; i < parent.size(); ++i) {
            int iParent = findParent(i);

            int cur {i};
            while (cur != iParent) {
                int next = parent[cur];
                parent[cur] = iParent;
                cur = next;
            }
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> emailToId;
        unordered_map<string, string> emailToName;
        
        for (const auto& acc : accounts) {
            for (int i = 1; i < acc.size(); ++i) {
                if (emailToId.find(acc[i]) == emailToId.end()) {
                    emailToId[acc[i]] = emailToId.size();
                }
                emailToName[acc[i]] = acc[0];
            }
        }
        
        DSU dsu(emailToId.size());
        
        for (const auto& acc : accounts) {
            int firstEmailId = emailToId[acc[1]];
            for (int i = 2; i < acc.size(); ++i) {
                dsu.unionSets(firstEmailId, emailToId[acc[i]]);
            }
        }

        dsu.flatten();
        unordered_map<int, vector<string>> groups;
        for (const auto& [email, id] : emailToId) {
            int root = dsu.parent[id];
            groups[root].push_back(email);
        }

        vector<vector<string>> result;
        for (auto& [root, emails] : groups) {
            sort(emails.begin(), emails.end());
            emails.insert(emails.begin(), emailToName[emails[0]]);
            result.push_back(emails);
        }

        return result;
    }
};
// @lc code=end

