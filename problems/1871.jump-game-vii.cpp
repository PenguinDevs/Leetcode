/*
 * @lc app=leetcode id=1871 lang=cpp
 *
 * [1871] Jump Game VII
 * 
 * // NOTE: See two pointer solution
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        const int n = s.size();
        if (s[n - 1] == '1') return false;

        vector<bool> dp(s.size());
        dp[0] = true;

        int cur {0};
        for (int i {1}; i < n; ++i) {
            if (i - minJump >= 0 && dp[i - minJump]) {
                ++cur;
            }
            // cout << (s[i] == '0') << " " << cur << endl;
            dp[i] = (s[i] == '0') && cur > 0;
            if (i - maxJump >= 0 && dp[i - maxJump]) {
                --cur;
            }
        }

        // for (int i {0}; i < n; ++i) cout << dp[i];

        return dp[n - 1];
    }

    // bool canReach(string s, int minJump, int maxJump) {
    //     const int n = s.size();

    //     vector<bool> visited(n);
    //     queue<int> bfsQ;
    //     visited[0] = true;
    //     bfsQ.push(0);

    //     while (!bfsQ.empty()) {
    //         int i = bfsQ.front();
    //         bfsQ.pop();

    //         for (int j {i + minJump}; j <= min(i + maxJump, n - 1); ++j) {
    //             if (visited[j]) continue;
    //             if (s[j] != '0') continue;
    //             visited[j] = true;
    //             bfsQ.push(j);
    //         }
    //     }

    //     // for (int i {0}; i < n; ++i) cout << visited[i];

    //     return visited[n - 1];
    // }

    // bool canReach(string s, int minJump, int maxJump) {
    //     const int n = s.length();

    //     vector<int> dp(n);
    //     dp[0] = 1;

    //     for (int i {0}; i < n; ++i) {
    //         for (int j {i + minJump}; j <= min(i + maxJump, n - 1); ++j) {
    //             // cout << "jumping from " << i << " to " << j << endl;
    //             if (s[j] != '0') continue;
    //             dp[j] += dp[i];
    //         }
    //     }

    //     return dp[n - 1] > 0;
    // }
};
// @lc code=end

