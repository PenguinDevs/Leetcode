/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

#include <bits/stdc++.h>
using namespace std;


// @lc code=start
class Solution {
public:
    int reverse(int x) {
        if (x == numeric_limits<int>::min()) return 0;
        if (x == numeric_limits<int>::max()) return 0;

        const int digitsNo = ceil(log10(1 + abs(x)));
        static const int maxDigitsNo = ceil(log10(pow(2, 32)));

        int output {0};
        bool isMax = digitsNo == maxDigitsNo;
        for (int i {0}; i < digitsNo; ++i) {
            const int digit = extractDigit(x, i);

            if (isMax) {
                const int maxDigit = extractDigit(numeric_limits<int>::max(), digitsNo - 1 - i);
                // cout << maxDigit << " " << digit << endl;
                if (abs(digit) > maxDigit) {
                    return 0;
                } else if (abs(digit) < maxDigit) {
                    isMax = false;
                }
            }

            output += digit * pow(10, (digitsNo - 1 - i));
        }

        return output | (1 << 31 & x);
    }
private:
    int extractDigit(int n, int i) {
        static const int maxDigitsNo = ceil(log10(pow(2, 32)));
        if (i == maxDigitsNo - 1) {
            return (n - (n % static_cast<int>(pow(10, (i)))))/(static_cast<int>(pow(10, (i))));
        } else {
            return ((n % static_cast<int>(pow(10, (i + 1)))) - (n % static_cast<int>(pow(10, (i)))))/(static_cast<int>(pow(10, (i))));
        }
    }
};
// @lc code=end

