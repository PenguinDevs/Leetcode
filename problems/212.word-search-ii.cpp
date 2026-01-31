/*
 * @lc app=leetcode id=212 lang=cpp
 *
 * [212] Word Search II
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
struct TrieNode {
    TrieNode* children[26];
    int i {-1};
    int refs;
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    };

    void addWord(const string& word, const int wordIdx) {
        TrieNode* curr = root;

        for (int i {0}; i < word.length(); ++i) {
            ++curr->refs;
            const char c = word[i];
            if (curr->children[c - 'a'] == nullptr) {
                curr->children[c - 'a'] = new TrieNode();
            }

            curr = curr->children[c - 'a'];
        }

        curr->i = wordIdx;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        const int n = board.size();
        const int m = board[0].size();

        
        Trie trie;
        for (int i {0}; i < words.size(); ++i) {
            trie.addWord(words[i], i);
        }

        vector<string> sol;
        for (int i {0}; i < n; ++i) {
            for (int j {0}; j < m; ++j) {
                dfs(board, words, trie.root, sol, {i, j});
            }
        }

        return sol;
    }
private:
    int dfs(
        vector<vector<char>>& board,
        vector<string>& words,
        TrieNode* prevNode,
        vector<string>& sol,
        const pair<int, int> pos
    ) {
        static constexpr pair<int, int> directions[] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        const int n = board.size();
        const int m = board[0].size();

        const int c = board[pos.first][pos.second];
        
        TrieNode* currNode = prevNode->children[c - 'a'];
        if (currNode == nullptr) return 0;
        int refsDiff {0};
        if (currNode->i != -1) {
            sol.push_back(words[currNode->i]);
            refsDiff = -1;
            currNode->i = -1;
        }
        
        if (currNode->refs > 0) {
            board[pos.first][pos.second] = '*';
            for (const auto [dx, dy] : directions) {
                const int ni = pos.first + dx, nj = pos.second + dy;
                if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
                if (board[ni][nj] == '*') continue;
                refsDiff += dfs(board, words, currNode, sol, {ni, nj});
            }
            board[pos.first][pos.second] = c;
        }

        return refsDiff;
    }
};
// @lc code=end

