/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        vector<int> currentRow(p.size() + 1);
        vector<int> nextRow(p.size() + 1);

        currentRow[0] = 1;

        for (int s_i {0}; s_i < s.size(); ++s_i) {
            for (int p_i {0}; p_i < p.size(); ++p_i) {
                if (p_i + 1 < p.size() && p[p_i + 1] == '*') {
                    // cout << s[s_i] << " " << p[p_i] << endl;
                    if (isCharMatch(s[s_i], p[p_i])) {
                        // cout << "is match" << s_i << " " << p_i << endl;
                        // Appending letter
                        nextRow[p_i] += currentRow[p_i];
                    }

                    // Skipping letter
                    currentRow[p_i + 2] += currentRow[p_i];
                } else {
                    if (isCharMatch(s[s_i], p[p_i])) {
                        nextRow[p_i + 1] += currentRow[p_i];
                    }
                }
            }

            swap(currentRow, nextRow);
            fill(nextRow.begin(), nextRow.end(), 0);

            // for (int x : currentRow) {
            //     cout << x << " ";
            // }
            // cout << endl;
        }
        
        if (p.back() == '*') {
            int p_i = p.size() - 1;
            while (p_i > 0) {
                if (currentRow[p_i]) break;
                --p_i;
            }
    
            while (p_i < p.size()) {
                if (p_i + 1 < p.size() && p[p_i + 1] == '*') {
                    currentRow[p_i + 2] += currentRow[p_i];
                } else {
                    break;
                }
                ++++p_i;
            }
        }

        return currentRow[p.size()];
    }

    bool isCharMatch(char s, char p) {
        if (p == '.') {
            return true;
        } else {
            return s == p;
        }
    }
};

// enum class Modifier { many };
// enum class TokenType { charMatch, any };
// struct Token {
//     char charMatch;
//     TokenType tokenType;
//     unordered_set<Modifier> modifiers;
// };

// template <typename K, typename V>
// constexpr unordered_set<K> getModifierMapping(const unordered_map<K, V>& map) {
//     unordered_set<K> keys;
//     for (auto pair : map) {
//         keys.insert(pair.first);
//     }
    
//     return keys;
// };
// const unordered_map<char, Modifier> MODIFIER_MAP = {
//     {'*', Modifier::many}
// };
// const unordered_set<char> MODIFIER_KEYS = getModifierMapping(MODIFIER_MAP);

// class Solution {
// public:
//     bool isMatch(string s, string p) {
//         vector<Token> tokens;

//         int p_i {0};
//         while (p_i < p.size()) {
//             if (p[p_i] == '.') {
//                 if (tokens.size() > 0 && tokens.back().tokenType == TokenType::any) {
//                     ++p_i;

//                     if (p_i + 1 < p.size() && MODIFIER_KEYS.contains(p[p_i + 1])) {
//                         ++p_i;
//                     }
//                     continue;
//                 }
//             }

//             Token newToken;

//             switch (p[p_i]) {
//                 case '.':
//                     newToken.tokenType = TokenType::any;
//                     break;
//                 default:
//                     newToken.tokenType = TokenType::charMatch;
//                     newToken.charMatch = p[p_i];
//             }

//             while (p_i + 1 < p.size() && MODIFIER_KEYS.contains(p[p_i + 1])) {
//                 newToken.modifiers.insert(MODIFIER_MAP.at(p[p_i + 1]));
//                 ++p_i;
//             }

//             tokens.push_back(newToken);
//             ++p_i;
//         }

//         int s_i {0};
//         int t_i {0};
//         while (s_i < s.size()) {
//             cout << s_i << " " << t_i << endl;
//             if (t_i >= tokens.size()) {
//                 // Does not match the entire string
//                 cout << "does not match entire string" << endl;
//                 return false;
//             }

//             Token &currentToken = tokens[t_i];

//             if (currentToken.tokenType == TokenType::charMatch) {
//                 if (s[s_i] == currentToken.charMatch) {
//                     if (!currentToken.modifiers.contains(Modifier::many)) {
//                         // Don't keep the current token for next
//                         ++t_i;
//                         cout << "don't keep current token" << endl;
//                     }
//                 } else {
//                     // Expected char is missing
//                     // Could later add an optional modifier here
//                     if (currentToken.modifiers.contains(Modifier::many)) {
//                         // Was matching a char many times but then encountered new char
//                         ++t_i;
//                         cout << "encountered diff char after many, expect" << currentToken.charMatch << ", got" << s[s_i] << endl;
//                         continue;
//                     } else {
//                         return false;
//                     }
//                 }
//             } else if (currentToken.tokenType == TokenType::any) {
//                 if (currentToken.modifiers.contains(Modifier::many)) {
//                     if (t_i + 1 < tokens.size()) {
//                         if (s_i + 1 < s.size()) {
//                             if (s[s_i] == s[s_i + 1]) {
//                                 ++s_i;
//                                 cout << "next inner" << endl;
//                                 continue;
//                             }
//                         }

//                         Token &nextToken = tokens[t_i + 1];
//                         if (nextToken.tokenType == TokenType::charMatch && nextToken.charMatch == s[s_i]) {
//                             ++t_i;
//                             cout << "encountered char after .*" << endl;
//                             continue;
//                         } else if (s_i == s.size() - 1 && !currentToken.modifiers.contains(Modifier::many)) {
//                             cout << "did not find a non-many last char";
//                             return false;
//                         }
//                     }
//                 } else {
//                     ++t_i;
//                 }
//             }

//             ++s_i;
//             cout << "next" << endl;
//         }

//         cout << "exiting with " << s_i << " " << t_i << endl;
//         if (t_i < tokens.size() && !tokens.back().modifiers.contains(Modifier::many)) {
//             // Not all tokens were considered
//             cout << "not all tokens were considered" << endl;
//             return false;
//         }

//         return true;
//     }
// };
// @lc code=end

