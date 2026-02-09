/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    string intToRoman(int num) {
        string out;
        
        auto [subOut1, newNum1] = getRoman(num, 1000, 'M', 'D', 'C');
        out += subOut1;
        num = newNum1;
        auto [subOut2, newNum2] = getRoman(num, 100, 'C', 'L', 'X');
        out += subOut2;
        num = newNum2;
        auto [subOut3, newNum3] = getRoman(num, 10, 'X', 'V', 'I');
        out += subOut3;
        num = newNum3;

        out += string(num, 'I');

        return out;
    }
private:
    pair<string, int> getRoman(
        int num,
        const int size,
        char decSymbol,
        char pentSymbol,
        char lowerDecSymbol
    ) {
        string subOut;

        int decCount = num / size;
        if (decCount > 0) {
            num -= decCount * size;
            subOut += string(decCount, decSymbol);
        }

        int firstDigit = num / (size / 10);
        if (firstDigit == 9) {
            subOut += lowerDecSymbol;
            subOut += decSymbol;
            num -= 9 * size / 10;
        } else if (firstDigit == 4) {
            subOut += lowerDecSymbol;
            subOut += pentSymbol;
            num -= 4 * size / 10;
        } else if (firstDigit >= 5) {
            subOut += pentSymbol;
            num -= 5 * size / 10;
        }

        return {subOut, num};
    }
};
// @lc code=end

