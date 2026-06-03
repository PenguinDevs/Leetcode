/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1);
        dp[0] = true;

        for (int i {0}; i <= s.size(); ++i) {
            for (const string& word : wordDict) {
                const int wordLength = word.size();
                if (i - wordLength < 0) continue;
                if (s.substr(i - wordLength, wordLength) != word) continue;
                dp[i] = dp[i - wordLength] || dp[i];
            }
        }

        return dp[s.size()];
    }
};
// struct TrieNode {
//     char c;
//     bool isRoot {false};
//     TrieNode* children[26];
// };

// class Solution {
// public:
//     bool wordBreak(string s, vector<string>& wordDict) {
//         TrieNode* root = new TrieNode();
//         for (const string& word : wordDict) {
//             TrieNode* currNode = root;
//             for (const char c : word) {
//                 if (currNode->children[c - 'a'] == nullptr) {
//                     currNode->children[c - 'a'] = new TrieNode(c);
//                 }
//                 currNode = currNode->children[c - 'a'];
//             }
//             currNode->isRoot = true;
//         }

//         queue<char> q;
//         for (const char c : s) q.push(c);
//         stack<char> workingStack;
//         TrieNode* currNode = root;
//         bool wasCurrPathUsed {false};
//         while (!q.empty()) {
//             const char c = q.front();
//             q.pop();
            
//             currNode = currNode->children[c - 'a'];
//             if (wasCurrPathUsed && currNode == nullptr) {
//                 while (!workingStack.empty()) {
//                     workingStack.push(workingStack.top()); workingStack.pop();
//                     wasCurrPathUsed
//                 }
//             } else if (currNode == nullptr) {
//                 return false;
//             }
            
//             workingStack.push(c);
//         }
//     }
// };
// @lc code=end

