/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    string addBinary(string& a, string& b) {
        int i = static_cast<int>(a.size()) - 1;
        int j = static_cast<int>(b.size()) - 1;
        int carry = 0;
        string out;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) {
                sum += a[i] - '0';
                --i;
            }
            if (j >= 0) {
                sum += b[j] - '0';
                --j;
            }

            out.push_back(static_cast<char>('0' + (sum & 1)));
            carry = sum >> 1;
        }

        reverse(out.begin(), out.end());
        return out;
    }
};
// @lc code=end

