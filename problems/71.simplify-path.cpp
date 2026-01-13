/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> dir;
        
        string currentToken = "";
        path += '/';
        for (const char c : path) {
            if (c == '/') {
                if (currentToken == "") {
                    // Consecutive '/'
                } else if (currentToken == ".") {
                    // Don't do anything
                } else if (currentToken == "..") {
                    if (!dir.empty()) {
                        dir.pop();
                    }
                } else {
                    dir.push(currentToken);
                }
                
                currentToken = "";
            } else {
                currentToken += c;
            }
        }

        string output;
        while (!dir.empty()) {
            output = dir.top() + '/' + output;
            dir.pop();
        }

        if (output.length() > 0) output.pop_back();
        output = '/' + output;

        return output;
    }
};
// @lc code=end

