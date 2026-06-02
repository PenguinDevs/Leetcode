/*
 * @lc app=leetcode id=752 lang=cpp
 *
 * [752] Open the Lock
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<pair<int, string>> q;
        q.push({0, "0000"});
        
        vector<bool> visited(10000);
        visited[0000] = true;
        for (const string& deadend : deadends) {
            if (deadend == "0000") return -1;
            visited[stoi(deadend)] = true;
        }

        while (!q.empty()) {
            // cout << 3;
            const auto [step, code] = q.front();
            q.pop();
            // cout << 4;

            // cout << code << " " << target << " \n";
            if (code == target) return step;
            // cout << 2;

            for (int pos {0}; pos < 4; ++pos) {
                for (int diff : {-1, 1}) {
                    string newCode = code;
                    // cout << (newCode[pos] - '0') + '0' << " " << (newCode[pos] - '0' + diff + 10) % 10 << '\n';
                    newCode[pos] = static_cast<char>((newCode[pos] - '0' + diff + 10) % 10 + '0');
                    if (visited[stoi(newCode)]) continue;
                    visited[stoi(newCode)] = true;
                    // cout << "yuh\n";
                    q.push({step + 1, newCode});
                }
            }
        }

        return -1;
    }
};
// @lc code=end

