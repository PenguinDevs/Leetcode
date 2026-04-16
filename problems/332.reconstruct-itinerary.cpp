/*
 * @lc app=leetcode id=332 lang=cpp
 *
 * [332] Reconstruct Itinerary
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    map<string, multiset<string>> targets;
    vector<string> path;

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // targets.clear();
        // path.clear();

        for (const auto& ticket : tickets)
            targets[ticket[0]].insert(ticket[1]);
        dfs("JFK");
        return vector<string>(path.rbegin(), path.rend());
    }

    void dfs(string node) {
        while (targets[node].size()) {
            string next = *targets[node].begin();
            targets[node].erase(targets[node].begin());
            dfs(next);
        }
    path.push_back(node);
}
};
// @lc code=end

