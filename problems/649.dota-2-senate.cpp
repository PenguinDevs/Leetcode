/*
 * @lc app=leetcode id=649 lang=cpp
 *
 * [649] Dota2 Senate
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
struct Node {
    bool radiant;
    Node* prev;
    Node* next;
    Node(bool r, Node* p = nullptr, Node* n = nullptr) : radiant(r), prev(p), next(n) {}
};

class Solution {
public:
    string predictPartyVictory(string& senate) {
        int n = senate.size();
        queue<int> r, d;
        for (int i = 0; i < n; ++i) {
            if (senate[i] == 'R') r.push(i);
            else d.push(i);
        }

        while (!r.empty() && !d.empty()) {
            int ri = r.front(); r.pop();
            int di = d.front(); d.pop();
            if (ri < di) r.push(ri + n);
            else d.push(di + n);
        }

        return r.empty() ? "Dire" : "Radiant";
    }
};
// @lc code=end

