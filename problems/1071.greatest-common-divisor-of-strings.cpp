/*
 * @lc app=leetcode id=1071 lang=cpp
 *
 * [1071] Greatest Common Divisor of Strings
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        return (str1 + str2 == str2 + str1) ? str1.substr(0, gcd(str1.length(), str2.length())) : "";
    }
};
// @lc code=end

