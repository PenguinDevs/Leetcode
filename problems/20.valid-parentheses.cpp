/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> brackets;
        for (int i {0}; i < s.size(); ++i) {
            const char c = s[i];
            if (c == '(' || c == '{' || c == '[') {
                brackets.push(c);
            } else {
                char reqOpening;
                switch (c) {
                    case ')':
                        reqOpening = '(';
                        break;
                    case '}':
                        reqOpening = '{';
                        break;
                    case ']':
                        reqOpening = '[';
                        break;
                }

                if (brackets.empty()) return false;
                if (brackets.top() == reqOpening) {
                    brackets.pop();
                } else {
                    return false;
                }
            }
        }

        return brackets.empty();
    }
};
// @lc code=end

