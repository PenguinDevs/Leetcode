/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 * 
 * NOTE: See Manacher's Algorithm
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    // int countSubstrings(string& s) {
    //     int count {0};

    //     for (int i = 0; i < s.length(); ++i) {
    //         for (int j = i + 1; j < s.length() + 1; ++j) {
    //             string subs = s.substr(i, j - i);

    //             if (isPalindrome(subs)) {
    //                 count++;
    //             }
    //         }
    //     }

    //     return count;
    // }
    int countSubstrings(string& s) {
        int count {0};

        for (int centerIdx = 0; centerIdx < s.length(); ++centerIdx) {
            // cout << centerIdx << ":" << s.length() - (centerIdx + 1) << endl;

            // Odd length palindrome check
            for (int offset = 0; offset <= min(centerIdx, (int)(s.length() - (centerIdx + 1))); ++offset) {
                // cout << centerIdx << " " << offset << endl;
                if (s[centerIdx - offset] == s[centerIdx + offset]) {
                    count++;
                } else {
                    break;
                }
            }

            // Even length palindrome check
            if (centerIdx < s.length() - 1) {
                for (int offset = 0; offset <= min(centerIdx, (int)(s.length() - (centerIdx + 2))); ++offset) {
                    if (s[centerIdx - offset] == s[centerIdx + 1 + offset]) {
                        count++;
                    } else {
                        break;
                    }   
                }
            }
        }

        return count;
    }
    // int countSubstrings(string& s) {
    //     int count {0};

    //     for (int centerIdx = 0; centerIdx < s.length(); ++centerIdx) {
    //         count += expandAroundCenter(s, centerIdx, centerIdx); // Odd palindrome
    //         count += expandAroundCenter(s, centerIdx, centerIdx + 1); // Even palindrome
    //     }

    //     return count;
    // }
    // int countSubstrings(string& s) {

    // }
// private:
// bool isPalindrome(string& s) {
//     for (int i = 0; i < (s.length() + 1) / 2; ++i) {
//         if (s[i] != s[s.length() - i - 1]) {
//             return false;
//         }
//     }

//     return true;
// }
    // int expandAroundCenter(string& s, int leftIdx, int rightIdx) {
    //     int count {0};
        
    //     int lowerBound = leftIdx;
    //     int upperBound = s.length() - (rightIdx + 1);

    //     for (int offset = 0; offset <= min(lowerBound, upperBound); ++offset) {
    //         if (s[leftIdx - offset] == s[rightIdx + offset]) {
    //             count++;
    //         } else {
    //             break;
    //         }
    //     }

    //     return count;
    // }
};
// @lc code=end

