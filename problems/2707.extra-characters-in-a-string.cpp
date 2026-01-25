/*
 * @lc app=leetcode id=2707 lang=cpp
 *
 * [2707] Extra Characters in a String
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start

struct TrieNode {
    bool isWord;
    TrieNode* children[26];
};

class ReverseTrie {
public:
    TrieNode* rootNode;

    ReverseTrie() {
        rootNode = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* curNode = rootNode;
        for (int i = word.length() - 1; i >= 0; --i) {
            if (curNode->children[word[i] - 'a'] == nullptr) {
                curNode->children[word[i] - 'a'] = new TrieNode();
                curNode = curNode->children[word[i] - 'a'];
            } else {
                curNode = curNode->children[word[i] - 'a'];
            }
        }

        curNode->isWord = true;
    }
};

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        vector<int> dp(s.length() + 1);
        iota(dp.begin(), dp.end(), 0);

        ReverseTrie trie;
        for (const string word : dictionary) trie.addWord(word);

        for (int i {1}; i < s.length() + 1; ++i) {
            bool hasAssigned {false};

            int wordLen {0};
            TrieNode* curNode = trie.rootNode;
            for (int j {i - 1}; j >= 0; --j) {
                if (curNode->children[s[j] - 'a'] == nullptr) {
                    break;
                } else {
                    curNode = curNode->children[s[j] - 'a'];
                    ++wordLen;
                }

                if (curNode->isWord) {
                    dp[i] = min(
                        min(dp[i], dp[i - 1] + 1),
                        dp[i - wordLen]
                    );
                    hasAssigned = true;
                }
            }

            if (!hasAssigned) dp[i] = dp[i - 1] + 1;
        }

        // for (const int x : dp) cout << x << " ";

        return dp.back();
    }
};
// @lc code=end

