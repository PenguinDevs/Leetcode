/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return 0;
        if (find(wordList.begin(), wordList.end(), beginWord) == wordList.end()) {
            wordList.push_back(beginWord);
        }

        unordered_map<string, int> wordToIdx;
        for (int i {0}; i < wordList.size(); ++i) {
            const string& word = wordList[i];
            wordToIdx[word] = i;
        }
        
        queue<pair<int, int>> q;
        q.push({wordToIdx[beginWord], 1});
        vector<bool> visited(wordList.size());
        visited[wordToIdx[beginWord]] = true;
        while (!q.empty()) {
            const auto [i, length] = q.front();
            q.pop();

            const string& word = wordList[i];

            for (int j {0}; j < word.size(); ++j) {
                char c = word[j];
                for (int d {0}; d < 26; ++d) {
                    string neighbour = word;
                    neighbour[j] = ((c - 'a') + d) % 26 + 'a';
                    if (wordToIdx.contains(neighbour)) {
                        const int k {wordToIdx[neighbour]};

                        if (visited[k]) continue;
                        visited[k] = true;

                        if (wordList[k] == endWord) return length + 1;

                        q.push({k, length + 1});
                    }
                }
            }
        }

        return 0;
    }
};
// @lc code=end

