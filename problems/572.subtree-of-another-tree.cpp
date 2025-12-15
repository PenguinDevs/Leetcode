/*
 * @lc app=leetcode id=572 lang=cpp
 *
 * [572] Subtree of Another Tree
 */

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr || subRoot == nullptr) return false;

        bool result = isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        if (result) return true;

        return isTreeMatch(root, subRoot);
    }
    bool isTreeMatch(TreeNode* root, TreeNode* comparison) {
        if (root == nullptr && comparison == nullptr) {
            return true;
        } if ((root == nullptr && comparison != nullptr) || (root != nullptr && comparison == nullptr)) {
            return false;
        }

        if (root->val == comparison->val) {
            return isTreeMatch(root->left, comparison->left) && isTreeMatch(root->right, comparison->right);
        } else {
            return false;
        }
    }
};
// @lc code=end

