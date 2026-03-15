/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> sols;
        string currentSol;
        dfs(sols, n, currentSol);

        return sols;
    }
private:
    void dfs(
        vector<string>& sols,
        int n,
        string& currentSol,
        int openedBrackets = 0
    ) {
        if (n <= 0 && openedBrackets <= 0) {
            sols.push_back(currentSol);
            return;
        }

        if (openedBrackets > 0) {
            currentSol.push_back(')');
            dfs(sols, n, currentSol, openedBrackets - 1);
            currentSol.pop_back();
        }

        if (n > 0) {
            currentSol.push_back('(');
            dfs(sols, n - 1, currentSol, openedBrackets + 1);
            currentSol.pop_back();
        }
    }
};
// @lc code=end

