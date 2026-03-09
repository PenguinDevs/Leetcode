/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        static vector<string> mapping = {
            " ",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
        };
        
        vector<string> out;
        string currentSol {};
        dfsConstruct(mapping, digits, out, currentSol);

        return out;
    }
private:
    void dfsConstruct(
        vector<string>& mapping,
        string& digits,
        vector<string>& out,
        string& currentSol,
        const int digitIdx = 0
    ) {
        if (digitIdx >= digits.size()) {
            out.push_back(currentSol);
            return;
        };

        const int digit = digits[digitIdx] - '0';
        for (const char c : mapping[digit]) {
            currentSol.push_back(c);
            dfsConstruct(mapping, digits, out, currentSol, digitIdx + 1);
            currentSol.pop_back();
        }
    }
};
// @lc code=end

