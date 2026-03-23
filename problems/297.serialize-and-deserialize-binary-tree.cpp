/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
 */

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string out;
        
        serialiseRecursive(root, out);

        return out;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // cout << "converting " << data << '\n';
        reverse(data.begin(), data.end());
        return deserialiseRecursive(data);
    }
private:
    void serialiseRecursive(TreeNode* node, string& out) {
        if (node == nullptr) {
            out += "()";
            return;
        };

        out.push_back('(');
        out += to_string(node->val);

        serialiseRecursive(node->left, out);
        serialiseRecursive(node->right, out);

        out.push_back(')');
    }

    TreeNode* deserialiseRecursive(string& reversedInput) {
        if (reversedInput == "") return nullptr;
        if (reversedInput.back() == ')') return nullptr;
        reversedInput.pop_back(); // Pop the '('

        string numberString;
        while (
            !reversedInput.empty()
            && reversedInput.back() != ')'
            && reversedInput.back() != '('
        ) {
            numberString += reversedInput.back();
            reversedInput.pop_back();
        }
        if (numberString.empty()) {
            reversedInput.pop_back();
            return nullptr;
        }
        // cout << numberString << '\n';

        const int value = stoi(numberString);
        TreeNode* node = new TreeNode(value);

        // if (reversedInput.back() == '(') {
            // cout << "seeing " << reversedInput << '\n';
            node->left = deserialiseRecursive(reversedInput);
            node->right = deserialiseRecursive(reversedInput);
        // }

        reversedInput.pop_back(); // Pop the ')'

        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

