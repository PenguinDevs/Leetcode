/*
 * @lc app=leetcode id=953 lang=cpp
 *
 * [953] Verifying an Alien Dictionary
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> orderPriority(26);
        for (int i {0}; i < 26; ++i) {
            orderPriority[order[i] - 'a'] = i;
        }
        
        auto comp = [orderPriority](char a, char b) {
            return orderPriority[a - 'a'] <= orderPriority[b - 'a'];
        };
        
        string prevWord = words[0];
        for (int i {1}; i < words.size(); ++i) {
            bool wasExitedEarly {false};
            for (int j {0}; j < min(prevWord.size(), words[i].size()); ++j) {
                // cout << prevWord[j] << " " << words[i][j] << '\n';
                if (prevWord[j] == words[i][j]) continue;
                if (!comp(prevWord[j], words[i][j])) {
                    cout << "out";
                    return false;
                } else {
                    wasExitedEarly = true;
                    break;
                }
            }
            if (!wasExitedEarly) {
                if (prevWord.size() > words[i].size()) return false;
            }
            prevWord = words[i];
        }

        return true;
    }
};
// @lc code=end

