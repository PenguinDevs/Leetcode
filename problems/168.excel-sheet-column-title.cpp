/*
 * @lc app=leetcode id=168 lang=cpp
 *
 * [168] Excel Sheet Column Title
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string out;
        while (columnNumber > 0) {
            int digit = columnNumber % 26;
            // cout << columnNumber << " " << digit << '\n';
            columnNumber /= 26;
            if (digit == 0) { // I don't understand why
                digit = 26;
                columnNumber -= 1;
            };
            out.push_back('A' + digit - 1);
        }

        reverse(out.begin(), out.end());
        return out;
    }
};
// @lc code=end

