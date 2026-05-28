/*
 * @lc app=leetcode id=678 lang=cpp
 *
 * [678] Valid Parenthesis String
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool checkValidString(string s) {
        stack<int> parens;
        stack<int> asteriks;

        for (int i {0}; i < s.size(); ++i) {
            switch(s[i]) {
                case '*':
                    asteriks.push(i);
                    break;
                case '(':
                    parens.push(i);
                    break;
                case ')':
                    if (parens.empty()) {
                        if (!asteriks.empty()) {
                            asteriks.pop();
                        } else return false;
                    } else parens.pop();
                    break;
            }
        }

        while (!parens.empty()) {
            if (asteriks.empty()) return false;
            if (parens.top() > asteriks.top()) return false;
            parens.pop();
            asteriks.pop();
        }

        return true;
    }
};
// @lc code=end

