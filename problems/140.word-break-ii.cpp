/*
 * @lc app=leetcode id=140 lang=cpp
 *
 * [140] Word Break II
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<vector<int>> dp(s.size() + 1);
        dp[0].push_back(-1);

        for (int i {0}; i <= s.size(); ++i) {
            for (int j {0}; j < wordDict.size(); ++j) {
                const string& word = wordDict[j];
                const int wordLength = word.size();
                if (i - wordLength < 0) continue;
                if (s.substr(i - wordLength, wordLength) != word) continue;
                if (!dp[i - wordLength].empty()) dp[i].push_back(j);
            }
        }

        vector<string> out;
        buildOut(s, wordDict, out, dp, s.size());

        return out;
    }
private:
    void buildOut(
        string s,
        vector<string>& wordDict,
        vector<string>& out,
        vector<vector<int>>& dp,
        const int i,
        string currentSol = ""
    ) {
        if (i < 0) return;
        if (i == 0) return out.push_back(currentSol.substr(0, currentSol.size() - 1));
        
        for (const int wordIdx : dp[i]) {
            const string newSol = wordDict[wordIdx] + " " + currentSol;
            const int neighbour = i - static_cast<int>(wordDict[wordIdx].size());
            buildOut(s, wordDict, out, dp, neighbour, newSol);
        }
    }
};
// @lc code=end

