/*
 * @lc app=leetcode id=211 lang=cpp
 *
 * [211] Design Add and Search Words Data Structure
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class WordDictionary {
struct TrieNode {
    bool isLeaf;
    TrieNode* children[26];
};
private:
    TrieNode* root;
public:
    static constexpr int a_0 = 'a';

    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* prevNode {root};
        for (char c : word) {
            if (prevNode->children[c - a_0] == nullptr) {
                prevNode->children[c - a_0] = new TrieNode();
            }
            prevNode = prevNode->children[c - a_0];
        }

        prevNode->isLeaf = true;
    }
    
    bool search(string word) {
        stack<pair<int, TrieNode*>> searchStack;
        searchStack.push({0, root});

        while (!searchStack.empty()) {
            auto [i, node] = searchStack.top();
            searchStack.pop();
            if (i >= word.size()) continue;
            
            if (word[i] == '.') {
                for (int j {0}; j < 26; ++j) {
                    if (node->children[j] == nullptr) continue;
                    if (i == word.size() - 1 && node->children[j]->isLeaf) return true;
                    searchStack.push({i + 1, node->children[j]});
                }
            } else {
                int char_i = word[i] - a_0;
    
                if (node->children[char_i] == nullptr) continue;
                if (i == word.size() - 1 && node->children[char_i]->isLeaf) return true;
                searchStack.push({i + 1, node->children[char_i]});
            }
            
        }

        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end

