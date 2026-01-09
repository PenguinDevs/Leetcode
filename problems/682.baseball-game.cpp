/*
 * @lc app=leetcode id=682 lang=cpp
 *
 * [682] Baseball Game
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> scores;
        for (const string o : operations) {
            if (o == "C") {
                if (!scores.empty()) scores.pop_back();
            } else if (o == "D") {
                if (scores.empty()) continue;
                scores.push_back(scores.back() * 2);
            } else if (o == "+") {
                scores.push_back(scores[scores.size() - 1] + scores[scores.size() - 2]);
            } else {
                scores.push_back(stoi(o));
            }
        }

        return accumulate(scores.begin(), scores.end(), 0);
    }
};
// @lc code=end

