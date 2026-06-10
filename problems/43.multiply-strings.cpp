/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    string multiply(string& num1, string& num2) {
        vector<int> vectorisedOut(num1.size() + num2.size() + 1);

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        for (int i {0}; i < num2.size(); ++i) {
            for (int j {0}; j < num1.size(); ++j) {
                vectorisedOut[i + j] += (num2[i] - '0') * (num1[j] - '0');
                vectorisedOut[i + j + 1] += vectorisedOut[i + j] / 10;
                vectorisedOut[i + j] = vectorisedOut[i + j] % 10;
            }
        }

        string out;
        for (int i = vectorisedOut.size() - 1; i >= 0; --i) {
            if (out.empty() && vectorisedOut[i] == 0) continue;
            out.push_back(vectorisedOut[i] + '0');
        }

        return !out.empty() ? out : "0";
    }
};
// class Solution {
// public:
//     string multiply(string& num1, string& num2) {
//         string out;
//         reverse(num1.begin(), num1.end());
//         reverse(num2.begin(), num2.end());
//         for (int i {0}; i < num2.size(); ++i) {
//             string currVal = string(i, '0');
//             int carryOver {0};
//             for (int j {0}; j < num1.size(); ++j) {
//                 int prod {(num2[i] - '0') * (num1[j] - '0') + carryOver};
//                 int digit1 = prod / 10;
//                 int digit2 {prod % 10};
//                 // cout << "prod is " << prod << " between b" << num2[i] << " t" << num1[j] << '\n';
//                 currVal = string(1, digit2 + '0') + currVal;
//                 // cout << "currVal:" << currVal << '\n';
//                 carryOver = digit1;
//             }
//             // cout << "carry over " << carryOver << '\n';
//             currVal = string(1, carryOver + '0') + currVal;
//             // cout << "final currVal:" << currVal << '\n';
//             out = add(out, currVal);
//         }
        
//         return !out.empty() ? out : "0";
//     }
// private:
//     string add(string& num1, string& num2) {
//         string out;
        
//         reverse(num1.begin(), num1.end());
//         reverse(num2.begin(), num2.end());

//         // Enforce num1 > num2
//         if (num2.size() > num1.size()) swap(num1, num2);
//         // cout << num1 << "+" << num2 << "=\n";

//         int carryOver {0};
//         for (int i {0}; i < num1.size(); ++i) {
//             int addition {(num1[i] - '0') + (i < num2.size() ? num2[i] - '0' : 0) + carryOver};
//             int digit1 = addition / 10;
//             int digit2 {addition % 10};
//             // cout << digit1 << " " << digit2 << '\n';
//             out = string(1, digit2 + '0') + out;
//             carryOver = digit1;
//         }
//         out = string(1, carryOver + '0') + out;

//         // cout << "penult adding " << out << '\n';
//         const int n = out.size();
//         for (int i {0}; i < n; ++i) {
//             // cout << i << " " << out.size() << "I see " << out[0] << '\n';
//             if (out[0] == '0') {
//                 out = out.substr(1, out.size() - 1);
//             } else {
//                 break;
//             }
//         }

//         // cout << "final adding " << out << '\n';
//         return out;
//     }
// };
// @lc code=end

