/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        for (int i {0}; i < s.size(); ++i) {
            if (s[i] != ']') {
                st.push(s[i]);
            } else {
                string currStr;
                while (st.top() != '[') {
                    currStr = st.top() + currStr;
                    st.pop();
                }
                cout << currStr << '\n';

                st.pop(); // '['
                string number;
                while (!st.empty() && isdigit(st.top())) {
                    number = st.top() + number;
                    st.pop();
                }
                
                int repeat {stoi(number)};
                while (repeat--) {
                    for (int j {0}; j < currStr.size(); ++j) {
                        st.push(currStr[j]);
                    }
                }
            }
        }

        string out;
        while (!st.empty()) {
            out = st.top() + out;
            st.pop();
        }

        return out;
    }
};
// @lc code=end

