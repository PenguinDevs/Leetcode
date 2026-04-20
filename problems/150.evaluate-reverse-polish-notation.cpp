/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
    set<string> OPERATORS {"+", "-", "*", "/"};
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;

        for (const string x : tokens) {
            if (OPERATORS.contains(x)) {
                const int n2 = s.top();
                s.pop();
                const int n1 = s.top();
                s.pop();

                if (x == "+") {
                    s.push(n1 + n2);
                } else if (x == "-") {
                    s.push(n1 - n2);
                } else if (x == "*") {
                    s.push(n1 * n2);
                } else if (x == "/") {
                    s.push(n1 / n2);
                }

                // cout << n1 << " and " << n2 << " gives " << s.top() << '\n';
            } else {
                s.push(stoi(x));
            }
        }

        return s.top();
    }
};
// @lc code=end

